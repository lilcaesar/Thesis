#ifndef IMPORTFILES_H
#define IMPORTFILES_H

#include <vector>

void load    (const char            * filename,
              std::vector<double>   & vertices,
              std::vector<int>      & faces,
              std::vector<double>   & normals);

int loadOBJ (const char            * filename,
              std::vector<double>   & vertices,
              std::vector<int>      & faces,
              std::vector<double>   & normals);

void loadPLY (const char                * filename,
              std::vector<double>       & vertices,
              std::vector<int>          & faces   );

void saveOBJ (const char                * filename,
              const std::vector<double> & vertices,
              const std::vector<int>    & faces   );

#endif // IMPORTFILES_H
