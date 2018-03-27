#include "Obj.h"
#include <iostream>
#include <fstream>
#include <cstdlib>



vector<Cube*> ObjGen(int xi, int yi,int zi , string path,vector<Cube*> v){
ifstream iS(path.c_str());  //Ouverture d'un fichier en lecture
cout << path << endl;

    if(iS)
    {

        string temp1;
        string temp2;
        Point pc;
        float r,g,b;
        float x,y,z;
        cout << "In file : " << path << endl ;

        while (iS >> temp1){
            if (temp1 == "#"){
                getline(iS,temp2);
                cout << "Comantaire : " << temp2 << endl;
            }
            if (temp1 == "v"){

                cout << "Cord :        " ;
                    iS >> x ;
                    x += xi ;
                    cout << x << " " ;
                    iS >> y ;
                    y += yi ;
                    cout << y << " " ;
                    iS >> z;
                    z += zi ;
                    cout << z << " " ;


                cout << "         Color :        " ;

                    iS >> r ;
                    cout << r << " " ;
                    iS >> g ;
                    cout << g << " " ;
                    iS >> b ;
                    cout << b << " " ;
                    v.push_back(new Cube(r*255,g*255,b*255,255,Point(x,z,y)));

                cout << endl;

            }
            for(int i = 6 ; i <6 ; i++){
                getline(iS,temp2);
            }
        }
    }
    else cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

    return v;
}


vector<Cube*> GoxelTxtGen(int xi, int yi,int zi , string path,vector<Cube*> v){
    ifstream iS(path.c_str());  //Ouverture d'un fichier en lecture
    cout << path << endl;

    if(iS)
    {

        string temp1;
        string temp2;
        char c1,c2;
        Point pc;
        float r,g,b;
        float x,y,z;
        int pos = 0;
        cout << "In file : " << path << endl ;

        while (iS >> temp1){
            if (temp1 == "#"){
                getline(iS,temp2);
                cout << "Comentaire : " << temp2 << endl;
            }else{

                iS.seekg(pos, ios::beg);
                cout << "Cord :        " ;
                    iS >> x ;
                    x += xi ;
                    cout << x << " " ;
                    iS >> y ;
                    y += yi ;
                    cout << y << " " ;
                    iS >> z;
                    z += zi ;
                    cout << z << " " ;


                cout << "         Color :        " ;
                    iS.get();
                    iS.get(c1) ;
                    iS.get(c2) ;
                    string s = "";
                    char *p;
                    s.push_back(c1);
                    s.push_back(c2);
                    r = strtol( s.c_str(), & p, 16 );
                    cout << r << " " ;

                    iS.get(c1) ;
                    iS.get(c2) ;
                    s = "";
                    s.push_back(c1);
                    s.push_back(c2);
                    g = strtol( s.c_str(), & p, 16 );
                    cout << g << " " ;

                    iS.get(c1) ;
                    iS.get(c2) ;
                    s = "";
                    s.push_back(c1);
                    s.push_back(c2);
                    b = strtol( s.c_str(), & p, 16 );
                    cout << b << " " ;
                    v.push_back(new Cube(r,g,b,255,Point(x,z,y)));

                cout << endl;

            }
            pos = iS.tellg();
        }
    }
    else cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

    return v;
}
