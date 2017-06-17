#include <iostream>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <nanogui/nanogui.h>
#include <nanogui/glutil.h>
#include <GL/gl.h>
#include <VectorsOperations.h>
#include <MeshMatricesInitializer.h>
#include <GL/glu.h>

/*TODO
 * -Modificare vettori temporanei in vettori di Eigen::Vector3
 * -Implementare caricamento della colorazione
 * -Normali
 * -Illumninazione*/

using namespace nanogui;

class NanoguiMeshViewer : public nanogui::Screen {
public:

    NanoguiMeshViewer() : nanogui::Screen(Eigen::Vector2i(1000, 1000), "Nanogui Mesh Viewer") {
        using namespace nanogui;

        this->setBackground(Color(180,180,255,255));

        Window *window = new Window(this, "Tools");
        window->setPosition(Vector2i(0, 0));
        window->setLayout(new GroupLayout());
        /* Wireframe widget */ {
            new Label(window, "Wireframe :", "sans-bold");
            CheckBox *cb = new CheckBox(window, "Wireframe");
            cb->setChecked(wireframe);
            cb->setFontSize(16);
            cb->setCallback([this](bool state) {
                this->wireframe = state;
                this->shaderStateChange = true;
            });
        }
        {
            new Label(window, "Filled :", "sans-bold");
            CheckBox *filledCB = new CheckBox(window, "Filled");
            filledCB->setChecked(filled);
            filledCB->setFontSize(16);
            filledCB->setCallback([this](bool state) {
                this->filled = state;
                this->shaderStateChange=true;
                if(filled)
                    this->alphaWireframe = 1.0f;
                else
                    this->alphaWireframe = -1.0f;
            });
        }

        performLayout();

        //Caricamento del file
        meshMatricesInitializer(vertices, normals, faces, nFaces,minXValue,maxXValue,minYValue,maxYValue,minZValue, maxZValue, minValue, maxValue, maxDistance);

        refreshArcball();

        vertexShaderFilePath = "./resources/vertexShader.vert";
        fragmentShaderFilePath = "./resources/fragmentShader.frag";
        mShader.initFromFiles("Nanogui Shader", vertexShaderFilePath.c_str(), fragmentShaderFilePath.c_str());

        mShader.bind();
        mShader.uploadAttrib("normals", normals);
        mShader.setUniform("lightPosition_worldspace", lightPosition);
        mShader.uploadIndices(faces);
        mShader.uploadAttrib("vertices", vertices);
    }

    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers) {
        if (Screen::keyboardEvent(key, scancode, action, modifiers))
            return true;
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            setVisible(false);
            return true;
        }
        return false;
    }

    bool mouseButtonEvent(const Vector2i &p, int button, bool down, int modifiers){
        if(!Screen::mouseButtonEvent(p, button, down, modifiers)){
            if(button == GLFW_MOUSE_BUTTON_1 && modifiers == 0){ // Rotazione
                nanoguiCamera.arcball.button(p, down);
            } else if (button == GLFW_MOUSE_BUTTON_2 ||
                       (button == GLFW_MOUSE_BUTTON_1 && modifiers == GLFW_MOD_SHIFT)) {
                nanoguiCamera.translationStart = nanoguiCamera.translation;
                isTranslating = true;
                screenTranslationStart = p;
            }  //Traslazione
        }
        if(button == GLFW_MOUSE_BUTTON_1 && !down){ //Interrompo il tracking per la rotazione
            nanoguiCamera.arcball.button(p,false);
        }
        if (!down) {
            isTranslating = false;
        }
        return true;
    }

    bool mouseMotionEvent(const Vector2i &p, const Vector2i &rel, int button, int modifiers){
        if(!Screen::mouseMotionEvent(p, rel, button, modifiers)){
            if(nanoguiCamera.arcball.motion(p)){         //Passo informazioni sulla posizione del mouse alla trackball
                //
            }else if (isTranslating) {
                Vector3f delta(p.x()-screenTranslationStart.x(), -(p.y()-screenTranslationStart.y()),0);
                delta /= mSize.x()/2;
                nanoguiCamera.translation = nanoguiCamera.translationStart + delta;
            }
        }
        return true;
    }

    bool scrollEvent(const Vector2i &p, const Vector2f &rel) {
        if (!Screen::scrollEvent(p, rel)) {
            nanoguiCamera.zoom = std::max(0.1, nanoguiCamera.zoom * (rel.y() > 0 ? 1.1 : 0.9));
        }
        return true;
    }

    // Draw the widget (and all child widgets)
    virtual void draw(NVGcontext *ctx) {
        /* Draw the user interface */
        Screen::draw(ctx);
    }

    float getScaleFactor(){
        return 1/(maxDistance);
    }

    Vector3f getTranslationToCenter() {
        return Vector3f(-(minXValue+maxXValue)/2,-(minYValue+maxYValue)/2,-(minZValue+maxZValue)/2);
    }

    Vector3f getMeshCenter() {
        return Vector3f((minXValue+maxXValue)/2,(minYValue+maxYValue)/2,(minZValue+maxZValue)/2);
    }

    virtual void drawContents(){
        using namespace nanogui;
//        glEnable(GL_DEPTH_TEST) ->  Enable depth test
//        glDepthFunc(GL_LESS) -> Accept fragment if it closer to the camera than the former one
//        glEnable(GL_CULL_FACE) -> Cull triangles which normal is not towards the camera

        if(!filled && wireframe){
            glDisable(GL_DEPTH_TEST);
            glDisable(GL_CULL_FACE);
            shaderStateChange = true;
        }
        else if(filled && wireframe){
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);
            glEnable(GL_CULL_FACE);
            shaderStateChange = true;
        }
        else{
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);
            glEnable(GL_CULL_FACE);
            shaderStateChange = true;
        }

        /* Draw the window contents using OpenGL */
        mShader.bind();

        //Aggiorno la grandezza dello schermo fornita alla arcball
        nanoguiCamera.arcball.setSize(mSize);

        Matrix4f modelView, viewportMatrix, normalMatrix;
        model.setIdentity();
        view.setIdentity();
        proj.setIdentity();
        modelView.setIdentity();

        calculateMVPMatrices(model, view, proj);

        modelView = view * model;

        viewportMatrix <<
                        width()/2,0.0,0.0,0.0,
                        0.0,height()/2,0.0,0.0,
                        0.0,0.0,1.0,0.0,
                        width()/2, height()/2, 0.0, 1.0;

        normalMatrix = modelView.inverse();
        normalMatrix.transposeInPlace();


        //Caricamento shaders
        if(shaderStateChange && wireframe){
            shaderStateChange = false;
            mShader.free();
            vertexShaderFilePath = "./resources/vertexWireframe.vert";
            fragmentShaderFilePath = "./resources/fragmentWireframe.frag";
            geometryShaderFilePath = "./resources/geometryWireframe.geom";
            mShader.initFromFiles("Nanogui Shader", vertexShaderFilePath.c_str(), fragmentShaderFilePath.c_str(), geometryShaderFilePath.c_str());
            mShader.bind();
            mShader.uploadIndices(faces);
            mShader.uploadAttrib("VertexPosition", vertices);
            mShader.uploadAttrib("VertexNormal", normals);
//            mShader.setUniform("NormalMatrix", normalMatrix);
//            mShader.setUniform("ModelViewMatrix", modelView);
            mShader.setUniform("ViewportMatrix", viewportMatrix);

            mShader.setUniform("filled", alphaWireframe);

            mShader.setUniform("Line.Width", 0.5f);
            mShader.setUniform("Line.Color", Vector4f(0.0f,0.0f,0.0f,1.0f));
            mShader.setUniform("Material.Kd", Vector3f(0.4f, 0.4f, 0.4f));
//            mShader.setUniform("Light.Position", Vector4f(0.0f,0.0f,0.0f, 1.0f));
//            mShader.setUniform("Material.Ka", Vector3f(0.2f, 0.2f, 0.2f));
//            mShader.setUniform("Light.Intensity", Vector3f(1.0f, 1.0f, 1.0f));
//            mShader.setUniform("Material.Ks", Vector3f(0.8f, 0.8f, 0.8f));
//            mShader.setUniform("Material.Shininess", 100.0f);
        }
        if(shaderStateChange && !wireframe){
            shaderStateChange = false;
            mShader.free();
            vertexShaderFilePath = "./resources/vertexShader.vert";
            fragmentShaderFilePath = "./resources/fragmentShader.frag";
            mShader.initFromFiles("Nanogui Shader", vertexShaderFilePath.c_str(), fragmentShaderFilePath.c_str());
            mShader.bind();
            mShader.uploadAttrib("normals", normals);
            mShader.setUniform("color", Vector4f(0.5,0.5,0.5,1.0));
            mShader.setUniform("lightPosition_worldspace", lightPosition);
            mShader.uploadIndices(faces);
            mShader.uploadAttrib("vertices", vertices);
        }

        mShader.setUniform("model", model);
        mShader.setUniform("proj", proj);
        mShader.setUniform("view", view);

        /* Draw nFaces triangles starting at index 0 */
        mShader.drawIndexed(GL_TRIANGLES, 0, nFaces);
    }

    void calculateMVPMatrices(Matrix4f &model, Matrix4f &view, Matrix4f &proj){
        Vector3f translateVector= getTranslationToCenter() + Vector3f(tarx,tary,tarz);

        float scaleFactor = getScaleFactor();
        float near = nanoguiCamera.camera_dnear;
        float far = nanoguiCamera.camera_dfar;
        float top = tan((nanoguiCamera.cameraViewAngle)/360.*M_PI)*near;
        float right = top * width()/height();

        proj = frustum(-right,right,-top,top,near,far);

        view = lookAt(nanoguiCamera.camPos-nanoguiCamera.translation, nanoguiCamera.camTar-nanoguiCamera.translation, nanoguiCamera.camUp);

        //Uso funzioni Eigen per traslazione e scalatura per evitare il segmentation fault descritto sotto
        Eigen::Affine3f translation(Eigen::Translation3f(getTranslationToCenter()[0],getTranslationToCenter()[1],getTranslationToCenter()[2]));
        Eigen::Affine3f scale(Eigen::Scaling(scaleFactor*nanoguiCamera.zoom));

        model = nanoguiCamera.arcball.matrix();
        model *= scale.matrix();
        model *= translation.matrix();

        /*TODO Perchè la combinazione (translateNanogui||scaleNanogui)&&arcball.matrix causa segmentation fault prima in scale e poi in translate???? (senza arcball funzione)*/
        //model= translate(translateVector) * scale(Vector3f(scaleFactor*nanoguiCamera.zoom,scaleFactor*nanoguiCamera.zoom,scaleFactor*nanoguiCamera.zoom));
    }

    void refreshArcball(){
        Vector3f mesh_center = getMeshCenter();
        nanoguiCamera.arcball = Arcball();
        nanoguiCamera.arcball.setSize(mSize);           //Assegno la dimensione del monitor
        nanoguiCamera.modelZoom = getScaleFactor();
    }

private:
    struct NanoguiCamera{
        int cameraViewAngle = 45;
        float zoom = 1.0;
        float modelZoom = 1.0;
        float camera_dnear = 0.1;
        float camera_dfar = 100;
        Vector3f camPos = {0, 0, 1.5};
        Vector3f camTar = {0, 0, 0};
        Vector3f camUp = {0, 1, 0};
        Arcball arcball;                                        //Per la gestione della vista tramite mouse
        Vector3f translation = Vector3f::Zero();                //Per la traslazione su schermo
        Vector3f translationStart = Vector3f::Zero();
    };
    nanogui::GLShader mShader;
    /*Numero di triangoli caricati dal file*/
    uint32_t nFaces;

    std::string vertexShaderFilePath, fragmentShaderFilePath,geometryShaderFilePath="";

    bool wireframe= false, shaderStateChange=false, filled= true;
    bool isTranslating = false;

    //Matrice di vertici
    Eigen::MatrixXd vertices;
    Eigen::MatrixXd normals;
    Eigen::MatrixXi faces;

    //Matrici per MVP
    Matrix4f  model, view, proj;

    //Vettore per la gestione della traslazione col mouse
    Vector2i screenTranslationStart = Vector2i(0, 0);

    //Luce
    Eigen::Vector3d lightPosition= {4.0,4.0,4.0};

    /* Variabili per il calcolo della traslazione */
    double minXValue, maxXValue, minYValue, maxYValue, minZValue, maxZValue, maxValue, minValue, maxDistance;

    float alphaWireframe;
    NanoguiCamera nanoguiCamera;
    float tarx = 0, tary = 0, tarz = 0;
};

int main(int /* argc */, char ** /* argv */) {
    try {
        nanogui::init();
        {
            nanogui::ref<NanoguiMeshViewer> app = new NanoguiMeshViewer();
            app->drawAll();
            app->setVisible(true);

            nanogui::mainloop();
        }

        nanogui::shutdown();

    } catch (const std::runtime_error &e) {
        std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
#if defined(_WIN32)
        MessageBoxA(nullptr, error_msg.c_str(), NULL, MB_ICONERROR | MB_OK);
#else
        std::cerr << error_msg << std::endl;
#endif
        return -1;
    }

    return 0;
}