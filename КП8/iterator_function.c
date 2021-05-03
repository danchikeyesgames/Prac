#include <stdio.h>
#include "iterator.h"

iterator* created(list* l) {
    iterator* it = (iterator *) malloc(sizeof(iterator));
    it->node = l->head;
    return it;
}

void iterator_next(iterator* it) {
    if (it->node->next->next)
        it->node = it->node->next;
    else
        printf("This last\n");
}

void iterator_back(iterator* it) {
    if (it->node->prev)
        it->node = it->node->prev;
    else
        printf("This head\n");
}

list_node* iteratorGet(iterator* it) {
    return it->node;
}

void iterator_print(iterator* it, list* l) {
    //printf("%-5c", '^');
    list_node* ll = l->head;
    int count = 0;
    while (ll != it->node) {
        count++;
        ll = ll->next;
    }
    printf("%*c\n", count*7 - count + 1, '^');
}

iterator* update(list_node* ll) {
    iterator* it;
    it->node = ll;
    return it;
}