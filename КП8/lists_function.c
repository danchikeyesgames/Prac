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
            tail->prev = NULL;
            l->head = node;
            node->prev = NULL;
            node->next = tail;

        } else if (ll->next == NULL)
        printf("Can't add lists. Pls, Delete NULL\n");
        else {

            node->prev = ll;
            node->next = ll->next;
            ll->next->prev = node;
            ll->next = node;

        }
}

void delete(list* l, list_node* ll) {
    list_node* deleted = ll->prev;
    list_node* nexus = ll->next;
    if (ll->prev == NULL && ll->next == NULL) {
        l->head = NULL;
        free(ll);
    } else if (!ll->prev) {
        l->head = ll->next;
        ll->next->prev = NULL;
        free(ll);
    } else {
        deleted->next = ll->next;
        nexus->prev = deleted;
        free(ll);
    }

}

void print(list* l) {

    list_node* ll = l->head;
    if (ll) {
        while (ll->next) {
            printf("%c --> ", ll->data);
            ll = ll->next;
        }
        printf("NULL");
        printf("\n");
    }
}

int foo(list* l, char data) {
    _Bool isTrue = 0; 
    list_node* detected = l->head;

    while (detected->next != NULL) {
        if (detected->data == data) {
            isTrue = 1;
            break;
        }
        detected = detected->next;
    }
    
    detected = l->head;
    
    if (isTrue) {
        
        while (detected->next != NULL) {
            delete(l,detected);
            detected = detected->next;
        }
        printf(">>>>>>>>>>CLEAR<<<<<<<<<\n");
        return 1;
    } else
        printf("Not found\n");
    return 0;
}