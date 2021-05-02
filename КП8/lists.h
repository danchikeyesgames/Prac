
typedef struct _lists list;
typedef struct _list_node list_node;

struct _lists {
    list_node* head;
};

struct _list_node {
    char data;
    list_node* prev;
    list_node* next;
};

list create();
void add(list* l, list_node* ll, char c);