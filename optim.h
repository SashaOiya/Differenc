#ifndef OPTIM
#define OPTIM

//#include "front.h"
#include <stdio.h>

#ifdef DEBUGG
#define $ printf ( "function <%s> line <%d>\n ", __PRETTY_FUNCTION__, __LINE__ );
#else
#define $
#endif

enum Node_Option_t {
    NODE_TYPE_NUM = 1,
    NODE_TYPE_OP  = 2,
    NODE_TYPE_VAR = 3
};

struct Node_t {
    int value = 0;
    Node_Option_t type;
    Node_t *left     = 0;
    Node_t *right    = 0;
};

int  Optimization_Const  ( struct Node_t **tree_node );
int  Optimization_Option ( struct Node_t **tree_node );
void Optimization        ( struct Node_t *tree_node );

#endif  // OPTIM
