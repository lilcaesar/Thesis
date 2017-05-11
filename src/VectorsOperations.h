//
// Created by mattia on 08/05/17.
//

#ifndef THESIS_CALCULATENORMALS_H
#define THESIS_CALCULATENORMALS_H

using namespace std;

inline Eigen::Vector3d getVertexFromID(int id, vector<double> &vertices){
    int vID = id*3;

    return Eigen::Vector3d (vertices[vID], vertices[vID+1], vertices[vID+2]);
}

inline Eigen::Vector3d getFaceNormal(int id, vector<double> &faceNormals){
    int vID = id*3;

    return Eigen::Vector3d (faceNormals[vID], faceNormals[vID+1], faceNormals[vID+2]);
}

inline void calculateFaceNormals(vector<double> &vertices,
                          vector<int> &faces,
                          vector<double> &faceNormals) {
    int nFaces = faces.size() / 3;
    for (int f = 0; f < nFaces; ++f) {
        int fID = f * 3;

        Eigen::Vector3d v0 = getVertexFromID(faces[fID], vertices);
        Eigen::Vector3d v1 = getVertexFromID(faces[fID+1], vertices);
        Eigen::Vector3d v2 = getVertexFromID(faces[fID+2], vertices);

        Eigen::Vector3d u = v1 - v0;
        u.normalize();
        Eigen::Vector3d v = v2 - v0;
        v.normalize();
        Eigen::Vector3d n = u.cross(v);
        n.normalize();

        faceNormals.push_back(n.x());
        faceNormals.push_back(n.y());
        faceNormals.push_back(n.z());
    }
}

inline void calculateVertexNormals(vector<double> &vertices,
                            vector<int> &faces,
                            vector<vector<int>> &vert2face,
                            vector<double> &faceNormals,
                            vector<double> &vertexNormals) {

    int nVertices = vertices.size() / 3;
    int nFaces = faces.size() / 3;

    for (int vertI = 0; vertI < nVertices; ++vertI) {
        vector<int> nbrs = vert2face[vertI];

        Eigen::Vector3d sum(0.0, 0.0, 0.0);
        for (int i = 0; i < (int) nbrs.size(); ++i) {
            sum += getFaceNormal(nbrs[i], faceNormals);
        }

        sum /= nbrs.size();
        sum.normalize();

        vertexNormals.push_back(sum.x());
        vertexNormals.push_back(sum.y());
        vertexNormals.push_back(sum.z());
    }
}

inline void loadVert2face(vector<double> &vertices,
                   vector<int> &faces,
                   vector<vector<int>> &vert2face) {
    int nVertices, nFaces;
    nVertices = vertices.size() / 3;
    nFaces = faces.size() / 3;

    vert2face.resize(nVertices);

    for(int f = 0; f<nFaces; f++){
        vert2face[faces[(f*3)]].push_back(f);
        vert2face[faces[(f*3)+1]].push_back(f);
        vert2face[faces[(f*3)+2]].push_back(f);
    }

    /*vector<int> temp;

    for (int v = 0; v < nVertices; v++) {
        for (int f = 0; f < nFaces; f++) {
            if ((faces[3 * f] == v) ||
                (faces[(3 * f) + 1] == v) ||
                (faces[(3 * f) + 2] == v)) {
                temp.push_back(f);
            }
        }
        vert2face.push_back(temp);
        temp.clear();
    }*/
}

inline void loadDerivedVectors(vector<double> &vertices,
                        vector<int> &faces,
                        vector<vector<int>> &vert2face,
                        vector<double> &faceNormals,
                        vector<double> &vertexNormals) {
    loadVert2face(vertices, faces, vert2face);
    calculateFaceNormals(vertices, faces, faceNormals);
    calculateVertexNormals(vertices, faces, vert2face, faceNormals, vertexNormals);
}

#endif //THESIS_CALCULATENORMALS_H
