#ifndef _OCTAGON_HPP_
#define _OCTAGON_HPP_

#include "figure.hpp"

class Octagon : public Figure {
    public:
        Octagon(std::istream& in);
        size_t  VertexNumber();
        double  Area();
        void    Print(std::ostream& os);
    private:
        Point p[8];
};

#endif      // _OCTAGON_HPP_