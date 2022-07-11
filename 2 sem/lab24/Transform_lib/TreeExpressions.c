#include "TreeExpressions.h"
#include <ctype.h>

tr_SymNode* tr_CreateSymNode() {
    tr_SymNode* node = (tr_SymNode *) malloc(sizeof(tr_SymNode));

    return node; 
}
