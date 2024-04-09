#ifndef RECURS_DESCENT
#define RECURS_DESCENT

#include "front.h"

struct Position_t {
    char *data = nullptr;
    int index = 0;
};

enum Mode_t {
    MODE_ADD_SUB = 1,
    MODE_MUL_DIV = 2
};

Node_t *Get_Number       ( struct Position_t *position );
Node_t *Get_Expression   ( struct Position_t *position );
Node_t *Get_Term         ( struct Position_t *position );
Node_t *Get_Partititon   ( struct Position_t *position );
Node_t *Get_Index        ( struct Position_t *position );
Node_t *Get_Negative_Num ( struct Position_t *position );
Node_t *Get_Power        ( struct Position_t *position );
Node_t *Get_General      ( char *buffer, struct Node_t *tree_node );

int Get_Binary_Element ( int sign, enum Mode_t mode );

#endif      // RECURS_DESCENT
