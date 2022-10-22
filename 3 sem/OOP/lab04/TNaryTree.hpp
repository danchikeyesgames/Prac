#ifndef _TNARYTREE_HPP_
#define _TNARYTREE_HPP_

#include <string>

#include "hexagon.hpp"

class TNaryTree {
    private:
        struct ItemTree {
            ItemTree* son;
            ItemTree* brother;
            Hexagon figure;
            int current_size;

            ItemTree() {}
        };

    public:
        TNaryTree();
        TNaryTree(int n);
        void Update(Hexagon& polygon, const std::string& tree_path = "");
        const Hexagon& GetItem(const std::string& tree_path = "");
        void RemoveSubTree(const std::string& tree_path);
        bool Empty();

        friend std::ostream& operator<<(std::ostream& os, const TNaryTree& tree);
        virtual ~TNaryTree();

    private:
        int size;
        ItemTree* root;

        void delete_node(ItemTree* t);
        void Print(ItemTree* t) const;
};


#endif      // _TNARYTREE_HPP_