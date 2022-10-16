#ifndef _POINT_HPP_
#define _POINT_HPP_

class Point {
    private:
        double x;
        double y;

    public:
        double GetX();
        double GetY();
        double DistP(Point& a);
        Point() : x(0), y(0) {};
        Point(double x, double y) : x(x), y(y) {};
};



#endif          // _POINT_HPP_