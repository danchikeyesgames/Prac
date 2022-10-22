#ifndef _HEXAGON_HPP_
#define _HEXAGON_HPP_

#include <iostream>

#include "figure.hpp"

class Hexagon : public Figure {
    public:
        Hexagon(std::istream& in);
        Hexagon(Hexagon& hex);
        Hexagon();
        size_t  VertexNumber();
        double  Area();
        void    Print(std::ostream& os);
    
    private:
        Point p[6];
    
    public:
        friend std::istream& operator>>(std::istream& is, Hexagon& hex);
        friend std::ostream& operator<<(std::ostream& os, Hexagon& hex);
        Hexagon& operator=(Hexagon& hex);
        bool operator==(Hexagon& hex);
};

#endif      // _HEXAGON_HPP_