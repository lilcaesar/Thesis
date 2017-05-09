//
// Created by mattia on 08/05/17.
//

#ifndef THESIS_CALCULATENORMALS_H
#define THESIS_CALCULATENORMALS_H

using namespace std;

void calculateFaceNormals(vector<double> & vertices,
                          vector<int> & faces,
                          vector<double> & faceNormals){
    int nFaces = faces.size()/3;
    for(int f=0; f<nFaces; f++){
        int fID = f*3;

        Eigen::Vector3d v0(vertices[faces[fID]], vertices[faces[fID]+1], vertices[faces[fID]+2]);
        Eigen::Vector3d v1(vertices[faces[fID+1]], vertices[faces[fID+1]+1], vertices[faces[fID+1]+2]);
        Eigen::Vector3d v2(vertices[faces[fID+2]], vertices[faces[fID+2]+1], vertices[faces[fID+2]+2]);

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

void calculateVertexNormals(vector<double> & vertices,
                            vector<int> & faces,
                            vector<vector<int>> & vert2face,
                            vector<double> & faceNormals,
                            vector<double> & vertexNormals){
    int nVertices = vertices.size()/3;
    int nFaces = faces.size()/3;

    for(int vertI=0; vertI<nVertices; vertI++){
        vector<int> nbrs = vert2face[vertI];

        Eigen::Vector3d sum(0.0,0.0,0.0);
        for(int i=0; i<(int)nbrs.size();i++){
            Eigen::Vector3d nbr(faceNormals[nbrs[i]], faceNormals[nbrs[i]+1], faceNormals[nbrs[i]+2]);
            sum += nbr;
        }

        sum /= nbrs.size();
        sum.normalize();

        int vID =vertI * 3;
        vertexNormals[vID] = sum.x();
        vertexNormals[vID+1] = sum.y();
        vertexNormals[vID+2] = sum.z();
    }
}

void loadVert2face(vector<double> & vertices,
                   vector<int> & faces,
                   vector<vector<int>> & vert2face){

    int nVertices, nFaces;
    nVertices = vertices.size()/3;
    nFaces = faces.size()/3;
    vector<int> temp;

    for(int v=0; v< nVertices; v++){
        for(int f=0; f<nFaces; f++){
            if((faces[3*f] == v) ||
               (faces[(3*f)+1] == v) ||
               (faces[(3*f)+2] == v)) {
                temp.push_back(f);
            }
        }
        vert2face.push_back(temp);
        temp.clear();
    }
}

void loadDerivedVectors(vector<double> & vertices,
                        vector<int> & faces,
                        vector<vector<int>> & vert2face,
                        vector<double> & faceNormals,
                        vector<double> & vertexNormals){
    loadVert2face(vertices, faces, vert2face);
    calculateFaceNormals(vertices, faces, faceNormals);
    calculateVertexNormals(vertices, faces, vert2face, faceNormals, vertexNormals);
}

#endif //THESIS_CALCULATENORMALS_H
