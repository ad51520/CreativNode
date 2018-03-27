#ifndef MAPEDITOR_H_INCLUDED
#define MAPEDITOR_H_INCLUDED

#include "../Model/Cube.h"
#include <vector>

vector<Cube*> createLayer(vector<Cube*> v,int xi,int y , int zi ,int scX,int scZ , Cube c);
vector<Cube*> createCube(vector<Cube*> v,int xi,int y , int zi ,int scX,int scY ,int scZ , Cube c);
vector<Cube*> createTree(vector<Cube*> v,int xi,int yi , int zi);





#endif // MAPEDITOR_H_INCLUDED
