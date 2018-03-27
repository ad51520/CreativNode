#ifndef POT_H_INCLUDED
#define POT_H_INCLUDED

#include "Cube.h"

class Pot : public Cube{

    public:
        Pot(int ri, int gi ,int bi , int alp ,Point p);
        void view(double scX,double scY, int frame , int text);

};


#endif // POT_H_INCLUDED
