#include "stack.h"

static void stack_delete(stack* head);
static void ClearNode(stack_node* s);

stack* stack_create() {
    stack* tmp = (stack *) malloc(sizeof(stack));
    tmp->head = NULL;
    tmp->size = 0;

    return tmp;
}

stack_node* stack_node_create(unsigned int key, int value) {
    stack_node* tmp = (stack_node *) malloc(sizeof(stack_node));
    tmp->key = key;
    tmp->value = value;
    tmp->next = NULL;

    return tmp;
}

stack_node* stack_pop(stack* head) {
    if (head->head == NULL)
        return NULL;

    stack_node* value = head->head;
    stack_delete(head);
    head->size -= 1;

    return value;
}

void stack_push(stack* head, unsigned int key, int value) {
    stack_node* tmp = head->head;
    stack_node* new_node = stack_node_create(key, value);
    head->head = new_node;
    new_node->next = tmp;
    head->size += 1;
}

void stack_push_node(stack* head, stack_node* node) {
    stack_node* tmp = head->head;
    head->head = node;
    node->next = tmp;
    head->size += 1;
}

size_t stack_take_size(stack* head) {
    return head->size;
}

unsigned int stack_take_key(stack_node* node) {
    return node->key;
}

int stack_take_value(stack_node* node) {
    return node->value;
}

void stack_clear(stack* head) {
    if (head->head != NULL) ClearNode(head->head);
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
}

static void ClearNode(stack_node* s) {
    if (s->next != NULL) ClearNode(s->next);
    free(s);
}