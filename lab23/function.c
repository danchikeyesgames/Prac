#include <stdio.h>
#include <stdlib.h>
#include "typescode.h"

tree *create_tree(int value) {
    tree *binartree = (tree *)malloc(sizeof(tree));
    binartree->data = value;
    binartree->left = NULL;
    binartree->right = NULL;
    return binartree;
}

void *add_tree(tree *parent, int child) {
    tree *binartree = create_tree(child);
    binartree->data = child;
    tree *last = parent;
    tree *free = NULL;
    while (last != NULL) {
        free = last;
        if (last->data > child) {
            last = last->left;
        } else if (last->data < child) {
            last = last->right;
        }
    }
    if (free->data > child) {
        free->left = binartree;
    } else if (free->data < child) {
        free->right = binartree;
    }
}

tree *found_next_tree(tree *yet) {
    tree *last = yet->right;
    while (last->left != NULL) {
        last = last->left;
    }
    return last;
}

void *destroy(tree *list, int data) {
    tree *parent = NULL;
    tree *child = list;

    while (child->data != data) {
        parent = child;
        if (child->data < data) {
            child = child->right;
        } else if (child->data > data) {
            child = child->left;
        }
    }
    //1
    if (list->left == NULL && list->right == NULL) {
        printf("/ not remove\n");
    //2
    } else if (child->left == NULL && child->right == NULL) {
        if (parent->left == child) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    //3
    } else if (child->left == NULL && child->right != NULL) {
        if (parent->left == child) {
            parent->left = child->right;
        } else {
            parent->right = child->right;
        }
    } else if (child->right == NULL && child->left != NULL) {
        if (parent->left == child) {
            parent->left = child->left;
        } else {
            parent->right = child->left;
        }
    //4
    } else if (child->left != NULL && child->right != NULL) {
        tree *next = found_next_tree(child);
        int rose = next->data;
        printf("%d change %d\nremove finished\n",rose, child->data);
        destroy(list,next->data);
        child->data = rose;
    }
    
}

void *print_Tree(tree * p,int level) {
    if(p != NULL) {
        print_Tree(p->right,level + 1);
        for(int i = 0;i < level;i++) printf("\t");
        printf( "%d\n",p->data);
        print_Tree(p->left,level + 1);
    }
}

int counter(tree *troy) {
    int i = 0;
    if (troy != NULL) {
        i = i + counter(troy->left);
        if (troy->left != NULL && troy->right != NULL ) {
            i++;
        }
        i = i + counter(troy->right);
    }
    return i;
}

tree *found_parent(tree *poptree,int data, int child) {
    tree *parent = poptree;
    while (parent != NULL) {
        if (parent->data < data && parent->data < child) {
            parent = parent->right;
        } else if (parent->data > data && parent->data > child) {
            parent = parent->left;
        } else if (parent->data == data) {
            return parent;
        } else {
            return NULL;
        }
    }
    return NULL;
}

tree *found(tree *poptree,int data) {
    tree *parent = poptree;
    while (parent != NULL) {
        if (parent->data < data) {
            parent = parent->right;
        } else if (parent->data > data) {
            parent = parent->left;
        } else if (parent->data == data) {
            return parent;
        } else {
            return NULL;
        }
    }
    return NULL;
}