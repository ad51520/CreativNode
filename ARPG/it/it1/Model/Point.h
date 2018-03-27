#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point {

    private:
        int  x,y,z;
    public :
    Point();
        Point(int xi , int yi , int zi);
        int getX();
        int getY();
        int getZ();
        bool operator==(Point const& a);
        bool equals(Point p);
};


#endif // POINT_H_INCLUDED
