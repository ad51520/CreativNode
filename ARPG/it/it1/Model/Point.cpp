#include "Point.h"


Point::Point(){
}

Point::Point(int xi , int yi , int zi){
    this->x = xi;
    this->y = yi;
    this->z = zi;
}


int Point::getX(){
    return this->x;
}

int Point::getY(){
    return this->y;
}

int Point::getZ(){
    return this->z;
}

bool Point::operator==(Point const& a){
    if (this->equals(a)){
        return true;
    }else{
        return false;
    }

}

bool Point::equals(Point p ){
    if(p.getX()==this->getX() && p.getY()==this->getY() && p.getZ()==this->getZ()){
        return true;
    }else{
        return false;
    }
}
