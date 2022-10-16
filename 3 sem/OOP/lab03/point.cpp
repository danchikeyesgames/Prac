#include <cmath>

#include "point.hpp"

double Point::GetX() {
    return x;
}

double Point::GetY() {
    return y;
}

double Point::DistP(Point& a) {
    double dx = x - a.x;
    double dy = y - a.y;

    return std::sqrt(dx*dx + dy*dy);
}