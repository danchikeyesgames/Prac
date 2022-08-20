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
static void Print_Tree_Format(tr_SymNode* head, int i);

void tr_CreateTransformedTree(tr_vector* input, tr_header* head) {
    state stat      = ONE;
    tr_vector* v    = vec_CreateVector();                   // vector with number make up char type
    char sym        = 0;
    int  number     = 0;
    char sign       = 0;       // sign symbol from string
    char alpha_sym  = 0;
    tr_SymNode* CurrentNode = head->start;

    sym = vec_take_item(input);
    while (sym != '\0') {
        tr_SymNode* NewNodeSign = NULL;
        tr_SymNode* NewNodeNum  = NULL;
        tr_SymNode* NewNodeSym  = NULL;

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
                    sign = sym;
                    stat = FOUR;
                    continue;
                }
                break;
            case THREE:
                if (IsSymExp(sym)) {
                    sign = sym;
                    stat = FIVE;
                    continue;
                }
                break;
            case FOUR:
                NewNodeSign = tr_CreateSymNode();
                NewNodeNum  = tr_CreateSymNode();

                number = vec_ToInt(v);
                vec_StringClear(v);
                tr_SetNodeOperand(NewNodeSign, sign);
                tr_SetNodenumber(NewNodeNum, number);
                
                if (CurrentNode == NULL) {
                    head->start = NewNodeSign;
                    CurrentNode = head->start;
                    tr_InsertLeftSide(NewNodeNum, CurrentNode);
                    
                    stat = ONE;
                } else {
                    if (sign == '*' || sign == '/') {
                        tr_InsertRightExpr(NewNodeSign, CurrentNode);
                        CurrentNode = NewNodeSign;
                        tr_InsertLeftSide(NewNodeNum, CurrentNode);
                        stat = ONE;
                    } else if (sign == '+' || sign == '-') {
                        tr_InsertRightExpr(NewNodeNum, CurrentNode);
                        // CurrentNode->right = NewNodeNum;
                        // NewNodeNum->parent = CurrentNode;
                        tr_InsertUpSide(NewNodeSign, head->start);
                        head->start = NewNodeSign;
                        CurrentNode = NewNodeSign;

                        stat = ONE;
                    }
                }
                break;

            case FIVE:
                NewNodeSign = tr_CreateSymNode();
                NewNodeSym  = tr_CreateSymNode();

                tr_SetNodeOperand(NewNodeSign, sign);
                tr_SetNodeSymbol(NewNodeSym, alpha_sym);
                
                if (CurrentNode == NULL) {
                    head->start = NewNodeSign;
                    CurrentNode = head->start;
                    tr_InsertLeftSide(NewNodeSym, CurrentNode);

                    stat = ONE;
                } else {
                    if (sign == '*' || sign == '/') {
                        tr_InsertRightExpr(NewNodeSign, CurrentNode);
                        CurrentNode = NewNodeSign;
                        tr_InsertLeftSide(NewNodeSym, CurrentNode);
                        stat = ONE;
                    } else if (sign == '+' || sign == '-') {
                        CurrentNode->right = NewNodeSym;
                        NewNodeSym->parent = CurrentNode;
                        tr_InsertUpSide(NewNodeSign, head->start);
                        head->start = NewNodeSign;
                        CurrentNode = NewNodeSign;
                        stat = ONE;
                    }
                }
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
    } else if (stat == THREE) {
        tr_SymNode* NewNode = tr_CreateSymNode();
        tr_SetNodeSymbol(NewNode, alpha_sym);
        CurrentNode->right = NewNode;
        NewNode->parent = CurrentNode;
    }
}

void tr_OutputNormalFormat(tr_header* head) {
    if (head->start) {
        PrintTree(head->start->left);
        printf("%c ", head->start->value.operand);
        PrintTree(head->start->right);
    } else {
        printf("-\n");
    }
    printf("\n");
}

void tr_PrintTreeFormat(tr_header* head) {
    Print_Tree_Format(head->start, 0);
}

// Collect new vector of char from stdin
tr_vector* tr_CollectNewVector() {            // for stdin input
    tr_vector* v = vec_CreateVector();
    char sym = 0;

    while ((sym = getchar()) != '\n') {
        vec_add_item(v, sym);
    }

    return v;
}

void tr_PrintVector(tr_vector* v) {
    char c;
    int i = 0;
    while ((c = v->Item[i]) != '\0') {
        printf("%c", c);
        ++i;
    }
    printf("\n");
}

// type = 0 => clear only string in heap || type = 1 => destroy vector
void tr_ClearVector(tr_vector* v, unsigned int type) {   
    if (type == 0) vec_StringClear(v);
    else if (type == 1) vec_ClearVec(v);
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
        if (node->flag == 0) printf("%d ", node->value.number);
        if (node->flag) printf("%c ", node->value.operand);
    } else {
        printf("%c ", node->value.operand);
    }

    if (node->right) PrintTree(node->right);
}

static void Print_Tree_Format(tr_SymNode* head, int i) {
    if (head->right != NULL) {
        Print_Tree_Format(head->right, i + 1);
    }
    
    for (int j = 0; j < i; j++) {
        printf("\t");
    }
    if (head->left == NULL || head->right == NULL) {
        if (head->flag == 0) printf("%d\n", head->value.number);
        else printf("%c\n", head->value.operand);
    } else {
        printf("%c\n", head->value.operand);
    }
    
    if (head->left != NULL) {
        Print_Tree_Format(head->left, i + 1);
    }
}
