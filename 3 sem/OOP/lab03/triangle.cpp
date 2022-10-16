#include <iostream>
#include <cmath>

#include "triangle.hpp"

Triangle::Triangle(std::istream& in) {
    int x, y;
    
    numvertex = 3;
    for (int i = 0; i < numvertex; ++i) {
        in >> x;
        in >> y;

        new (&p[i]) Point(x, y);
    }
}

size_t Triangle::VertexNumber() {
    return (size_t) numvertex;
}

double Triangle::Area() {
    double a = p[0].DistP(p[1]);
    double b = p[1].DistP(p[2]);
    double c = p[2].DistP(p[0]);
    double _p = ( a + b + c ) / 2;

    return std::sqrt(_p * (_p - a) * (_p - b) * (_p - c));
}

void Triangle::Print(std::ostream& os) {
    os << "Triangle:\n";
    for (int i = 0; i < numvertex; ++i)
        os << "( " << p[i].GetX() << ", " << p[i].GetY() << " )\n";
}