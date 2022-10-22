#include "TNaryTree.hpp"

TNaryTree::TNaryTree() {
    size = 3;
    root = nullptr;
}

TNaryTree::TNaryTree(int n) {
    size = n;
    root = nullptr;
}

void TNaryTree::Update(Hexagon& polygon, const std::string& tree_path) {
    int i = 0;
    ItemTree* tmp = root;

    if (root == nullptr) {
        root = new ItemTree;
        root->brother = nullptr;
        root->current_size = 0;
        root->son = nullptr;
        new (&root->figure) Hexagon(polygon);
        tmp = root;
    }
    
    while (tree_path[i] != '\0') {
        if (tree_path[i] == 'c') {
            if (size < tmp->current_size + 1) {
                throw std::out_of_range("Tree is overflow\n");
            }

            if (!tmp->son && tree_path[i + 1] != '\0') {
                throw std::invalid_argument("Vertex doesn't exist in the path\n");
            }

            if (!tmp->son && tree_path[i + 1] == '\0') {
                tmp->son = new ItemTree;
                tmp->son->brother = nullptr;
                tmp->son->current_size = tmp->current_size + 1;
                tmp->son->son = nullptr;
            }

            tmp = tmp->son;
        } else if (tree_path[i] == 'b') {
            if (!tmp->brother && tree_path[i + 1] != '\0') {
                throw std::invalid_argument("Vertex doesn't exist in the path\n");
            }

            if (!tmp->brother && tree_path[i + 1] == '\0') {
                tmp->brother = new ItemTree;
                tmp->brother->brother = nullptr;
                tmp->brother->current_size = tmp->current_size;
                tmp->brother->son = nullptr;
            }

            tmp = tmp->brother;
        }

        ++i;
    }

    tmp->figure = polygon;
    ++size;
}

const Hexagon& TNaryTree::GetItem(const std::string& tree_path) {
    int i = 0;
    ItemTree* tmp = root;
    
    while (tree_path[i] != '\0') {
        if (tree_path[i] == 'c') {
            if (!tmp->brother) {
                throw std::invalid_argument("Vertex doesn't exist in the path\n");
            }
            
            tmp->son;
        } else if (tree_path[i] == 'b') {
            if (!tmp->son) {
                throw std::invalid_argument("Vertex doesn't exist in the path\n");
            }

            tmp->brother;
        }

        ++i;
    }

    return tmp->figure;
}

void TNaryTree::RemoveSubTree(const std::string& tree_path) {
    int i = 0;
    ItemTree* tmp = root;
    
    while (tree_path[i] != '\0') {
        if (tree_path[i] == 'c') {
            if (!tmp->brother) {
                throw std::invalid_argument("Vertex doesn't exist in the path\n");
            }
            
            tmp->son;
        } else if (tree_path[i] == 'b') {
            if (!tmp->son) {
                throw std::invalid_argument("Vertex doesn't exist in the path\n");
            }

            tmp->brother;
        }

        ++i;
    }

    delete_node(tmp);
}

bool TNaryTree::Empty() {
    return size == 0 ? 1 : 0;
}

void TNaryTree::Print(ItemTree* t) const {
    std::cout << t->figure.Area();

    if (t->son) {
        std::cout << ": [";
        Print(t->son);
    }

    if (t->brother) {
        std::cout << ", ";
        Print(t->brother);
    }

    std::cout << "]";
}

std::ostream& operator<<(std::ostream& os, const TNaryTree& tree) {
    os << tree.root->figure.Area() << ": [";

    tree.Print(tree.root->son);
    os << "\n";

    return os; 
}

TNaryTree::~TNaryTree() {
    delete_node(root);
}

void TNaryTree::delete_node(ItemTree* t) {
    if (t->son) {
        delete_node(t->son);
    }

    if (t->brother) {
        delete_node(t->brother);
    }

    delete t;
}