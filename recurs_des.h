#ifndef RECURS_DESCENT
#define RECURS_DESCENT

#include "front.h"

struct Position_t {
    char *data = nullptr;
    int index = 0;
};

Node_t *Get_Number ( struct Position_t *position );
Node_t *Get_General ( char *buffer, struct Node_t *tree_node );
Node_t *Get_Expression ( struct Position_t *position );
Node_t *Get_Term  ( struct Position_t *position );
Node_t *Get_Partititon   ( struct Position_t *position );
Node_t *Get_Index ( struct Position_t *position );

#endif      // RECURS_DESCENT
