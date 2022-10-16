#include <iostream>
#include <cmath>

#include "hexagon.hpp"

Hexagon::Hexagon(std::istream& in) {
    int x, y;
    
    numvertex = 6;
    for (int i = 0; i < numvertex; ++i) {
        in >> x;
        in >> y;

        new (&p[i]) Point(x, y);
    }
}

size_t Hexagon::VertexNumber() {
    return (size_t) numvertex;
}

double Hexagon::Area() {
    double sum1 = 0;
    double sum2 = 0;

    for (int i = 0; i < numvertex; ++i) {
        if (i == numvertex - 1) {
            sum1 += p[i].GetX() * p[0].GetY();
            sum2 += p[i].GetY() * p[0].GetX();
        } else { 
            sum1 += p[i].GetX() * p[i+1].GetY();
            sum2 += p[i].GetY() * p[i+1].GetX();
        }
    }

    return std::abs(sum1 - sum2) / 2;
}

void Hexagon::Print(std::ostream& os) {
    os << "Hexagon:\n";
    for (int i = 0; i < numvertex; ++i)
        os << "( " << p[i].GetX() << ", " << p[i].GetY() << " )\n";
}