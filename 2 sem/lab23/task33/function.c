#include "function.h"

static node* FindNode(node* root, int key);
static node* FindNextItem(node* _node);

node * CreateTree(int value) {
    node * tmp = (node *) malloc(sizeof(node));
    tmp->key = value;
    tmp->left = tmp->right = NULL;
    return tmp;
}

node * InsertTree(node* root, int value) {
    node * tmp = root;
    node * parent = NULL;
    
    while (tmp != NULL) {
        parent = tmp;
        if (value == tmp->key)
            break;
        else if (value > tmp->key)
            tmp = tmp->right;
        else if (value < tmp->key)
            tmp = tmp->left;
    }

    if (!tmp) {
        tmp = CreateTree(value);     
        if (parent->key > tmp->key)
            parent->right = tmp;
        if (parent->key < tmp->key)
            parent->left = tmp;
    }

    return tmp;
}

void PrintTree(node* root, int level) {
    if (root) {
        PrintTree(root->right, level + 1);
        for (int i = 0; i < level; i++) printf('\t');
        printf("%d\n", root->key);
        PrintTree(root->left, level + 1);
    }
}

void DestroyTree(node* root) {
    if (root) {
        DestroyTree(root->right);
        DestroyTree(root->left);
        free(root);
        if (root)
            root = NULL;
    }
}

int AmountVertex(node* root) {
    if (root) {
        int count = AmountVertex(root->left) + AmountVertex(root->right);

        if (root->left != NULL && root->right != NULL)
            count += 1;
        
        return count;    
    } else
        return 0;
}

void DeleteNode(node* root, int key) {
    // what this?
}

static node * FindNode(node* root, int key) {
    node * tmp = root;
    node * parent = NULL;

    while (tmp != NULL) {
        parent = tmp;
        if (key == tmp->key)
            break;
        else if (key > tmp->key)
            tmp = tmp->right;
        else if (key < tmp->key)
            tmp = tmp->left;
    }

    root = parent;
    return tmp;
}

static node * FindNextItem(node* _node) {
    node * tmp = _node->right;

    while (tmp->left != NULL)
        tmp = tmp->left;
    
    return tmp;
}