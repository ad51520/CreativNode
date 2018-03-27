#ifndef OBJ_H_INCLUDED
#define OBJ_H_INCLUDED

#include <string>
#include "Point.h"
#include "Cube.h"
#include <vector>

using namespace std;

vector<Cube*> ObjGen(int x,int y,int z,string path,vector<Cube*> v);
vector<Cube*> GoxelTxtGen(int x,int y,int z,string path,vector<Cube*> v);

#endif // OBJ_H_INCLUDED
