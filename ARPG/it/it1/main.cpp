// g++ -Wall ./Model/*.cpp ./*.cpp -o It1 -lSDL_ttf  -lGL -lGLU `sdl-config --cflags --libs`

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Model/Grass.h"
#include "Model/Sand.h"
#include "Model/Water.h"
#include "Model/Pot.h"
#include "Tools/MapEditor.h"
#include "Model/Obj.h"
#include <vector>
#include <iostream>
#include <unistd.h>
#include "Console.h"

using namespace std;

void mapDisplay(vector<Cube*> v,double sx,double sy , int frame , int text);



int main(int argc, char *argv[])
{


    int const fps = 30;
    int const xScreen = 1000;
    int const yScreen = 1000;
    int const scale = 20; // echelle en pixel par block

    double scY = (1/(double)yScreen)*scale;
    double scX = (1/(double)xScreen)*scale;


    SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();
    SDL_WM_SetCaption("It 1",NULL);
    SDL_SetVideoMode(xScreen,yScreen, 32, SDL_OPENGL);
    bool continuer = true;
    SDL_Event event;
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    glEnable(GL_DEPTH_TEST);
    Console *conso = new Console();

    vector<Cube*> l;

    //l.push_back(new Pot(172,117,16,255,Point(0,1,0)));
    //l = ObjGen(0,0,0,"tree.obj",l);
    l = GoxelTxtGen(0,0,-20,"treesmall.txt",l);


    //l = createLayer(l,-4,-1,-2,10,10,Grass(Point()));



    while (continuer)
    {


       SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_UP:
                        glRotated(5,1,0,0);
                        break;
                    case SDLK_DOWN:
                        glRotated(-5,1,0,0);
                        break;
                    case SDLK_LEFT:
                        glRotated(5,0,1,0);
                        break;
                    case SDLK_RIGHT:
                        glRotated(-5,0,1,0);
                        break;
                    case SDLK_F3:
                        conso->launch();
                        break;
                    default:
                        break;
                }
                break;
        }



        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;

        glPushMatrix();
        mapDisplay(l,scX,scY,FRAME_BLACK,NORMAL_TEXT);
        glPopMatrix();
        glFlush();
        SDL_GL_SwapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;

        usleep(1000000/fps); // application des fps

    }

    SDL_Quit();

    return 0;
}


void mapDisplay(vector<Cube*> v,double scX,double scY, int frame , int text){
    for(Cube* c : v){ //prend toutes les valeurs de la liste
        c->view(scX,scY,frame,text);
    }
}

