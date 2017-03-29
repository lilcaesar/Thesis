#include <iostream>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <nanogui/nanogui.h>
#include <nanogui/glutil.h>
#include <GL/gl.h>
#include <importFiles.h>

using namespace nanogui;

class ProvaCubo : public nanogui::Screen {
public:
    ProvaCubo():nanogui::Screen(Eigen::Vector2i(1920,1080), "Prova Cubo titolo"){
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

        //Calcolo del frustum in base alla mesh

        float frustumLeft, frustumRight, frustumBottom, frustumTop, frustumNear, frustumFar;
        std::vector<double> XValues;
        std::vector<double> YValues;
        std::vector<double> ZValues;

        for(unsigned long i=0; i < nVertices; i++){
            XValues.push_back(tempVertices[(3*i)]);
            YValues.push_back(tempVertices[(3*i)+1]);
            ZValues.push_back(tempVertices[(3*i)+2]);
        }

         std::min_element(XValues.begin(),XValues.end());

        frustumLeft = (float)(*std::min_element(XValues.begin(),XValues.end()));
        frustumRight = (float)(*std::max_element(XValues.begin(),XValues.end()));
        frustumBottom = (float)(*std::min_element(YValues.begin(),YValues.end()));
        frustumTop = (float)(*std::max_element(YValues.begin(),YValues.end()));
        frustumNear = (float)(*std::max_element(ZValues.begin(),ZValues.end()));
        frustumFar = (float)(*std::min_element(ZValues.begin(),ZValues.end()));

        nanogui::frustum(frustumLeft*2, frustumRight, frustumBottom, frustumTop, frustumNear, frustumFar);

        //CARICAMENTO VECTOR SU MATRIX
        Eigen::MatrixXd vertices(3, nVertices);
        for(unsigned long i=0; i < nVertices; i++){
            vertices.col(i) << tempVertices[(3*i)], tempVertices[(3*i)+1], tempVertices[(3*i)+2];
        }

        Eigen::MatrixXi faces(3, nFaces);
        for(int32_t i=0; i < nFaces; i++){
            faces.col(i) << tempFaces[(3*i)], tempFaces[(3*i)+1], tempFaces[(3*i)+2];
        }

        /* Hard coded cube*/
        /*Eigen::MatrixXd positions(3, 8);
        positions.col(0) << -1.000000,-1.000000,-1.000000;
        positions.col(1) << 1.000000,-1.000000,-1.000000;
        positions.col(2) << 1.000000,-1.000000,1.000000;
        positions.col(3) << -1.000000,-1.000000,1.000000;
        positions.col(4) << -1.000000,1.000000,-1.000000;
        positions.col(5) << 1.000000,1.000000,-1.000000;
        positions.col(6) << 1.000000,1.000000,1.000000;
        positions.col(7) << -1.000000,1.000000,1.000000;*/

        //Eigen::MatrixXi indices(3, 12); /* Cube triangles indices */
        /*indices.col(0) << 0,1,3;
        indices.col(1) << 1,2,3;
        indices.col(2) << 1,2,5;
        indices.col(3) << 2,5,6;
        indices.col(4) << 2,3,7;
        indices.col(5) << 2,6,7;
        indices.col(6) << 1,4,5;
        indices.col(7) << 0,1,4;
        indices.col(8) << 3,4,7;
        indices.col(9) << 0,3,4;
        indices.col(10) << 4,5,7;
        indices.col(11) << 5,6,7;*/

        /*Eigen::MatrixXd colors (3, 12);
        colors.col(0) << 1, 0, 0;
        colors.col(1) << 0, 1, 0;
        colors.col(2) << 1, 1, 0;
        colors.col(3) << 0, 0, 1;
        colors.col(4) << 1, 0, 1;
        colors.col(5) << 0, 1, 1;
        colors.col(6) << 1, 1, 1;
        colors.col(7) << 0.5, 0.5, 0.5;
        colors.col(8) << 1, 0, 0.5;
        colors.col(9) << 1, 0.5, 0;
        colors.col(10) << 0.5, 1, 0;
        colors.col(11) << 0.5, 1, 0.5;*/


        mShader.bind();
        mShader.uploadIndices(faces);
        mShader.uploadAttrib("vertices", vertices);
        //mShader.uploadAttrib("color", colors);
        //mShader.setUniform("intensity", 0.5f);

        performLayout();
    }

    ~ProvaCubo() {
        mShader.free();
    }

    virtual void drawContents() {
        using namespace nanogui;

        /* Draw the window contents using OpenGL */
        mShader.bind();

        Matrix4f mvp;
        mvp.setIdentity();
        mvp.topLeftCorner<3,3>() = (Matrix3f(Eigen::AngleAxisf((float) glfwGetTime(),  Vector3f::UnitY())) * 0.5f) * (Matrix3f(Eigen::AngleAxisf((float) glfwGetTime()/2,  Vector3f::UnitZ())) * 0.5f);

        mvp.row(0) *= (float) mSize.y() / (float) mSize.x();

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
};

int main(int /* argc */, char ** /* argv */) {
    nanogui::init();
    {
        nanogui::ref<ProvaCubo> app = new ProvaCubo();

        app->drawAll();
        app->setVisible(true);

        nanogui::mainloop();
    }

    nanogui::shutdown();
}