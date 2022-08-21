work with lib:

That to use Transform_lib for the tree expressions need to include "include/TransformToTree.h". This header has necessary functions and structures. The lib can apply input the numbers/char \\ `//* char is one-symbol variable` Example: `43*a+43*b`. 

Compile: `make build`
RUN: `make run`
CLean: `make clean`

Example usage in file `src/main.c` (U can to use this file for your code):
```C
#include "../include/TransformToTree.h"

int main(void) {
    tr_vector* string = NULL;       // The definition tr_vector* for string expression
    tr_header tree;                 // The head of our tree

    tr_SetHeadNode(&tree);          // Init tree
    string = tr_CollectNewVector(); // Collect new expression from stdin to vector
    // Now the @string contain all expression from stdin 
    // tr_PrintVector(string);
    tr_CreateTransformedTree(string, &tree);    // Based on @string create tree expressions
    tr_OutputNormalFormat(&tree);       // output expression in line
    tr_PrintTreeFormat(&tree);          // output tree format

    tr_ClearVector(string, 1);          // destroy vetor
    tr_ClearTree(&tree);                // destroy tree
    return 0;
}
```
intput: `a+23*c+536+12+43*431*42+23+4*b`
output: 
```C
a + 23 * c + 536 + 12 + 43 * 431 * 42 + 23 + 4 * b      // The normal format 

// Tree format
                b
        *
                4
+
                23
        +
                                        42
                                *
                                        431
                        *
                                43
                +
                                12
                        +
                                        536
                                +
                                                        c
                                                *
                                                        23
                                        +
                                                a
```
                                    

