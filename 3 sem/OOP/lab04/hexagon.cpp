#include <iostream>
#include <cmath>

#include "hexagon.hpp"

Hexagon::Hexagon(std::istream& in) {
    double x, y;
    
    numvertex = 6;
    for (int i = 0; i < numvertex; ++i) {
        in >> x;
        in >> y;

        new (&p[i]) Point(x, y);
    }
}

Hexagon::Hexagon() {
    numvertex = 6;
    for (int i = 0; i < numvertex; ++i) {
        new (&p[i]) Point(0, 0);
    }
}

Hexagon::Hexagon(Hexagon& hex) {
    numvertex = 6;
    for (int i = 0; i < numvertex; ++i) {
        p[i] = hex.p[i];
    }
}

Hexagon::Hexagon(Point a, Point b, Point c, Point d, Point e, Point f) {
    numvertex = 6;
    new (&p[0]) Point(a);
    new (&p[1]) Point(b);
    new (&p[2]) Point(c);
    new (&p[3]) Point(d);
    new (&p[4]) Point(e);
    new (&p[5]) Point(f);
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

std::istream& operator>>(std::istream& is, Hexagon& hex) {
    double x, y;
    
    for (int i = 0; i < hex.numvertex; ++i) {
        is >> x >> y;

        new (&(hex.p[i])) Point(x, y);
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, Hexagon& hex) {
    os << "Hexagon:\n";
    for (int i = 0; i < hex.numvertex; ++i)
        os << "( " << hex.p[i].GetX() << ", " << hex.p[i].GetY() << " )\n";

    return os;
}

Hexagon& Hexagon::operator=(const Hexagon& hex) {
    numvertex = 6;

    for (int i = 0; i < numvertex; ++i) {
        p[i] = hex.p[i];
    }

    return *this;
}

bool Hexagon::operator==(Hexagon& hex) {
    for (int i = 0; i < numvertex; ++i) {
        if (p[i] != hex.p[i]) return false;
    }

    return true;
}