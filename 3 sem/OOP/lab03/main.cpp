#include <iostream>

#include "hexagon.hpp"
#include "triangle.hpp"
#include "octagon.hpp"

int main() {
    std::cout << "Hexagon:\n";
    Hexagon hex(std::cin);
    std::cout << "Area: " << (double) hex.Area()  << "\n";
    std::cout << "NumVertex: " << hex.VertexNumber() << "\n";

    std::cout << "Octagon:\n";
    Octagon oct(std::cin);
    std::cout << "Area: " << (double) oct.Area()  << "\n";
    std::cout << "NumVertex: " << oct.VertexNumber() << "\n";

    std::cout << "Triangle:\n";
    Triangle tri(std::cin);
    std::cout << "Area: " << (double) tri.Area()  << "\n";
    std::cout << "NumVertex: " << tri.VertexNumber() << "\n";

    hex.Print(std::cout);
    oct.Print(std::cout);
    tri.Print(std::cout);

    return 0;
}