#include "stack.h"

static void stack_delete(stack* head);

stack* stack_create() {
    stack* tmp = (stack *) malloc(sizeof(stack));
    tmp->head = NULL;
    tmp->size = 0;

    return tmp;
}

stack_node* stack_node_create(unsigned int key) {
    stack_node* tmp = (stack_node *) malloc(sizeof(stack_node));
    tmp->key = key;
    tmp->key = NULL;

    return tmp;
}

unsigned int stack_pop(stack* head) {
    unsigned int value = head->head->key;
    stack_delete(head);

    return value;
}

void stack_push(stack* head, unsigned int key) {
    stack_node* tmp = head->head;
    stack_node* new_node = stack_node_create(key);
    head->head = new_node;
    new_node->next = tmp;
}

size_t stack_take_size(stack* head) {
    return head->size;
}

void stack_clear(stack* head) {
    ClearNode(head->head);
}

void stack_destroy(stack* head) {
    stack_clear(head);
    free(head);
}

// -------------------STATIC-FUNCTIONS-------------------

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

static void stack_delete(stack* head) {
    stack_node* tmp = head->head;
    head->head = head->head->next;
    free(tmp);
}

static void ClearNode(stack_node* s) {
    if (s->next != NULL) ClearNode(s->next);
    free(s);
}