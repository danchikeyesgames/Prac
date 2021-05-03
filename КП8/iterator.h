
#include "lists.h"

typedef struct _iterator {

list_node *node;

} iterator;

iterator* created(list* l);
void iterator_next(iterator* it);
void iterator_back(iterator* it);
list_node* iteratorGet(iterator* it);
void iterator_print(iterator* it, list* l);
iterator* update (list_node* ll);
