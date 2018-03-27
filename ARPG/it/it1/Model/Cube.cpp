#include "Cube.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

        Cube::~Cube(){

            this->p = Point();
            this->cR = 255;
            this->cG = 255;
            this->cB = 255;
            this->alpha = 255;
            this->tex = "frame.png";
            this->useTex = false;
        }


        Cube::Cube(Point pi){
            this->p = pi;
            this->cR = 255;
            this->cG = 255;
            this->cB = 255;
            this->alpha = 255;
            this->tex = "frame.png";
            this->useTex = false;
        }

        Cube::Cube(int cri,int cgi,int cbi,int alphai, Point pi){
            this->p = pi;
            this->cR =cri;
            this->cG =cgi;
            this->cB =cbi;
            this->alpha =alphai;
            this->tex = "frame.png";
            this->useTex = false;
        }

        Cube::Cube(bool eti, Point pi){
            this->useTex = eti;
            this->p = pi;
            this->cR = 255;
            this->cG = 255;
            this->cB = 255;
            this->alpha = 255;
            this->tex = "frame.png";
        }

        Cube::Cube(string ti , Point pi){
            this->tex = ti;
            this->p = pi;
            this->useTex = true;
            this->cR = 255;
            this->cG = 255;
            this->cB = 255;
            this->alpha = 255;
        }

        Cube::Cube(int cri,int cgi,int cbi, int alphai, string ti, Point pi){
            this->alpha = alphai;
            this->tex = ti;
            this->p = pi;
            this->useTex = true;
            this->cR =cri;
            this->cG =cgi;
            this->cB =cbi;
        }

        Cube Cube::cp(int x, int y, int z){
            Cube c(getR(),getG(),getB(),getAlpha(),getTex(),Point(x,y,z));
            if(this->useTex)c.enableTex();
            else c.disableText();

            return c;
        }

        void Cube::setRGBA(int ri, int gi, int bi, int alphai){
            this->cR =ri;
            this->cG =gi;
            this->cB =bi;
            this->alpha=alphai;
        }

        int Cube::getR(){return this->cR;}
        int Cube::getG(){return this->cG;}
        int Cube::getB(){return this->cB;}
        int Cube::getAlpha(){return this->alpha;}

        Point Cube::getPos(){return this->p;}

        void Cube::enableTex(){
            this->useTex = true;
        }

        void Cube::disableText(){
            this->useTex = false;
        }

        bool Cube::getUseText(){
            return this->useTex;
        }

        string Cube::getTex(){
            return this->tex;
        }

        void Cube::setText(string ti){
            this->tex = ti;
        }

        void Cube::view(double scX,double scY, int frame , int text){

            Cube c = *this;
            if(c.getUseText()){


            }else{

                switch(text){
                    case NORMAL_TEXT:
                    glColor4ub(  c.getR()  ,   c.getG()  ,  c.getB() , c.getAlpha());
                        break;
                    case WHITE_TEXT :
                        glColor3ub(255,255,255);
                        break;
                    case BLACK_TEXT :
                        glColor3ub(0,0,0);
                        break;
                }

                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                glEnd();
                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                glEnd();
                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                glEnd();
                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                glEnd();
                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY())*scY    ,(c.getPos().getZ())*scY);
                glEnd();
                glBegin(GL_QUADS); // affiche top
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ()-1)*scY);
                    glVertex3d(  (c.getPos().getX()+1)*scX  ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
                    glVertex3d(  (c.getPos().getX())*scX    ,  (c.getPos().getY()-1)*scY  ,(c.getPos().getZ())*scY);
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












