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
        
        if (!ll) {
            
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
    list_node* deleted = ll->prev;
    
    if (!ll->prev) {
        l->head = ll->next;
        ll->next->prev = NULL;
        free(ll);
    } else {
        ll->prev->next = ll->next;
        ll->next->prev = ll->prev;
        free(ll);
    }

}

void print(list* l) {

    list_node* ll = l->head;
    if (ll) {
        while (ll->next) {
            printf("%d --> ", ll->data);
            ll = ll->next;
        }
        printf("NULL");
        printf("\n");
    }
}