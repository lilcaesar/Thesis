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

        Window *meshTools = new Window(this, "Mesh Tools");
        meshTools->setPosition(Vector2i(0, 0));
        meshTools->setLayout(new GroupLayout());

        Button *loadMeshButton = new Button(meshTools, "Load Mesh");
        loadMeshButton->setCallback([this](){
            //Caricamento del file
            meshMatricesInitializer(vertices, normals, faces, nFaces,nVertices,minXValue,maxXValue,minYValue,maxYValue,minZValue, maxZValue, minValue, maxValue, maxDistance);

            refreshArcball();

            nanoguiCamera.modelZoom = 1.0;
            nanoguiCamera.translation = nanoguiCamera.translationStart = Vector3f::Zero();

            vertexShaderFilePath = "./resources/vertexShader.vert";
            fragmentShaderFilePath = "./resources/fragmentShader.frag";
            mShader.initFromFiles("Nanogui Shader", vertexShaderFilePath.c_str(), fragmentShaderFilePath.c_str());

            mShader.bind();
            mShader.uploadAttrib("normals", normals);
            mShader.setUniform("lightPosition_worldspace", lightPosition);
            mShader.uploadIndices(faces);
            mShader.uploadAttrib("vertices", vertices);
        });

        PopupButton *popupBtn = new PopupButton(meshTools, "Shading Styles");
        Popup *popup = popupBtn->popup();
        popup->setLayout(new GroupLayout());
        popup->setTooltip("Select type of shading for the mesh");

        /* Wireframe widget */ {
            new Label(popup, "Wireframe :", "sans-bold");
            CheckBox *wireframeCB = new CheckBox(popup, "Wireframe");
            wireframeCB->setChecked(wireframe);
            wireframeCB->setFontSize(16);
            wireframeCB->setCallback([this](bool state) {
                this->wireframe = state;
                this->shaderStateChange = true;
            });
            wireframeCB->setTooltip("Toggle wireframe shading on the mesh");
        }
        {
            new Label(popup, "Flat Coloration :", "sans-bold");
            CheckBox *flatCB = new CheckBox(popup, "Flat");
            flatCB->setChecked(flat);
            flatCB->setFontSize(16);
            flatCB->setCallback([this](bool state) {
                this->flat = state;
                this->shaderStateChange=true;
                if(flat)
                    this->flatColoration = 1.0f;
                else
                    this->flatColoration = -1.0f;
            });
            flatCB->setTooltip("Toggle flat coloration on the inner area of the triangles during filled wireframe shading");
        }
        {
            new Label(popup, "Filled :", "sans-bold");
            CheckBox *filledCB = new CheckBox(popup, "Filled");
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
            filledCB->setTooltip("Toggle filled version of wireframe shading");
        }

        popupBtn = new PopupButton(meshTools, "Colors");
        popup = popupBtn->popup();
        popup->setLayout(new GroupLayout());
        popup->setTooltip("Color settings for mesh and background");

        new Label(popup, "Background color");
        colorwheelBG = new ColorWheel(popup);
        colorwheelBG->setColor(this->background());
        colorwheelBG->setCallback([this](Color state){
            this->setBackground(state);
        });

        Widget *tools = new Widget(popup);
        tools->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 6));
        new Label(tools, "R:");
        rValueBG = new IntBox<int>(tools);
        rValueBG->setValue(this->background().r()*255);
        rValueBG->setEditable(true);
        rValueBG->setMinMaxValues(0,255);
        rValueBG->setCallback([this](int state){
            Color c = this->background();
            int c1,c2,c3;
            c1 = c[1]*255;
            c2 = c[2]*255;
            c3 = c[3]*255;
            this->setBackground(Color(state,c1,c2,c3));
        });
        new Label(tools, "G:");
        gValueBG = new IntBox<int>(tools);
        gValueBG->setValue(this->background().g()*255);
        gValueBG->setEditable(true);
        gValueBG->setMinMaxValues(0,255);
        gValueBG->setCallback([this](int state){
            Color c = this->background();
            int c1,c2,c3;
            c1 = c[0]*255;
            c2 = c[2]*255;
            c3 = c[3]*255;
            this->setBackground(Color(c1,state,c2,c3));
        });
        new Label(tools, "B:");
        bValueBG = new IntBox<int>(tools);
        bValueBG->setValue(this->background().b()*255);
        bValueBG->setEditable(true);
        bValueBG->setMinMaxValues(0,255);
        bValueBG->setCallback([this](int state){
            Color c = this->background();
            int c1,c2,c3;
            c1 = c[0]*255;
            c2 = c[1]*255;
            c3 = c[3]*255;
            this->setBackground(Color(c1,c2,state,c3));
        });

        new Label(popup, "Mesh color");
        colorWheelMesh = new ColorWheel(popup);
        colorWheelMesh->setColor(this->meshColor);
        colorWheelMesh->setCallback([this](Color state){
            this->meshColor = state;
        });

        tools = new Widget(popup);
        tools->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 6));
        new Label(tools, "R:");
        rValueMesh = new IntBox<int>(tools);
        rValueMesh->setValue(this->meshColor[0]*255);
        rValueMesh->setEditable(true);
        rValueMesh->setMinMaxValues(0,255);
        rValueMesh->setCallback([this](int state){
            Color c = this->meshColor;
            int c1,c2,c3;
            c1 = c[1]*255;
            c2 = c[2]*255;
            c3 = c[3]*255;
            this->meshColor= Color(state,c1,c2,c3);
        });
        new Label(tools, "G:");
        gValueMesh = new IntBox<int>(tools);
        gValueMesh->setValue(this->meshColor[1]*255);
        gValueMesh->setEditable(true);
        gValueMesh->setMinMaxValues(0,255);
        gValueMesh->setCallback([this](int state){
            Color c = this->meshColor;
            int c1,c2,c3;
            c1 = c[0]*255;
            c2 = c[2]*255;
            c3 = c[3]*255;
            this->meshColor= Color(c1,state,c2,c3);
        });
        new Label(tools, "B:");
        bValueMesh = new IntBox<int>(tools);
        bValueMesh->setValue(this->meshColor[2]*255);
        bValueMesh->setEditable(true);
        bValueMesh->setMinMaxValues(0,255);
        bValueMesh->setCallback([this](int state){
            Color c = this->meshColor;
            int c1,c2,c3;
            c1 = c[0]*255;
            c2 = c[1]*255;
            c3 = c[3]*255;
            this->meshColor= Color(c1,c2,state,c3);
        });


        new Label(popup, "Wireframe color");
        colorWheelWF = new ColorWheel(popup);
        colorWheelWF->setColor(this->wireframeColor);
        colorWheelWF->setCallback([this](Color state){
            this->wireframeColor=state;
        });

        tools = new Widget(popup);
        tools->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 6));
        new Label(tools, "R:");
        rValueWF = new IntBox<int>(tools);
        rValueWF->setValue(this->wireframeColor[0]*255);
        rValueWF->setEditable(true);
        rValueWF->setMinMaxValues(0,255);
        rValueWF->setCallback([this](int state){
            Color c = this->wireframeColor;
            int c1,c2,c3;
            c1 = c[1]*255;
            c2 = c[2]*255;
            c3 = c[3]*255;
            this->wireframeColor= Color(state,c1,c2,c3);
        });
        new Label(tools, "G:");
        gValueWF = new IntBox<int>(tools);
        gValueWF->setValue(this->wireframeColor[1]*255);
        gValueWF->setEditable(true);
        gValueWF->setMinMaxValues(0,255);
        gValueWF->setCallback([this](int state){
            Color c = this->wireframeColor;
            int c1,c2,c3;
            c1 = c[0]*255;
            c2 = c[2]*255;
            c3 = c[3]*255;
            this->wireframeColor= Color(c1,state,c2,c3);
        });
        new Label(tools, "B:");
        bValueWF = new IntBox<int>(tools);
        bValueWF->setValue(this->wireframeColor[2]*255);
        bValueWF->setEditable(true);
        bValueWF->setMinMaxValues(0,255);
        bValueWF->setCallback([this](int state){
            Color c = this->wireframeColor;
            int c1,c2,c3;
            c1 = c[0]*255;
            c2 = c[1]*255;
            c3 = c[3]*255;
            this->wireframeColor= Color(c1,c2,state,c3);
        });
        new Label(popup, "Line thickness:");
        FloatBox<float> *wireframeLineFloatBox = new FloatBox<float>(popup);
        wireframeLineFloatBox->setValue(this->wireframeLineThickness);
        wireframeLineFloatBox->setEditable(true);
        wireframeLineFloatBox->setSpinnable(true);
        wireframeLineFloatBox->setMinMaxValues(0,10);
        wireframeLineFloatBox->setCallback([this](float state){
            this->wireframeLineThickness= state;
        });

        popupBtn = new PopupButton(meshTools, "Camera settings");
        popup = popupBtn->popup();
        popup->setLayout(new GroupLayout());
        popup->setTooltip("Tools for the camera");
        {
            new Label(popup, "Perspective View :", "sans-bold");
            CheckBox *perspectiveCB = new CheckBox(popup, "Perspective");
            perspectiveCB->setChecked(perspective);
            perspectiveCB->setFontSize(16);
            perspectiveCB->setCallback([this](bool state) {
                this->perspective = state;
            });
            perspectiveCB->setTooltip("Toggle perspective view for the canvas");
        }

        Button *help = new Button(meshTools, "Help");
        help->setCallback([&] {
            auto dlg = new MessageDialog(this, MessageDialog::Type::Information, "Starting informations", "This is an information message");
            dlg->setCallback([](int result) { cout << "Dialog result: " << result << endl; });
        });
        auto dlg = new MessageDialog(this, MessageDialog::Type::Information, "Starting informations", "This is an information message");

        ///INFORMATION BAR

        Window *informationBar = new Window(this, "Informations");
        informationBar->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 6));
        informationBar->setPosition(Vector2i(177,0));

        new Label(informationBar, "Vertices:", "sans-bold");
        nVerticesIntBox = new IntBox<int>(informationBar);
        nVerticesIntBox->setValue(nVertices);
        new Label(informationBar, "Faces:", "sans-bold");
        nFacesIntBox = new IntBox<int>(informationBar);
        nFacesIntBox->setValue(nFaces);
        new Label(informationBar, "Field of view:", "sans-bold");
        FOVIntBox = new IntBox<int>(informationBar);
        FOVIntBox->setValue(nanoguiCamera.cameraViewAngle);

        performLayout();
    }

    void refreshGUIElements(){
        colorwheelBG->setColor(background());
        rValueBG->setValue(background().r()*255);
        gValueBG->setValue(background().g()*255);
        bValueBG->setValue(background().b()*255);

        colorWheelMesh->setColor(meshColor);
        rValueMesh->setValue(meshColor[0]*255);
        gValueMesh->setValue(meshColor[1]*255);
        bValueMesh->setValue(meshColor[2]*255);

        colorWheelWF->setColor(wireframeColor);
        rValueWF->setValue(wireframeColor[0]*255);
        gValueWF->setValue(wireframeColor[1]*255);
        bValueWF->setValue(wireframeColor[2]*255);

        nVerticesIntBox->setValue(nVertices);
        nFacesIntBox->setValue(nFaces);
        FOVIntBox->setValue(nanoguiCamera.cameraViewAngle);
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
            if(button == GLFW_MOUSE_BUTTON_MIDDLE && modifiers == 0){
                lightArcball.button(p,down);
            }else if(button == GLFW_MOUSE_BUTTON_1 && modifiers == 0){ // Rotazione mesh
                nanoguiCamera.arcball.button(p, down);
            } else if (button == GLFW_MOUSE_BUTTON_2 ||
                       (button == GLFW_MOUSE_BUTTON_1 && modifiers == GLFW_MOD_SHIFT)) {
                nanoguiCamera.translationStart = nanoguiCamera.translation;
                isTranslating = true;
                screenTranslationStart = p;
            }  //Traslazione
        }
        if(button == GLFW_MOUSE_BUTTON_1 && !down){ //Interrompo il tracking per la rotazione della mesh
            nanoguiCamera.arcball.button(p,false);
        }
        if(button == GLFW_MOUSE_BUTTON_MIDDLE && !down){ //Interrompo il tracking per la rotazione della luce
            lightArcball.button(p,false);
        }
        if (!down) {
            isTranslating = false;
        }
        return true;
    }

    bool mouseMotionEvent(const Vector2i &p, const Vector2i &rel, int button, int modifiers){
        if(!Screen::mouseMotionEvent(p, rel, button, modifiers)){
            if(nanoguiCamera.arcball.motion(p) || lightArcball.motion(p)){         //Passo informazioni sulla posizione del mouse alla trackball
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
        //Azzero le variabili visibili nelle info che devono essere ancora inizializzate
        if(start){
            wireframeColor= Color(0,0,0,255);
            nFaces=0;
            nVertices=0;
            start=false;
        }
        refreshGUIElements();
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

        //Aggiorno la grandezza dello schermo fornita alle arcball
        nanoguiCamera.arcball.setSize(mSize);
        lightArcball.setSize(mSize);

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

        Vector3f lightPositionVector = lightArcball.matrix().block<3,3>(0,0) * lightPosition;


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
            mShader.setUniform("ViewportMatrix", viewportMatrix);

            mShader.setUniform("filled", alphaWireframe);
            mShader.setUniform("flatColor", flatColoration);

            mShader.setUniform("Line.Width", wireframeLineThickness);
            mShader.setUniform("Line.Color", Vector4f(wireframeColor));
            mShader.setUniform("Material.Kd", Vector4f(meshColor));
        }
        if(shaderStateChange && !wireframe){
            shaderStateChange = false;
            mShader.free();
            vertexShaderFilePath = "./resources/vertexShader.vert";
            fragmentShaderFilePath = "./resources/fragmentShader.frag";
            mShader.initFromFiles("Nanogui Shader", vertexShaderFilePath.c_str(), fragmentShaderFilePath.c_str());
            mShader.bind();
            mShader.uploadAttrib("normals", normals);
            mShader.setUniform("color", Vector4f(meshColor));
            mShader.setUniform("lightPosition_worldspace", lightPositionVector);
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

        if(perspective){
            proj = frustum(-right,right,-top,top,near,far);}
        else{
            proj = ortho(-right*14,right*14,-top*14,top*14,near,far);}

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
        lightArcball = Arcball();
        nanoguiCamera.arcball.setSize(mSize);           //Assegno la dimensione del monitor
        lightArcball.setSize(mSize);
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

    Arcball lightArcball;

    /*Numero di triangoli caricati dal file*/
    //Forzo la gui ad assegnare il numero corretto di spazi per le informazioni della mesh
    uint32_t nFaces=10000000;
    uint32_t nVertices=10000000;

    std::string vertexShaderFilePath, fragmentShaderFilePath,geometryShaderFilePath="";

    bool wireframe= false, shaderStateChange=false, filled= true, flat = false, perspective = true;
    bool isTranslating = false;
    bool start = true;

    //Matrice di vertici
    Eigen::MatrixXd vertices;
    Eigen::MatrixXd normals;
    Eigen::MatrixXi faces;

    //Matrici per MVP
    Matrix4f  model, view, proj;

    //Vettore per la gestione della traslazione col mouse
    Vector2i screenTranslationStart = Vector2i(0, 0);

    //Luce
    Eigen::Vector3f lightPosition= {4.0,4.0,4.0};

    /* Variabili per il calcolo della traslazione */
    double minXValue, maxXValue, minYValue, maxYValue, minZValue, maxZValue, maxValue, minValue, maxDistance;

    float alphaWireframe;
    float flatColoration=-1.0;
    NanoguiCamera nanoguiCamera;
    float tarx = 0, tary = 0, tarz = 0;

    float wireframeLineThickness = 0.5f;

    Color meshColor = {128,128,128,255};
    Color wireframeColor = {255,255,255,255};

    //GUI elements that must be refreshed every frame
    IntBox<int> *nVerticesIntBox, *nFacesIntBox, *FOVIntBox;
    IntBox<int> *rValueMesh, *gValueMesh, *bValueMesh;
    IntBox<int> *rValueBG, *gValueBG, *bValueBG;
    IntBox<int> *rValueWF, *gValueWF, *bValueWF;
    ColorWheel *colorwheelBG, *colorWheelMesh, *colorWheelWF;
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