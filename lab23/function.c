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

tree *destroy(tree *list, int data) {
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
        printf("remove %d finished\n", list->data);
        list = NULL;
        free(list);
    //2
    } else if (child->left == NULL && child->right == NULL) {
        if (parent->left == child) {
            printf("remove %d finished\n", parent->left->data);
            parent->left = NULL;
            free(parent->left);
        } else {
            printf("remove %d finished\n", parent->right->data);
            parent->right = NULL;
            free(parent->right);
        }
    //3
    } else if (child->left == NULL && child->right != NULL) {
        if (list->data == data) {
            printf("remove %d finished\n", list->data);
            list = list->right;
            free(child);
        } else if (parent->left == child) {
            printf("remove %d finished\n", parent->left->data);
            parent->left = child->right;
            free(child);
        } else {
            printf("remove %d finished\n", parent->right->data);
            parent->right = child->right;
            free(child);
        }
    } else if (child->right == NULL && child->left != NULL) {
        if (list->data == data) {
            list = list->left;
            printf("remove %d finished\n", list->data);
            free(child);
        } else if (parent->left == child) {
            printf("remove %d finished\n", child->data);
            parent->left = child->left;
            free(child);
        } else {
            printf("remove %d finished\n", child->data);
            parent->right = child->left;
            free(child);
        }
    //4
    } else if (child->left != NULL && child->right != NULL) {
        if (list->data == data) {
            tree *next = found_next_tree(list);
            int rose = next->data;
            printf("%d change %d\n",rose, child->data);
            destroy(list,next->data);
            list->data = rose;
        } else {
            tree *next = found_next_tree(child);
            int rose = next->data;
            printf("%d change %d\n",rose, child->data);
            destroy(list,next->data);
            child->data = rose;
        }
    }

    return list; 
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