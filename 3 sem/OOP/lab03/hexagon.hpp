#ifndef _HEXAGON_HPP_
#define _HEXAGON_HPP_

#include "figure.hpp"

class Hexagon : public Figure {
    public:
        Hexagon(std::istream& in);
        size_t  VertexNumber();
        double  Area();
        void    Print(std::ostream& os);
    private:
        Point p[6];
};

#endif      // _HEXAGON_HPP_