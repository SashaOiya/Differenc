#ifndef RECURS_DESCENT
#define RECURS_DESCENT

#include "front.h"

struct Position_t {
    char *data = nullptr;
    int index = 0;
};

Node_t *Get_Number ( struct Position_t *Position );
Node_t *GetG ( char *buffer, struct Node_t *Tree );
Node_t *GetE ( struct Position_t *Position );
Node_t *GetT  ( struct Position_t *Position );
Node_t *GetP  ( struct Position_t *Position );
Node_t *GetId ( struct Position_t *Position );
Node_t *GetId ( struct Position_t *Position );

#endif      // RECURS_DESCENT
