#ifndef FRONT_END
#define FRONT_END

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "log.h"

#ifdef DEBUGG
#define $ printf ( "function <%s> line <%d>\n ", __PRETTY_FUNCTION__, __LINE__ );
#else
#define $
#endif

enum Node_Type_t {
    NODE_TYPE_NUM = 1,
    NODE_TYPE_OP  = 2,
    NODE_TYPE_VAR = 3
};

enum Option_t {
    OP_ADD    = '+',  // +
    OP_SUB    = '-',  // -
    OP_DIV    = '/',  // /
    OP_MUL    = '*',  // *
    OP_VAR    = 'x',  // x
    OP_BRA    = '(',  // (
    OP_CL_BRA = ')',  // )
    OP_POW    = '^',  // ^
    OP_SIN    = 's',  // sin
    OP_COS    = 'c',  // cos
    OP_TG     = 't',  // tg
    OP_CTG    = 'g'   // ctg
};

struct Node_t {
    int value = 0;
    Node_Type_t type;
    Node_t *left     = 0;
    Node_t *right    = 0;
};

struct Tree_t {
    Node_t *start_node = nullptr;
    double value = 0;
    //Array
};

enum Errors_t {
    OK_TREE     = 0,
    ERR_FREAD   = 1,
    ERR_INPUT   = 2,
    ERR_FOPEN   = 3,
    ERR_RLINE   = 4,
    ERR_CALLO   = 5,
    ERR_CYCLE   = 6,
    ERR_CTYPE   = 7,
    OK_FILE     = 8,
    OK_OCCURR   = 9,
    VAR_FOUND   = 10,
    VAR_N_FOUND = 11
};

struct File_t {
    char *file_name = nullptr;
    FILE *front_f = nullptr;
    char *out_buffer = nullptr;
    int file_size = 0;
};

void        Tree_Dump_Body  ( const struct Node_t *tree, FILE *tree_dump );
void        Tree_Text_Dump  ( const struct Node_t *tree_node );
Errors_t    Tree_Graph_Dump ( const struct Node_t *tree );
const char *Get_Op_Name     ( int op_type );

double   Eval       ( const struct Node_t *node );
double   Eval_Body  ( const struct Node_t *node, const int var_value );
Errors_t Search_Var ( const struct Node_t *node );

char *   File_Skip_Spaces ( char *data, int file_size );
Errors_t File_Reader      ( struct File_t *File );
Errors_t Diff_Tree_Ctor   ( struct File_t *file, struct Tree_t *tree, char *open_file );
void     Diff_Tree_Dtor   ( struct File_t *file, struct Tree_t *tree );

int  Optimization_Const  ( struct Node_t **tree_node );
int  Optimization_Option ( struct Node_t **tree_node );
void Optimization        ( struct Node_t *tree_node );

void    Node_Free   ( struct Node_t **tree_node );
Node_t *Copy_Node   ( const struct Node_t *tree );
Node_t *Create_Node ( Node_Type_t option, int value, struct Node_t *left, struct Node_t *right );

void Latex_Op         ( Node_t* node, FILE* latex_file);
void Put_Op           ( Node_t* node, FILE* latex_file);
void Print_Latex_Body ( Node_t* node, FILE* latex_file);
void Print_Latex      ( Node_t* node, FILE* latex_file );
void Put_Brackets     ( Node_t* node, FILE* latex_file, char bracket_type);

Node_t *Differentiation ( const struct Node_t *tree );
Node_t *Taylor_Body ( const struct Node_t *tree_node, const int number, const int var_val );
Node_t *Taylor ( const struct Node_t *tree_node );

void Diff_Interface ( const struct Node_t *start_node );

#endif  // FRONT_END
