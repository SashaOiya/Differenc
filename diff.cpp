#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef DEBUGG
#define $ printf ( "function <%s> line <%d>\n ", __PRETTY_FUNCTION__, __LINE__ );
#else
#define $
#endif

enum Node_Type_t {
    NUMBER = 0,
    SYMBOL = 1
};

enum Option_t {
    OP_ADD = 1,  // +
    OP_SUB = 2,  // -
    OP_DIV = 3,  // /
    OP_MUL = 4   // *
};

struct Node_t {
    char *data       = 0;
    Node_Type_t type;
    Node_t *left     = 0;
    Node_t *right    = 0;
};

struct Tree_t {
    Node_t *start = nullptr;
};

enum Errors_t {
    OK        = 0,
    ERR_FREAD = 1,
    ERR_INPUT = 2,
    ERR_FOPEN = 3,
    ERR_RLINE = 4,
    ERR_CALLO = 5,
    ERR_CTYPE = 6
};

Errors_t File_Reader ( struct Node_t **tree, FILE * f );
void Tree_Text_Dump ( const struct Node_t *tree_node );
void Tree_Dtor ( struct Node_t *tree );
Errors_t FromType_ToOption ( struct Node_t *tree_node );
double Eval ( const struct Node_t *node );

int main ()
{
    struct Tree_t tree = {};
    FILE *tree_f = fopen ( "start.txt", "r" );
    if ( !tree_f ) {
        perror ( "File opening failed" );

        return ERR_FOPEN;
    }

    if ( File_Reader ( &tree.start, tree_f ) != OK ) {

        return EXIT_FAILURE;
    }
    Tree_Text_Dump ( tree.start );

    FromType_ToOption ( tree.start );

    printf ( "%g\n", Eval ( tree.start ) );

    fclose ( tree_f );

    Tree_Dtor ( tree.start );

    return 0;
}

Errors_t File_Reader ( struct Node_t **tree, FILE * f )
{
    int sign = 0;
    char data[10] = {};

    int i = 0; //fscanf ( f, "%s", &data );

    if ( ( i = fscanf ( f , "%s", &data ) ) == 0 || i == EOF ) {

        return ERR_FREAD;
    }
$   if ( strcmp ( data, ")" ) == 0 ) {
        i = fscanf ( f , "%s", &data );
    }
    if ( strcmp ( data, "(" ) == 0 ) {  // strncmp
        *tree = (Node_t *)calloc ( 1, sizeof ( Node_t ) );
        if ( !tree ) {
            free ( tree );

            return ERR_CALLO;
        }
$       i = fscanf ( f , "%s", &data );
        (*tree)->type = SYMBOL;
    }
    if ( i < 1 ) {  //????

        return ERR_FREAD;
    }

$   if ( strcmp ( data, "\0" )  == 0 ||
         strcmp ( data, "nil" ) == 0 ) {

        return OK;
    }
    if ( isdigit ( data[0] ) && i != EOF ) {
        //i = atoi ( data );
        (*tree)->type = NUMBER;
    }
$   (*tree)->data = strdup( data );

$   File_Reader ( &((*tree)->left) , f ); //?????  //
    File_Reader ( &((*tree)->right), f ); //

    i = fscanf ( f, "%s", &data );

    if ( strcmp ( data, ")" ) != 0 || i == ERR_RLINE ) {
        printf ( "ERROR\n" );

        return ERR_FREAD;
    }

    return OK;
}

void Tree_Dtor ( struct Node_t *tree )
{
    if ( tree != nullptr ) {
        Tree_Dtor ( tree->left  );
        Tree_Dtor ( tree->right );

        free ( tree );
    }
}

void Tree_Text_Dump ( const struct Node_t *tree_node )
{

    if ( tree_node == nullptr) {
        printf ( " nil " );

        return ;
    }
    printf ( " ( " );
    printf ( "%s", tree_node->data );

    Tree_Text_Dump ( tree_node->left  );
    Tree_Text_Dump ( tree_node->right );

    printf ( " ) " );

}

double Eval ( const struct Node_t *node )
{
    if ( node == nullptr ) {

        return 0; //
    }
    if ( node->type == NUMBER ) {

        //double value = atof ( node->data );

        return atof ( node->data );
    }
    double left  = Eval ( node->left );
    double right = Eval ( node->right );

    switch ( node->type ) {
        case OP_ADD : {

            return left + right;
            break;
        }
        case OP_SUB : {

            return right - left; // left or right
            break;
        }
        case OP_DIV : {

            return right / left; // left or right// /
            break;
        }
        case OP_MUL : {

            return left * right;
            break;
        }
        default :{
            printf ( "ERROR\n" );

            break;
        }
    }

    return ERR_CTYPE;
}

Errors_t FromType_ToOption ( struct Node_t *tree_node )
{
    if ( !tree_node || tree_node->type != SYMBOL ) {

        return OK;
    }
    if      ( strcmp ( tree_node->data, "-" ) == 0 ) {
$        tree_node->type = (Node_Type_t)OP_SUB;
    }
    else if ( strcmp ( tree_node->data, "+" ) == 0 ) {
$       tree_node->type = (Node_Type_t)OP_ADD;
    }
    else if ( strcmp ( tree_node->data, "/" ) == 0 ) {
$       tree_node->type = (Node_Type_t)OP_DIV;
    }
    else if ( strcmp ( tree_node->data, "*" ) == 0 ) {
        tree_node->type = (Node_Type_t)OP_MUL;
    }
    else {
        printf ( "ERROR TYPE\n" );

        return ERR_CTYPE;
    }
    FromType_ToOption ( tree_node->left  );
    FromType_ToOption ( tree_node->right );

    return OK;
}


