#include <iostream>

#include "hexagon.hpp"
#include "TNaryTree.hpp"

int main() {
    TNaryTree tree;
    Hexagon hex;

    std::cin >> hex;
    tree.Update(hex, "");

    hex = Hexagon(Point(23, 12), Point(4, 12), Point(63, 1), Point(35, 65), Point(12, 53), Point(27, 13));
    tree.Update(hex, "c");

    std::cout << tree;

    return 0;
}