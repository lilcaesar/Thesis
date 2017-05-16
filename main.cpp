#include <iostream>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <nanogui/nanogui.h>
#include <nanogui/glutil.h>
#include <GL/gl.h>
#include <importFiles.h>
#include <VectorsOperations.h>
#include <GL/glu.h>

/*TODO
 * -Modificare vettori temporanei in vettori di Eigen::Vector3
 * -Inserire vista prospetica (al momento è ortogonale di default)
 * -Implementare caricamento della colorazione
 * -Normali
 * -Illumninazione*/

using namespace nanogui;

class MeshCanvas : public nanogui::GLCanvas {
public:
    MeshCanvas(Widget *parent) : nanogui::GLCanvas(parent) {
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

        loadOBJ(filePath.c_str(), tempVertices, tempFaces);

        //Calcolo i vettori vert2face, tempFaceNormals e tempVertNormals in base ai dati della mesh
        loadDerivedVectors(tempVertices, tempFaces, vert2face, tempFaceNormals, tempVertNormals);

        //Salvo il numero di vertici e facce della mesh
        unsigned long nVertices = (tempVertices.size()) / 3;
        nFaces = (uint32_t) (tempFaces.size()) / 3;

        //TODO verificare che le prossime operazioni fatte prima del caricamento su matrice siano più dispendiose rispetto a farle sulle matrici stesse

        //Cerco il vertice più grande in modulo e lo uso per la scalatura
        double maxVertex = (*std::max_element(tempVertices.begin(), tempVertices.end()));
        double minVertex = (*std::min_element(tempVertices.begin(), tempVertices.end()));

        if (maxVertex > abs(minVertex))
            scaleFactor = std::abs(1 / maxVertex);
        else
            scaleFactor = std::abs(1 / minVertex);




        //Calcolo del frustum in base alla mesh

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





        //CARICAMENTO VECTOR SU MATRIX
        Eigen::MatrixXd vertices(3, nVertices);
        Eigen::MatrixXd normals(3, nVertices);
        for (unsigned long i = 0; i < nVertices; i++) {
            vertices.col(i) << tempVertices[(3 * i)], tempVertices[(3 * i) + 1], tempVertices[(3 * i) + 2];
            normals.col(i) << tempVertNormals[(3 * i)], tempVertNormals[(3 * i) + 1], tempVertNormals[(3 * i) + 2];
        }

        Eigen::MatrixXi faces(3, nFaces);
        for (int32_t i = 0; i < nFaces; i++) {
            faces.col(i) << tempFaces[(3 * i)], tempFaces[(3 * i) + 1], tempFaces[(3 * i) + 2];
        }

        Eigen::Vector3d lightPosition(4.0, 4.0, 4.0);

        mShader.bind();
        mShader.uploadIndices(faces);
        mShader.uploadAttrib("vertices", vertices);
        //mShader.uploadAttrib("normals", normals);
        //mShader.uploadAttrib("color", colors);
        mShader.setUniform("lightPosition", lightPosition);
        //mShader.setUniform("intensity", 0.5f);
    }

    ~MeshCanvas() {
        mShader.free();
    }

    void setScaleFactor(float scale) {
        scaleFactor = scale;
    }

    double getScaleFactor() {
        return scaleFactor;
    }

    //TODO Calcolare correttamente la traslazione in Z
    Vector3f getTranslationToCenter() {
        return Vector3f(-(minXValue+maxXValue)/2,-(minYValue+maxYValue)/2,-(minZValue+maxZValue)/2 -1.5);
    }


    virtual void drawGL() override {
        using namespace nanogui;

        /* Draw the window contents using OpenGL */
        mShader.bind();

        Matrix4f mvp;
        Matrix4f model;
        Matrix4f proj;
        mvp.setIdentity();
        model.setIdentity();
        proj.setIdentity();
        Vector3f scaleVector = {scaleFactor, scaleFactor, scaleFactor};
        Vector3f translateVector = getTranslationToCenter();

        //TODO Calcolare correttamente il frustum
        proj = frustum(-1, 1, -1, 1, 1, 30);
        proj.transposeInPlace();


        model = (translate(translateVector)) * (scale(scaleVector));

        mvp = proj * /* view * */model;

        mShader.setUniform("modelViewProj", mvp);
        //mShader.setUniform("modelMatrix", model);
        //mShader.setUniform("projection", proj);

        /* Funzioni per la gestione dello Z-buffer*/
        glClearDepth(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDepthFunc(GL_LESS);
        glEnable(GL_DEPTH_TEST);

        /* Draw nFaces triangles starting at index 0 */
        mShader.drawIndexed(GL_TRIANGLES, 0, nFaces);
    }

private:
    nanogui::GLShader mShader;
    /*Numero di triangoli caricati dal file*/
    uint32_t nFaces;
    double scaleFactor = 1;

    /* Variabili per il calcolo del frustum*/
    double minXValue, maxXValue, minYValue, maxYValue, minZValue, maxZValue;
};

class NanoguiMeshViewer : public nanogui::Screen {
public:
    NanoguiMeshViewer() : nanogui::Screen(Eigen::Vector2i(800, 800), "Nanogui Mesh Viewer") {
        using namespace nanogui;

        Window *window = new Window(this, "Model Canvas");
        window->setPosition(Vector2i(0, 0));
        window->setLayout(new GroupLayout());

        mCanvas = new MeshCanvas(window);
        mCanvas->setBackgroundColor({100, 100, 100, 255});
        mCanvas->setSize({600, 600});

        new Label(window, "Transform Tools", "sans-bold");
        Widget *transformTools = new Widget(window);
        transformTools->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 5));

        /* Scale widget*/{
            new Label(window, "Scale :", "sans");
            auto scaleFloatBox = new FloatBox<float>(window);
            scaleFloatBox->setFixedSize(Vector2i(100, 20));
            scaleFloatBox->setValue(mCanvas->getScaleFactor());
            scaleFloatBox->setFontSize(16);
            scaleFloatBox->setValueIncrement(mCanvas->getScaleFactor() / 10);
            scaleFloatBox->setMinValue(0);
            scaleFloatBox->setEditable(true);
            scaleFloatBox->setSpinnable(true);
            scaleFloatBox->setCallback([this](float scaleValue) {
                this->mCanvas->setScaleFactor(scaleValue);
            });
        }

        performLayout();
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

private:
    MeshCanvas *mCanvas;
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