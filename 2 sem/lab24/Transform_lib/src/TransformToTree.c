#include "../include/TransformToTree.h"
#include "../include/private/VectorPrivate.h"
#include "../include/private/TreeExpressions.h"
#include <stdio.h>
#include <ctype.h>

typedef enum _State {
    ONE, TWO, THREE, FOUR, FIVE
} state;

static int IsSymExp(char c);
static void PrintTree(tr_SymNode* node);

void tr_CreateTransformedTree(tr_vector* input, int max, tr_header* head) {
    state stat      = ONE;
    tr_vector* v    = vec_CreateVector();                   // vector with number make up char type
    char sym        = 0;
    int number      = 0;
    char znak       = 0;       // English??
    char alpha_sym  = 0;
    tr_SymNode* CurrentNode = head->start;

    sym = vec_take_item(input);
    while (sym != '\0') {
        switch(stat) {
            case ONE:
                if (IsSymExp(sym)) {
                    if (isdigit(sym)) {
                        vec_add_item(v, sym);
                        stat = TWO;
                    } else if (isalpha(sym)) {
                        alpha_sym = sym;
                        stat = THREE;
                    }
                } else if (sym = ' ') {
                    break;
                } else {
                    printf("Incorrected format\npls use alpha & digit & symbols of +, =, -, *, /.\n");
                    return;
                }
                break;
            case TWO:
                if (isdigit(sym)) {
                    vec_add_item(v, sym);
                } else if (IsSymExp(sym)) {
                    znak = sym;
                    stat = FOUR;
                    continue;
                }
                break;
            case THREE:
                if (IsSymExp(sym)) {
                    znak = sym;
                    stat = FIVE;
                    continue;
                }
                break;
            case FOUR:
                tr_SymNode* NewNodeZnak = tr_CreateSymNode();
                tr_SymNode* NewNodeNum = tr_CreateSymNode();

                number = vec_ToInt(v);
                vec_StringClear(v);
                tr_SetNodeOperand(NewNodeZnak, znak);
                tr_SetNodenumber(NewNodeNum, number);
                
                if (CurrentNode == NULL) {
                    head->start = NewNodeZnak;
                    NewNodeZnak->left = NewNodeNum;
                    NewNodeNum->parent = NewNodeZnak;
                    CurrentNode = head->start;
                    stat = ONE;
                } else {
                    if (znak == '*' || znak == '/') {
                        tr_InsertRightExpr(NewNodeZnak, CurrentNode);
                        CurrentNode = NewNodeZnak;
                        CurrentNode->left = NewNodeNum;
                        NewNodeNum->parent = CurrentNode;
                        stat = ONE;
                    } else if (znak == '+' || znak == '-') {
                        CurrentNode->right = NewNodeNum;
                        NewNodeNum->parent = CurrentNode;
                        tr_InsertUpSide(NewNodeZnak, head->start);
                        CurrentNode = head->start;
                        stat = ONE;
                    }
                }


                break;

            case FIVE:
                break;
        }
        sym = vec_take_item(input);
    }

    if (stat == TWO) {
        tr_SymNode* NewNode = tr_CreateSymNode();
        number = vec_ToInt(v);
        vec_ClearVec(v);
        tr_SetNodenumber(NewNode, number);
        CurrentNode->right = NewNode;
        NewNode->parent = CurrentNode;
    }
}

void tr_OutputNormalFormat(tr_header* head) {
    if (head->start) {
        PrintTree(head->start->left);
        printf(" %c ", head->start->value.operand);
        PrintTree(head->start->right);
    } else {
        printf("-\n");
    }
}

tr_vector* tr_CollectNewVector() {            // for stdin input
    tr_vector* v = vec_CreateVector();
    char sym = 0;
    // state stat = ONE;

    while ((sym = getchar()) != '\n') {
        vec_add_item(v, sym);
    }

}

void tr_PrintVector(tr_vector* v) {
    char c;
    while ((c = vec_take_item(v)) != '\0') {
        printf("%c", c);
    }
}

//------------static-functions---------------------

//+++++++++++++++++++++++++++++++++++++++++++++++++

static int IsSymExp(char c) {
    if (isdigit(c)) {
        return 1;
    } else if (isalpha(c)) {
        return 1;
    } else if (c == '*' || c == '/' || c == '=' || c == '-' || c == '+' || c == '(' || c == ')') {
        return 1;
    }
}

static void PrintTree(tr_SymNode* node) {
    if (node->left) PrintTree(node->left);

    if (node->left == NULL || node->right == NULL) {
        printf(" %d ", node->value.number);
    } else {
        printf(" %c ", node->value.operand);
    }

    if (node->right) PrintTree(node->right);
}