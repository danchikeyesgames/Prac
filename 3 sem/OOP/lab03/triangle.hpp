#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include "figure.hpp"

class Triangle : public Figure {
    public:
        Triangle(std::istream& in);
        size_t  VertexNumber();
        double  Area();
        void    Print(std::ostream& os);
    private:
        Point p[3];
};

#endif      // _TRIANGLE_HPP_