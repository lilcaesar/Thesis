//
// Created by mattia on 08/05/17.
//

#ifndef THESIS_CALCULATENORMALS_H
#define THESIS_CALCULATENORMALS_H

Eigen::MatrixXd calculateNormals(Eigen::MatrixXd vertices, Eigen::MatrixXi faces){
    long nVertices = vertices.size()/3;
    long nFaces = faces.size()/3;

    Eigen::MatrixXd normals(3, nVertices);

    //for(long )
}

#endif //THESIS_CALCULATENORMALS_H
