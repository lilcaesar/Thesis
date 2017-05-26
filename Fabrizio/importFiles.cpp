#include "importFiles.h"

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

void load    (const char            * filename,
              std::vector<double>   & vertices,
              std::vector<int>      & faces,
              std::vector<double>   & normals)
{
   string str(filename);
   string filetype = str.substr(str.size()-3,3);

   if ( filetype.compare("obj") == 0 ||
        filetype.compare("OBJ") == 0    )
   {
      loadOBJ(filename, vertices, faces, normals);
   }
   else
   if ( filetype.compare("ply") == 0 ||
        filetype.compare("PLY") == 0   )
   {
      loadPLY(filename, vertices, faces);
   }
   else
   if ( filetype.compare("off") == 0 ||
        filetype.compare("OFF") == 0   )
   {
      //loadOFF(filename, vertices, faces);
   }
   else
   {
      cerr << "ERROR : " << __FILE__ << ", line " << __LINE__ << " : load() : file format not supported yet " << endl;
      exit(-1);
   }
}

bool loadOBJ (const char            * filename,
              std::vector<double>   & vertices,
              std::vector<int>      & faces,
              std::vector<double>   & normals)
{
   //CODE FROM CAGELAB TO REWRITE AS SOON AS POSSIBLE!!! ONLY FOR TEMPORARY USE

    ifstream file(filename);
    bool  hasNormals = false;

    if (!file.is_open())
    {
        cerr << "ERROR : " << __FILE__ << ", line " << __LINE__ << " : load_OBJ() : couldn't open input file " << filename << endl;
        exit(-1);
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);

        string token;
        iss >> token;
        if (token.size() > 1) {
            if(token == "vn"){
                hasNormals = true;
                double x, y, z;
                iss >> x >> y >> z;
                normals.push_back(x);
                normals.push_back(y);
                normals.push_back(z);
                //cout << "v " << x << " " << y << " " << z << endl;
            }
            else {
                continue; // vn,fn  .... I don't care
            }
        }
        else {
            if (token[0] == 'v') {
                double x, y, z;
                iss >> x >> y >> z;
                vertices.push_back(x);
                vertices.push_back(y);
                vertices.push_back(z);
                //cout << "v " << x << " " << y << " " << z << endl;
            } else if (token[0] == 'f') {
                int v0, v1, v2, n;
                char c;
                if (hasNormals)
                    iss >> v0 >> c >> c >> n >> v1 >> c >> c >> n >> v2;
                else
                    iss >> v0 >> v1 >> v2;
                faces.push_back(v0 - 1);
                faces.push_back(v1 - 1);
                faces.push_back(v2 - 1);
                //cout << "f " << v0 << " " << v1 << " " << v2 << endl;
            }
        }
    }
    file.close();
    return hasNormals;
}

void loadPLY ( const char     * filename,
               vector<double> & vertices,
               vector<int>    & faces)
{
   //CODE FROM CAGELAB TO REWRITE AS SOON AS POSSIBLE!!! ONLY FOR TEMPORARY USE
   int vnum, fnum;

   ifstream file(filename);
   if (!file.is_open())
   {
      cerr << "ERROR : " << __FILE__ << ", line " << __LINE__ << " : load_PLY() : couldn't open input file " << filename << endl;
      exit(-1);
   }

   string line;
   unsigned found;
   bool flag = false;

   //Retrieve informations from headers
   while(getline(file, line))
   {
      if (line.find("element vertex") != std::string::npos)
      {
         found = line.find_last_of(" ");
         vnum = atoi(line.substr(found+1).c_str());
      }
      if (line.find("element face") != std::string::npos)
      {
         found = line.find_last_of(" ");
         fnum = atoi(line.substr(found+1).c_str());
      }
      if (line.find("int flags") != std::string::npos)
      {
         flag = true;
      }
      if (line == "end_header")
         break;
   }

   double x,y,z;
   //double u,v,quality;
   //int flags;


   vertices.reserve(vnum*3);
   faces.reserve(fnum*3);

   //M.V = MatrixXd (vnum, 3);
   //M.F = MatrixXi (fnum, 3);
   //C.Vmesh = MatrixXd (vnum, 2);
   //C.QVmesh = VectorXi (vnum);

   //Get vertex coordinates for each vertex
   for(int i=0; i<vnum; i++)
   {
      getline(file, line);
      stringstream linestream(line);
      linestream >> x >> y >> z;
      //if(flag)
         //linestream >> x >> y >> z >> flags >> quality >>
         //              u >> v;
       //else
         //linestream >> x >> y >> z >> quality >>
         //              u >> v;

      //Save coordinates for each vertex
      vertices.push_back(x);
      vertices.push_back(y);
      vertices.push_back(z);

      //M.V.row(i) = Vector3d(x,y,z);
      //C.Vmesh.row(i) = Vector2d(u,v);
      //C.QVmesh[i] = quality;

   }
   int tmp, v0,v1,v2;
   for(int i=0; i<fnum; i++)
   {
      getline(file, line);
      stringstream linestream(line);
      linestream >> tmp >> v0 >> v1 >> v2;
      faces.push_back(v0);
      faces.push_back(v1);
      faces.push_back(v2);
      //M.F.row(i) = Vector3i(v0,v1,v2);
   }
}

void saveOBJ ( const char                 * filename ,
               const std::vector<double>  & vertices ,
               const std::vector<int>     & faces    )
{
   ofstream fp;
   fp.open (filename);
   fp.precision(6);
   fp.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed

   if(!fp)
   {
      cerr << "ERROR : " << __FILE__ << ", line " << __LINE__ << " : save_OBJ() : couldn't open output file " << filename << endl;
      exit(-1);
   }

   //cout << "v " << vertices[3] << " " << vertices[4] << " " << vertices[5] << endl;

   for(int i=0; i<(int)vertices.size(); i+=3)
   {
      fp << "v " << vertices[i] << " " << vertices[i+1] << " " << vertices[i+2] << endl;
   }

   for(int i=0; i<(int)faces.size(); i+=3)
   {
      fp << "f " << faces[i]+1 << " " << faces[i+1]+1 << " " << faces[i+2]+1 << endl;
   }

   fp.close();
}
