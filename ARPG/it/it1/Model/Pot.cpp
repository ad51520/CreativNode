#include "Pot.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

Pot::Pot(int ri , int gi , int bi ,int alp ,Point p) : Cube(ri,gi,bi,alp,Point(p)){

}

    void Pot::view(double scX,double scY, int frame , int text){
            Cube c = *this;
            if(c.getUseText()){

            }else{

                switch(text){
                    case NORMAL_TEXT:
                    glColor3ub(68,44,0);
                    glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX())*scX+scX*0.1    ,  (c.getPos().getY())*scY-scY*0.25    ,(c.getPos().getZ()-1)*scY+scY*0.1 );
                    glVertex3d(  (c.getPos().getX()+1)*scX-scX*0.1 ,  (c.getPos().getY())*scY-scY*0.25     ,(c.getPos().getZ()-1)*scY+scY*0.1 );
                    glVertex3d(  (c.getPos().getX()+1)*scX-scX*0.1 ,  (c.getPos().getY())*scY-scY*0.25     ,(c.getPos().getZ())*scY-scY*0.1);
                    glVertex3d(  (c.getPos().getX())*scX+scX*0.1    ,  (c.getPos().getY())*scY-scY*0.25     ,(c.getPos().getZ())*scY-scY*0.1);
                    glEnd();
                    glColor4ub(  c.getR()  ,   c.getG()  ,  c.getB() , c.getAlpha());
                        break;
                    case WHITE_TEXT :
                        glColor3ub(255,255,255);
                        break;
                    case BLACK_TEXT :
                        glColor3ub(0,0,0);
                        break;
                }

                glBegin(GL_QUADS); // affiche front
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                glEnd();
                glBegin(GL_QUADS); // affiche back
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                glEnd();
                glBegin(GL_QUADS); // affiche left
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                glEnd();
                glBegin(GL_QUADS); // affiche right
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                glEnd();
                glBegin(GL_QUADS); // affiche bot
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                glEnd();



                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY  ,(c.getPos().getZ()-1)*scY-scY*0.1);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY  ,(c.getPos().getZ()-1)*scY-scY*0.1);
                glEnd();
                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY  ,(c.getPos().getZ()-1)*scY-scY*0.1);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY  ,(c.getPos().getZ())*scY-scY*0.1);
                glEnd();
                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY  ,(c.getPos().getZ())*scY-scY*0.1);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY  ,(c.getPos().getZ())*scY-scY*0.1);
                glEnd();
                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY  ,(c.getPos().getZ()-1)*scY-scY*0.1);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY  ,(c.getPos().getZ())*scY-scY*0.1);
                glEnd();


                if(frame!=NO_FRAME){

                    switch(frame){
                        case FRAME_BLACK:
                            glColor3ub(0,0,0);
                            break;
                        case FRAME_RED :
                            glColor3ub(255,0,0);
                            break;
                    }

                    glBegin(GL_LINE_LOOP);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                        glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                        glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                    glEnd();
                }
            }
}
