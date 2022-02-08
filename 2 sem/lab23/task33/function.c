#include "function.h"

static node* FindNode(node* root, int key);
static node* FindNextItem(node* _node);
static node* FindParent(node*, int);

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
        else if (tmp->key > value)
            tmp = tmp->left;
        else if (tmp->key < value)
            tmp = tmp->right;
    }

    if (!tmp) {
        tmp = CreateTree(value);     
        if (parent->key < tmp->key)
            parent->right = tmp;
        if (parent->key > tmp->key)
            parent->left = tmp;
    }

    return tmp;
}

void PrintTree(node* root, int level) {
    if (root != NULL) {
        PrintTree(root->right, level + 1);
        for (int i = 0; i < level; i++) printf("\t");
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
    node* _node = FindNode(root, key);
    node* parent = FindParent(root, key);
    node* tmp = NULL;
    node* next_node = NULL;
    int value = 0;

    if (_node == NULL) {
        printf("Not find this ->%d<- element\n", key);
        return;
    }

    if (parent == NULL && _node->left == _node->right) {
        printf("Root %d remove from tree\n", root->key);
        free(root);
        if (root)
            root = NULL;
    }

    // 1: lists
    else if (!_node->left && !_node->right) {
        printf("Node %d remove from tree\n", _node->key);
        if (parent->key > key) {
            free(_node);
            parent->left = NULL;
        } else if (parent->key < key) {
            free(_node);
            parent->right = NULL;
        }
    }
    // 2: have one child
    else if (_node->left && !_node->right) {
        printf("Node %d remove from tree\n", _node->key);
        if (parent->left->key == key) {
            tmp = _node->left;
            free(_node);
            parent->left = tmp;
        } else if (parent->right->key == key) {
            tmp = _node->left;
            free(_node);
            parent->right = tmp;
        }
    } else if (!_node->left && _node->right) {
        printf("Node %d remove from tree\n", _node->key);
        if (parent->left->key == key) {
            tmp = _node->right;
            free(_node);
            parent->left = tmp;
        } else if (parent->right->key == key) {
            tmp = _node->right;
            free(_node);
            parent->right = tmp;
        }
    }
    // 3: have two child
    else if (_node->left && _node->right) {
        printf("Node %d remove from tree\n", _node->key);
        next_node = FindNextItem(_node);
        value = next_node->key;
        DeleteNode(root, value);
        _node->key = value;
    }

}

static node * FindNode(node* root, int key) {
    node * tmp = root;

    while (tmp != NULL && tmp->key != key) {
        if (key > tmp->key)
            tmp = tmp->right;
        else if (key < tmp->key)
            tmp = tmp->left;
    }

    return tmp;
}

static node* FindParent(node* root, int key) {
    node * tmp = root;
    node * parent = NULL;

    while (tmp != NULL && tmp->key != key) {
        parent = tmp;

        if (key > tmp->key)
            tmp = tmp->right;
        else if (key < tmp->key)
            tmp = tmp->left;
    }

    return parent;
}

static node * FindNextItem(node* _node) {
    node * tmp = _node->right;

    while (tmp->left != NULL)
        tmp = tmp->left;
    
    return tmp;
}
