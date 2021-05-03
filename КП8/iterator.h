
#include "lists.h"

typedef struct _iterator {

list_node *node;

} iterator;

iterator* created(list* l);
void iterator_next(iterator* it);
void iterator_back(iterator* it);
list_node* iteratorGet(iterator* it);
