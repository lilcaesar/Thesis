//
// Created by mattia on 12/06/17.
//

#ifndef THESIS_MESHMATRICESINITIALIZER_H
#define THESIS_MESHMATRICESINITIALIZER_H

#include <importFiles.h>

void meshMatricesInitializer(Eigen::MatrixXd &vertices, Eigen::MatrixXd &normals, Eigen::MatrixXi &faces, uint32_t &nFaces,uint32_t &nVertices,
                             double &minXValue,double &maxXValue,double &minYValue,double &maxYValue,
                             double &minZValue,double &maxZValue,double &maxValue,double &minValue, double &maxDistance){
    std::vector<int> tempFaces;
    std::vector<double> tempVertices;
    std::vector<std::vector<int>> vert2face;
    std::vector<double> tempFaceNormals;
    std::vector<double> tempVertNormals;

    std::vector<std::pair<std::string, std::string>> fileTypes;
    fileTypes.push_back(std::make_pair("obj", "obj file"));
    std::string filePath;
    filePath = nanogui::file_dialog(fileTypes, false);

    bool hasNormals = loadOBJ(filePath.c_str(), tempVertices, tempFaces, tempVertNormals);

//Calcolo i vettori vert2face, tempFaceNormals e tempVertNormals in base ai dati della mesh
    if(!hasNormals)
        loadDerivedVectors(tempVertices, tempFaces, vert2face, tempFaceNormals, tempVertNormals);

//Salvo il numero di vertici e facce della mesh
    nVertices = (tempVertices.size()) / 3;
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
    minZValue = (*std::min_element(ZValues.begin(), ZValues.end()));
    maxZValue = (*std::max_element(ZValues.begin(), ZValues.end()));

    std::vector<double> maxVector = {maxXValue, maxYValue, maxZValue};
    std::vector<double> minVector = {minXValue, minYValue, minZValue};
    maxValue = (*std::max_element(maxVector.begin(), maxVector.end()));
    minValue = (*std::min_element(minVector.begin(), minVector.end()));

    if((maxXValue-minXValue) > (maxYValue-minYValue)){
        if((maxXValue-minXValue)>(maxZValue-minZValue)){
            maxDistance = maxXValue - minXValue;
        }else{
            maxDistance = maxZValue - minZValue;
        }
    }else{
        if((maxYValue-minYValue)>(maxZValue-minZValue)){
            maxDistance = maxYValue - minYValue;
        }else{
            maxDistance = maxZValue - minZValue;
        }
    }

//CARICAMENTO VECTOR SU MATRIX
    vertices.resize(3, nVertices);
    normals.resize(3, nVertices);
    for (unsigned long i = 0; i < nVertices; i++) {
        vertices.col(i) << tempVertices[(3 * i)], tempVertices[(3 * i) + 1], tempVertices[(3 * i) + 2];
        normals.col(i) << tempVertNormals[(3 * i)],
                tempVertNormals[(3 * i) + 1],
                tempVertNormals[(3 * i) + 2];
    }

    faces.resize(3, nFaces);
    for (int32_t i = 0; i < nFaces; i++) {
        faces.col(i) << tempFaces[(3 * i)], tempFaces[(3 * i) + 1], tempFaces[(3 * i) + 2];
    }
}

void arcballMatricesInitializer(Eigen::MatrixXd &vertices, Eigen::MatrixXd &normals, Eigen::MatrixXi &faces, uint32_t &nFaces,uint32_t &nVertices){
    std::vector<int> tempFaces;
    std::vector<double> tempVertices;
    std::vector<std::vector<int>> vert2face;
    std::vector<double> tempFaceNormals;
    std::vector<double> tempVertNormals;

    bool hasNormals = loadOBJ("../resources/torus.obj", tempVertices, tempFaces, tempVertNormals);

//Calcolo i vettori vert2face, tempFaceNormals e tempVertNormals in base ai dati della mesh
    if(!hasNormals)
        loadDerivedVectors(tempVertices, tempFaces, vert2face, tempFaceNormals, tempVertNormals);

//Salvo il numero di vertici e facce della mesh
    nVertices = (tempVertices.size()) / 3;
    nFaces = (uint32_t) (tempFaces.size()) / 3;

//CARICAMENTO VECTOR SU MATRIX
    vertices.resize(3, nVertices);
    normals.resize(3, nVertices);
    for (unsigned long i = 0; i < nVertices; i++) {
        vertices.col(i) << tempVertices[(3 * i)], tempVertices[(3 * i) + 1], tempVertices[(3 * i) + 2];
        normals.col(i) << tempVertNormals[(3 * i)],
                tempVertNormals[(3 * i) + 1],
                tempVertNormals[(3 * i) + 2];
    }

    faces.resize(3, nFaces);
    for (int32_t i = 0; i < nFaces; i++) {
        faces.col(i) << tempFaces[(3 * i)], tempFaces[(3 * i) + 1], tempFaces[(3 * i) + 2];
    }
}

#endif //THESIS_MESHMATRICESINITIALIZER_H
