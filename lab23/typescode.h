typedef struct _tree {
    int data;
    struct _tree *left;
    struct _tree *right;
} tree;

tree *create_tree(int value);

void *add_tree(tree *parent, int child);

tree *found_next_tree(tree *yet);

tree *destroy(tree *list, int data);

void *print_Tree(tree * p,int level);

int counter(tree *troy);

tree *found(tree *poptree,int data);