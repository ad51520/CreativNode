#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED
#include "Point.h"
#include <iostream>

using namespace std;


    const int NO_FRAME = 0;
    const int FRAME_RED = 1;
    const int FRAME_BLACK = 2;

    const int NORMAL_TEXT = 0;
    const int WHITE_TEXT = 1;
    const int BLACK_TEXT = 2;


class Cube{

    protected:
        Point p;
        int cR;
        int cG;
        int cB;
        int alpha;
        string tex;
        bool useTex;


    public:

        ~Cube();
        Cube(Point pi);
        Cube(int cri,int cgi,int cbi, int alphai, Point pi);
        Cube(bool enlTex, Point pi);
        Cube(string tex, Point pi);
        Cube(int cri,int cgi,int cbi,int alphai, string tex , Point pi);
        Cube cp(int x , int y , int z);
        int getR();
        int getG();
        int getB();
        int getAlpha();
        void setRGBA(int ri, int gi, int bi, int alphai);
        Point getPos();
        void enableTex();
        void disableText();
        bool getUseText();
        string getTex();
        void setText(string text);
        virtual void view(double scX,double scY, int frame , int text);


};



#endif // CUBE_H_INCLUDED
