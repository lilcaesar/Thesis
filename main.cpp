#include <iostream>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <nanogui/nanogui.h>
#include <nanogui/glutil.h>
#include <GL/gl.h>
#include <importFiles.h>

/*TODO
 * -Inserire vista prospetica (al momento è ortogonale di default)
 * -Implementare caricamento della colorazione
 * -Normali*/

using namespace nanogui;

class MeshCanvas : public nanogui::GLCanvas {
public:
    MeshCanvas(Widget *parent) : nanogui::GLCanvas(parent){
        using namespace nanogui;

        mShader.init(
                /* An identifying name */
                "a_simple_shader",

                /* Vertex shader */
                "#version 330\n"
                        "uniform mat4 modelViewProj;\n"
                        "out vec4 frag_color;\n"
                        "in vec3 vertices;\n"
                        "in vec3 color;\n"
                        "void main() {\n"
                        "    frag_color = 3.0 * modelViewProj * vec4(color, 1.0);\n"
                        "    gl_Position = modelViewProj * vec4(vertices, 1.0);\n"
                        "}",

                /* Fragment shader */
                "#version 330\n"
                        "out vec4 color;\n"
                        "in vec4 frag_color;\n"
                        "void main() {\n"
                        "    color = frag_color;\n"
                        "}"
        );

        //Caricamento del file
        std::vector<int> tempFaces;
        std::vector<double> tempVertices;

        std::vector<std::pair<std::string, std::string>> fileTypes;
        fileTypes.push_back(std::make_pair("obj", "obj file"));

        std::string filePath;
        filePath = nanogui::file_dialog(fileTypes, false);

        loadOBJ(filePath.c_str(), tempVertices, tempFaces);

        //Salvo il numero di vertici e facce della mesh
        unsigned long nVertices = (tempVertices.size())/3;
        nFaces = (uint32_t) (tempFaces.size())/3;

        //TODO verificare che le prossime operazioni fatte prima del caricamento su matrice siano più dispendiose rispetto a farle sulle matrici stesse

        //Cerco il vertice più grande in modulo e lo uso per la scalatura
        double maxVertex = (*std::max_element(tempVertices.begin(), tempVertices.end()));
        double minVertex = (*std::min_element(tempVertices.begin(), tempVertices.end()));

        if(maxVertex > abs(minVertex))
            scaleFactor = std::abs(1/maxVertex);
        else
            scaleFactor = std::abs(1/minVertex);

        //CARICAMENTO VECTOR SU MATRIX
        Eigen::MatrixXd vertices(3, nVertices);
        for(unsigned long i=0; i < nVertices; i++){
            vertices.col(i) << tempVertices[(3*i)], tempVertices[(3*i)+1], tempVertices[(3*i)+2];
        }

        Eigen::MatrixXi faces(3, nFaces);
        for(int32_t i=0; i < nFaces; i++){
            faces.col(i) << tempFaces[(3*i)], tempFaces[(3*i)+1], tempFaces[(3*i)+2];
        }

        mShader.bind();
        mShader.uploadIndices(faces);
        mShader.uploadAttrib("vertices", vertices);
        //mShader.uploadAttrib("color", colors);
        //mShader.setUniform("intensity", 0.5f);
    }

    ~MeshCanvas() {
        mShader.free();
    }

    void setScaleFactor(float scale){
        scaleFactor = scale;
    }

    double getScaleFactor(){
        return scaleFactor;
    }


    virtual void drawGL() override {
        using namespace nanogui;

        /* Draw the window contents using OpenGL */
        mShader.bind();

        Matrix4f mvp;
        mvp.setIdentity();
        Vector3f scaleVector = {scaleFactor, scaleFactor, scaleFactor};

        mvp =scale(scaleVector);

        mShader.setUniform("modelViewProj", mvp);

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
};

class NanoguiMeshViewer : public nanogui::Screen {
public:
    NanoguiMeshViewer():nanogui::Screen(Eigen::Vector2i(800,800), "Nanogui Mesh Viewer"){
        using namespace nanogui;

        Window *window = new Window(this, "Model Canvas");
        window->setPosition(Vector2i(0,0));
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
            scaleFloatBox->setValueIncrement(mCanvas->getScaleFactor()/10);
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