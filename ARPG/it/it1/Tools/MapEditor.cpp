#include "MapEditor.h"
#include <vector>
#include <iostream>

using namespace std;


vector<Cube*> createLayer(vector<Cube*> v ,int xi , int yi ,int zi, int scX , int scZ ,Cube c){

    for(int i=0 ; i < scX ; i++){
        for(int j = 0 ; j < scZ ; j++){
            Cube *x = new Cube(c.getR(),c.getG(),c.getB(),c.getAlpha(),c.getTex(),Point(xi+i,yi,zi+j));
            if(c.getUseText())x->enableTex();
            else x->disableText();
            v.push_back(x);
        }
    }
    return v;
}

vector<Cube*> createCube(vector<Cube*> v ,int xi , int yi ,int zi, int scX ,int scY , int scZ ,Cube c){

    for(int i=0 ; i < scX ; i++){
        for(int j = 0 ; j < scZ ; j++){
            for (int k = 0 ; k < scY ; k++){
                Cube x = c.cp(i+xi,yi+k,zi+j);
                //v.push_back(x);
            }
        }
    }
    return v;
}

vector<Cube*> createTree(vector<Cube*> v,int xi,int yi , int zi){
    v = createCube(v,xi-4,yi+9,zi-4,11,9,11,Cube(37,95,0,255,Point()));
    v = createCube(v,xi,yi,zi,10,15,10,Cube(71,30,0,255,Point()));
    return v;
}












