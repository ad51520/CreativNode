
#include "Console.h"


#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL_ttf.h>
#include "Tools/TextDraw.h"



Console::Console(){
    this->log = "#ARPG Project - Iteration 1 --- Debug Console";
}


void Console::launch(){
    bool stop = false;
    SDL_Event event;

    while(!stop){

        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                stop = true;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        stop = true;

                        glPopMatrix();
                        glFlush();
                        SDL_GL_SwapBuffers();

                        break;
                    default :
                        break;
                }
                break;
        }


        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glMatrixMode (GL_MODELVIEW);
        glLoadIdentity ();
        glDisable(GL_DEPTH_TEST);



        SDL_Color sC = {255,255,255,0};

        RenderText(this->log,sC,0,0,50);


        glMatrixMode (GL_PROJECTION);
        glMatrixMode (GL_MODELVIEW);
        glEnable(GL_DEPTH_TEST);


        glPopMatrix();
        glFlush();
        SDL_GL_SwapBuffers();

    }

}
