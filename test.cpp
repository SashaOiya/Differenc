#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifdef DEBUGG
#define $ printf ( "function <%s> line <%d>\n ", __PRETTY_FUNCTION__, __LINE__ );
#else
#define $
#endif

struct Knot {
    char* value = 0;  // name //calloc
    Knot *left   = 0;
    Knot *right  = 0;
    int count = 0;  // chislo vhogdeniy
};

struct Tree_t {
    Knot *start = 0;
    //size_t capacity = 5;
};

enum Errors_t {
    ERR_NO   = 0,
    ERR_READ = 1

};

void Print_Node  ( struct Knot *tree_knot );
Errors_t File_Reader ( FILE * f, struct Knot **tree );

int main ()
{
    FILE *tree_f = fopen ( "tree.txt", "r" );
    struct Tree_t tree = {};

    //printf ("%d\n", sizeof (  ) );

    //tree.start = (Knot *)calloc ( 1, sizeof ( Knot ) );

    File_Reader ( tree_f, &tree.start );

    Print_Node ( tree.start );

    assert ( tree.start != nullptr );

    return 0;
}

Errors_t File_Reader ( FILE * f, struct Knot **tree )
{
    char word[100] = {};
    fscanf ( f, "%s", &word ); //getline

    if ( strcmp ( word, ")" ) == 0 ) {
        fscanf ( f, "%s", &word );
    }
    if ( strcmp ( word, "(" ) == 0 ) {
        *tree = (Knot *)calloc ( 1, sizeof ( Knot ) );
$       fscanf ( f, "%s", &word );
    }
    if ( strcmp ( word, "\0" ) == 0 ||
         strcmp ( word, "nil" ) == 0 ) {

        return ERR_NO;
    }
$   (*tree)->value = strdup( word );

$   File_Reader ( f, &((*tree)->left) );
    File_Reader ( f, &((*tree)->right) );

    fscanf ( f, "%s", &word ); //getline

    if ( strcmp ( word, ")" ) != 0 ) {
        printf ( "ERROR\n" );

        return ERR_READ;
    }

    return ERR_NO;
}

void Print_Node  ( struct Knot *tree_knot )
{

    if ( tree_knot == nullptr) {
        printf ( " nil " );

        return ;
    }
    printf ( " ( " );

    printf ( "%s", tree_knot->value );

    Print_Node ( tree_knot->left );
    Print_Node ( tree_knot->right );

    printf ( " ) " );

}


