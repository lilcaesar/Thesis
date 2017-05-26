#include <iostream>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <nanogui/nanogui.h>
#include <nanogui/glutil.h>
#include <GL/gl.h>
#include <importFiles.h>
#include <VectorsOperations.h>
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

        Window *window = new Window(this, "Frustum tools");
        window->setPosition(Vector2i(850, 0));
        window->setLayout(new GroupLayout());

        new Label(window, "Field of view", "sans-bold");
        Widget *frustumTools = new Widget(window);
        frustumTools->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 5));
        {
            new Label(window, "Field of view:", "sans");
            auto fovFloatBox = new FloatBox<float>(window);
            fovFloatBox->setFixedSize(Vector2i(100, 20));
            fovFloatBox->setValue(cameraViewAngle);
            fovFloatBox->setFontSize(16);
            fovFloatBox->setMinMaxValues(30, 90);
            fovFloatBox->setValueIncrement(1);
            fovFloatBox->setEditable(true);
            fovFloatBox->setSpinnable(true);
            fovFloatBox->setCallback([this](float fieldOfView) {
                this->cameraViewAngle = fieldOfView;
            });
        }
        {
            new Label(window, "Near plane:", "sans");
            auto nearPlaneFloatBox = new FloatBox<float>(window);
            nearPlaneFloatBox->setFixedSize(Vector2i(100, 20));
            nearPlaneFloatBox->setValue(camera_dnear);
            nearPlaneFloatBox->setFontSize(16);
            nearPlaneFloatBox->setMinMaxValues(0.1, 20);
            nearPlaneFloatBox->setValueIncrement(0.1);
            nearPlaneFloatBox->setEditable(true);
            nearPlaneFloatBox->setSpinnable(true);
            nearPlaneFloatBox->setCallback([this](float nearPlane) {
                this->camera_dnear = nearPlane;
            });
        }
        {
            new Label(window, "Far plane:", "sans");
            auto farPlaneFloatBox = new FloatBox<float>(window);
            farPlaneFloatBox->setFixedSize(Vector2i(100, 20));
            farPlaneFloatBox->setValue(camera_dfar);
            farPlaneFloatBox->setFontSize(16);
            farPlaneFloatBox->setMinMaxValues(1, 100);
            farPlaneFloatBox->setValueIncrement(1);
            farPlaneFloatBox->setEditable(true);
            farPlaneFloatBox->setSpinnable(true);
            farPlaneFloatBox->setCallback([this](float farPlane) {
                this->camera_dfar = farPlane;
            });
        }
        {
            new Label(window, "Camera zoom:", "sans");
            auto cameraZoomFloatBox = new FloatBox<float>(window);
            cameraZoomFloatBox->setFixedSize(Vector2i(100, 20));
            cameraZoomFloatBox->setValue(camera_zoom);
            cameraZoomFloatBox->setFontSize(16);
            cameraZoomFloatBox->setMinValue(0);
            cameraZoomFloatBox->setValueIncrement(camera_zoom/10);
            cameraZoomFloatBox->setEditable(true);
            cameraZoomFloatBox->setSpinnable(true);
            cameraZoomFloatBox->setCallback([this](float cZoom) {
                this->camera_zoom = cZoom;
            });
        }

        new Label(window, "Camera Translation", "sans-bold");
        Widget *cameraTranslationTools = new Widget(window);
        cameraTranslationTools->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 5));

        {
            new Label(window, "Translate cam x:", "sans");
            auto scaleFloatBox = new FloatBox<float>(window);
            scaleFloatBox->setFixedSize(Vector2i(100, 20));
            scaleFloatBox->setValue(camx);
            scaleFloatBox->setFontSize(16);
            scaleFloatBox->setValueIncrement(0.1);
            scaleFloatBox->setEditable(true);
            scaleFloatBox->setSpinnable(true);
            scaleFloatBox->setCallback([this](float translationValue) {
                this->camx = translationValue;
            });
        }
        {
            new Label(window, "Translate cam y:", "sans");
            auto scaleFloatBox = new FloatBox<float>(window);
            scaleFloatBox->setFixedSize(Vector2i(100, 20));
            scaleFloatBox->setValue(camy);
            scaleFloatBox->setFontSize(16);
            scaleFloatBox->setValueIncrement(0.1);
            scaleFloatBox->setEditable(true);
            scaleFloatBox->setSpinnable(true);
            scaleFloatBox->setCallback([this](float translationValue) {
                this->camy = translationValue;
            });
        }
        {
            new Label(window, "Translate cam z:", "sans");
            auto scaleFloatBox = new FloatBox<float>(window);
            scaleFloatBox->setFixedSize(Vector2i(100, 20));
            scaleFloatBox->setValue(camz);
            scaleFloatBox->setFontSize(16);
            scaleFloatBox->setValueIncrement(0.1);
            scaleFloatBox->setEditable(true);
            scaleFloatBox->setSpinnable(true);
            scaleFloatBox->setCallback([this](float translationValue) {
                this->camz = translationValue;
            });
        }

        new Label(window, "Target Translation", "sans-bold");
        Widget *targetranslationTools = new Widget(window);
        targetranslationTools->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 5));

        {
            new Label(window, "Translate tar x:", "sans");
            auto scaleFloatBox = new FloatBox<float>(window);
            scaleFloatBox->setFixedSize(Vector2i(100, 20));
            scaleFloatBox->setValue(tarx);
            scaleFloatBox->setFontSize(16);
            scaleFloatBox->setValueIncrement(0.1);
            scaleFloatBox->setEditable(true);
            scaleFloatBox->setSpinnable(true);
            scaleFloatBox->setCallback([this](float translationValue) {
                this->tarx = translationValue;
            });
        }
        {
            new Label(window, "Translate tar y:", "sans");
            auto scaleFloatBox = new FloatBox<float>(window);
            scaleFloatBox->setFixedSize(Vector2i(100, 20));
            scaleFloatBox->setValue(tary);
            scaleFloatBox->setFontSize(16);
            scaleFloatBox->setValueIncrement(0.1);
            scaleFloatBox->setEditable(true);
            scaleFloatBox->setSpinnable(true);
            scaleFloatBox->setCallback([this](float translationValue) {
                this->tary = translationValue;
            });
        }
        {
            new Label(window, "Translate tar z:", "sans");
            auto scaleFloatBox = new FloatBox<float>(window);
            scaleFloatBox->setFixedSize(Vector2i(100, 20));
            scaleFloatBox->setValue(tarz);
            scaleFloatBox->setFontSize(16);
            scaleFloatBox->setValueIncrement(0.1);
            scaleFloatBox->setEditable(true);
            scaleFloatBox->setSpinnable(true);
            scaleFloatBox->setCallback([this](float translationValue) {
                this->tarz = translationValue;
            });
        }

        performLayout();

        using namespace nanogui;

        //Caricamento shaders
        std::string vertexShaderFilePath, fragmentShaderFilePath;
        std::vector<std::pair<std::string, std::string>> fileTypes;
        fileTypes.push_back(std::make_pair("vert", "vertex shader file"));

        vertexShaderFilePath = nanogui::file_dialog(fileTypes, false);

        fileTypes.clear();
        fileTypes.push_back(std::make_pair("frag", "fragent shader file"));

        fragmentShaderFilePath = nanogui::file_dialog(fileTypes, false);

        mShader.initFromFiles("Nanogui Shader", vertexShaderFilePath.c_str(), fragmentShaderFilePath.c_str());

        //Caricamento del file
        std::vector<int> tempFaces;
        std::vector<double> tempVertices;
        std::vector<std::vector<int>> vert2face;
        std::vector<double> tempFaceNormals;
        std::vector<double> tempVertNormals;

        fileTypes.clear();
        fileTypes.push_back(std::make_pair("obj", "obj file"));

        std::string filePath;
        filePath = nanogui::file_dialog(fileTypes, false);

        hasNormals = loadOBJ(filePath.c_str(), tempVertices, tempFaces, tempVertNormals);

        //Calcolo i vettori vert2face, tempFaceNormals e tempVertNormals in base ai dati della mesh
        if(!hasNormals)
            loadDerivedVectors(tempVertices, tempFaces, vert2face, tempFaceNormals, tempVertNormals);

        //Salvo il numero di vertici e facce della mesh
        unsigned long nVertices = (tempVertices.size()) / 3;
        nFaces = (uint32_t) (tempFaces.size()) / 3;

        std::vector<double> XValues;
        std::vector<double> YValues;
        std::vector<double> ZValues;

        for (unsigned long i = 0; i < nVertices; i++) {
            XValues.push_back(tempVertices[(3 * i)]);
            YValues.push_back(tempVertices[(3 * i) + 1]);
            ZValues.push_back(tempVertices[(3 * i) + 2]);
        }

        minXValue = (*std::min_element(XValues.begin(), XValues.end()));
        maxXValue = (*std::max_element(XValues.begin(), XValues.end()));
        minYValue = (*std::min_element(YValues.begin(), YValues.end()));
        maxYValue = (*std::max_element(YValues.begin(), YValues.end()));
        minZValue = (*std::max_element(ZValues.begin(), ZValues.end()));
        maxZValue = (*std::min_element(ZValues.begin(), ZValues.end()));
        std::vector<double> maxVector = {maxXValue, maxYValue, maxZValue};
        std::vector<double> minVector = {minXValue, minYValue, minZValue};
        maxValue = (*std::max_element(maxVector.begin(), maxVector.end()));
        minValue = (*std::min_element(minVector.begin(), minVector.end()));


        //CARICAMENTO VECTOR SU MATRIX
        vertices.resize(3, nVertices);
        normals.resize(3, nVertices);
        for (unsigned long i = 0; i < nVertices; i++) {
            vertices.col(i) << tempVertices[(3 * i)], tempVertices[(3 * i) + 1], tempVertices[(3 * i) + 2];
            normals.col(i) << tempVertNormals[(3 * i)],
                    tempVertNormals[(3 * i) + 1],
                    tempVertNormals[(3 * i) + 2];
        }

        Eigen::MatrixXi faces(3, nFaces);
        for (int32_t i = 0; i < nFaces; i++) {
            faces.col(i) << tempFaces[(3 * i)], tempFaces[(3 * i) + 1], tempFaces[(3 * i) + 2];
        }

        mShader.bind();
        mShader.uploadIndices(faces);
        mShader.uploadAttrib("vertices", vertices);
        mShader.uploadAttrib("normals", normals);
        mShader.setUniform("lightPosition_worldspace", lightPosition);
        //mShader.uploadAttrib("color", colors);
        //mShader.setUniform("intensity", 0.5f);
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

    // Draw the widget (and all child widgets)
    virtual void draw(NVGcontext *ctx) {
        /* Draw the user interface */
        Screen::draw(ctx);
    }

    float getScaleFactor(){
        return 1/abs(maxValue - minValue);
    }

    Vector3f getTranslationToCenter() {
        return Vector3f(-(minXValue+maxXValue)/2,-(minYValue+maxYValue)/2,-(minZValue+maxZValue)/2);
    }

    virtual void drawContents(){
        using namespace nanogui;

        /* Funzioni per la gestione dello Z-buffer*/
        glGetError();
        glEnable(GL_BLEND | GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glEnable(GL_CULL_FACE);

        /* Draw the window contents using OpenGL */
        mShader.bind();


        Matrix4f model, view, proj;
        model.setIdentity();
        view.setIdentity();
        proj.setIdentity();

        Vector3f translateVector= getTranslationToCenter() + Vector3f(tarx,tary,tarz);

        float scaleFactor = getScaleFactor();
        float near = camera_dnear;
        float far = camera_dfar;
        float top = tan((cameraViewAngle)/360.*M_PI)*near;
        float right = top * 1000/1000;

        proj = frustum(-right,right,-top,top,near,far);

        view = lookAt(Vector3f(camx,camy,camz),Vector3f(tarx,tary,tarz),Vector3f(0,1,0));

        model= scale(Vector3f(camera_zoom,camera_zoom,camera_zoom)) * scale(Vector3f(scaleFactor,scaleFactor,scaleFactor)) * translate(translateVector);

        mShader.setUniform("model", model);
        mShader.setUniform("proj", proj);
        mShader.setUniform("view", view);

        /* Draw nFaces triangles starting at index 0 */
        mShader.drawIndexed(GL_TRIANGLES, 0, nFaces);
    }

private:
    //MeshCanvas *mCanvas;
    nanogui::GLShader mShader;
    /*Numero di triangoli caricati dal file*/
    uint32_t nFaces;

    bool hasNormals;

    //Matrice di vertici
    Eigen::MatrixXd vertices;
    Eigen::MatrixXd normals;

    //Luce
    Eigen::Vector3d lightPosition= {4.0,4.0,4.0};

    /* Variabili per il calcolo della traslazione */
    double minXValue, maxXValue, minYValue, maxYValue, minZValue, maxZValue, maxValue, minValue;

    float cameraViewAngle = 45;
    float camera_dnear = 0.1;
    float camera_dfar = 100;
    float camera_zoom = 1.0;
    float camx = 0, camy = 0, camz = 1.5;
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