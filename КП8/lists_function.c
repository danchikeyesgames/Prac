#include <stdio.h>
#include "lists.h"

list* create() {
    list* l;
    l = (list*) malloc(sizeof(list));
    l->head = NULL;
    return l;
}

void add(list* l, list_node* ll, char c) {
        
        list_node* node = (list_node*) malloc(sizeof(list_node));
        node->data = c;
        
        if (!(l->head)) {
            
            list_node* tail;
            tail = (list_node*) malloc(sizeof(list_node));
            tail->next = NULL;
            l->head = node;
            node->prev = NULL;
            node->next = tail;

        } else {

            node->prev = ll;
            node->next = ll->next;
            ll->next = node;

        }
}

void delete(list* l, list_node* ll) {
    
}

