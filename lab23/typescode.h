typedef struct _tree {
    int data;
    struct _tree *left;
    struct _tree *right;
} tree;

tree *create_tree(int value);

void *add_tree(tree *parent, int child);

tree *found_next_tree(tree *yet);

void *destroy(tree *list, int data);

void *print_Tree(tree * p,int level);

int counter(tree *troy);

tree *found_parent(tree *poptree,int data, int child);

tree *found(tree *poptree,int data);