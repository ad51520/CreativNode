#include "Obj.h"
#include <iostream>
#include <fstream>
#include <cstdlib>



vector<Cube*> ObjGen(int xi, int yi,int zi , string path,vector<Cube*> v){
ifstream iS(path.c_str());  

    if(iS)
    {

        string temp1;
        string temp2;
        Point pc;
        float r,g,b;
        float x,y,z;

        while (iS >> temp1){
            if (temp1 == "#"){
                getline(iS,temp2);
            }
            if (temp1 == "v"){

                    iS >> x ;
                    x += xi ;
                    iS >> y ;
                    y += yi ;
                    iS >> z;
                    z += zi ;


                    iS >> r ;
                    iS >> g ;
                    iS >> b ;
                    v.push_back(new Cube(r*255,g*255,b*255,255,Point(x,z,y)));

            }
            for(int i = 6 ; i <6 ; i++){
                getline(iS,temp2);
            }
        }
    }
    else cout << "ERROR: Impossible to open : " << path << endl;

    return v;
}


vector<Cube*> GoxelTxtGen(int xi, int yi,int zi , string path,vector<Cube*> v){
    ifstream iS(path.c_str());  //Ouverture d'un fichier en lecture

    if(iS)
    {

        string temp1;
        string temp2;
        char c1,c2;
        Point pc;
        float r,g,b;
        float x,y,z;
        int pos = 0;

        while (iS >> temp1){
            if (temp1 == "#"){
                getline(iS,temp2);
            }else{

                iS.seekg(pos, ios::beg);
                    iS >> x ;
                    x += xi ;
                    iS >> y ;
                    y += yi ;
                    iS >> z;
                    z += zi ;

                    iS.get();
                    iS.get(c1) ;
                    iS.get(c2) ;
                    string s = "";
                    char *p;
                    s.push_back(c1);
                    s.push_back(c2);
                    r = strtol( s.c_str(), & p, 16 );

                    iS.get(c1) ;
                    iS.get(c2) ;
                    s = "";
                    s.push_back(c1);
                    s.push_back(c2);
                    g = strtol( s.c_str(), & p, 16 );

                    iS.get(c1) ;
                    iS.get(c2) ;
                    s = "";
                    s.push_back(c1);
                    s.push_back(c2);
                    b = strtol( s.c_str(), & p, 16 );
                    v.push_back(new Cube(r,g,b,255,Point(x,z,y)));


            }
            pos = iS.tellg();
        }
    }
    else cout << "ERROR: Impossible to open : " << path << endl;

    return v;
}
