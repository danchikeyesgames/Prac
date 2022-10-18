#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_

#include <iostream>
#include "point.hpp"

class Figure {
    public:
        virtual size_t  VertexNumber() = 0;
        virtual double  Area() = 0;
        virtual void    Print(std::ostream& os) = 0;
    protected:
        uint numvertex;
};

#endif      // _FIGURE_HPP_