#include <iostream>

#include "hexagon.hpp"
#include "TNaryTree.hpp"

int main() {
    TNaryTree tree;
    Hexagon hex;

    std::cin >> hex;
    tree.Update(hex, "");

    std::cin >> hex;
    tree.Update(hex, "c");

    std::cin >> hex;
    tree.Update(hex, "cb");

    std::cin >> hex;
    tree.Update(hex, "cbb");

    std::cout << tree;

    return 0;
}