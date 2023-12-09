#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#ifdef DEBUGG
#define $ printf ( "function <%s> line <%d>\n ", __PRETTY_FUNCTION__, __LINE__ );
#else
#define $
#endif

char *s = nullptr;
int p = 0;

enum Node_Type_t {
    NUM = 0,
    OP  = 1,
    VAR = 2,
    KEY = 3
};

enum Option_t {
    OP_ADD = '+',  // +
    OP_SUB = '-',  // -
    OP_DIV = '/',  // /
    OP_MUL = '*',  // *
    OP_VAR = 'x',  // x
    OP_BRA = '(',  // (
    CL_BRA = ')',  // )
    OP_POW = '^'   // ^
};

struct Node_t {
    int value       = 0;
    Node_Type_t type;
    Node_t *left     = 0;
    Node_t *right    = 0;
};

struct Tree_t {
    Node_t *start = nullptr;
    //Array
};

enum Errors_t {
    OK_TREE   = 0,
    ERR_FREAD = 1,
    ERR_INPUT = 2,
    ERR_FOPEN = 3,
    ERR_RLINE = 4,
    ERR_CALLO = 5,
    ERR_CYCLE = 6,
    ERR_CTYPE = 7
};

int GetFileSize ( FILE * f );
Node_t *GetN  ();
Node_t *GetG  ( char * str, struct Node_t *tree );
Node_t *GetE  ();
Node_t *GetT  ();
Node_t *GetP  ();
Node_t *GetId ();
void Analitic ( char *buffer, struct Node_t *tree );
void Tree_Text_Dump ( const struct Node_t *tree_node );
Node_t *Create_Node ( Option_t option, int value, struct Node_t *left, struct Node_t *right );
Errors_t Tree_Graph_Dump ( const struct Node_t *tree );
void Tree_Dump_Body ( const struct Node_t *tree, FILE *tree_dump );
double Eval ( const struct Node_t *node );
Errors_t FromType_ToOption ( struct Node_t *tree_node );
Node_t *d ( const struct Node_t *tree );
char *Skip_Spaces ( char *buffer );
Node_t *c ( const struct Node_t *tree );

FILE *logfile = fopen ( "logs/log.html", "w" );

int main ()
{
    struct Tree_t tree = {};// realloc

    FILE *f = fopen ( "start.txt", "r" );
    assert ( f != nullptr );

    int f_size = GetFileSize ( f );

    char *buffer = ( char *)calloc ( f_size + 1, sizeof ( char ) );
    assert ( buffer != nullptr );

    fread ( buffer, sizeof( buffer[0] ), f_size, f );   // error

    tree.start = GetG ( buffer, tree.start );

    //printf ( "%d\n", val );

    //Analitic ( buffer, tree.start );

    Tree_Graph_Dump ( tree.start );
    Tree_Text_Dump ( tree.start );

    FromType_ToOption ( tree.start );

    //printf ( "%g\n", Eval ( tree.start ) );

    Node_t *tree_c = d ( tree.start );

    Tree_Graph_Dump ( tree_c );
    Tree_Text_Dump ( tree_c );

    return 0;
}

Node_t *GetG ( char * str, struct Node_t *tree )
{
    s = str;
    p = 0;

    //assert ( s[p] == '\0' ); //my_assert
    tree = GetE();

    return tree;
}

Node_t *GetN ()
{
    int val = 0;
    int prev_p = p;

    while ( s[p] >= '0' && s[p] <= '9' ) {
        val = val * 10 + s[p] - '0';
        ++p;
    }
    assert ( p > prev_p );

    return Create_Node ( (Option_t)NUM, val, nullptr, nullptr );
}

Node_t *GetId ()
{
    char data[50] = {};//size
    int prev_p = p;

    for ( int i = 0; isalpha( s[p] ); ) {
        data[i++] = s[p];
        ++p;
    }
    assert ( p > prev_p );
    if ( strcmp ( data, "x" ) == 0 ) {

        return Create_Node ( (Option_t)VAR, OP_VAR, nullptr, nullptr );
    }
    printf ( "NO X\n" );

    return Create_Node ( (Option_t)KEY, -1, nullptr, nullptr );  // val???
}

int GetFileSize ( FILE * f )
{
    int prev = ftell ( f );

    fseek ( f, 0, SEEK_END );
    size_t size_not_blue = ftell ( f );
    fseek ( f, prev, SEEK_SET );

    return size_not_blue;
}

Node_t *GetE ()
{
    Node_t *val = GetT ();
    while ( s[p] == '+' || s[p] == '-' )
    {
        int op = s[p];
        p++;
        Node_t *val_2 = GetT ();

        switch ( op ) {
            case '+' : {
                val = Create_Node( (Option_t)OP, OP_ADD, val, val_2 );
                break;
            }
            case '-' : {
                val = Create_Node( (Option_t)OP, OP_SUB, val, val_2 );
                break;
            }
            default : {
                printf ( "Error" );
                break;
            }
        }
    }
    return val;
}

Node_t *GetT ()
{
    Node_t *val = GetP ();

    while ( s[p] == '*' || s[p] == '/' ) {
        char op = s[p];
        p++;

        Node_t *val_2 = GetP ();

        switch ( op ) {
            case '*' : {
                val = Create_Node( (Option_t)OP, OP_MUL, val, val_2 );
                break;
            }
            case '/' : {
                val = Create_Node( (Option_t)OP, OP_DIV, val, val_2 );
                break;
            }
            default : {
                printf ( "Error" );
                break;
            }
        }
    }
    return val;
}

Node_t *GetP ()
{
    if ( s[p] == '(' ) {

        Node_t *val = nullptr;
        p++;
        val = GetE ();

        assert ( s[p] == ')' );
        p++;

        return val;
    }
    else if ( isalpha ( s[p] ) ) {

        Node_t *val = GetId ();

        // function Id '(' E ')'

        return val;
    }
    else {

        return GetN ();
    }
}

Node_t *Create_Node ( Option_t option, int value, struct Node_t *left, struct Node_t *right )
{
    struct Node_t *tree_c = ( Node_t *)calloc ( 1, sizeof ( Node_t ) );
    if ( !tree_c ) {
        free ( tree_c );
    }
    tree_c->type = (Node_Type_t)option;
    tree_c->value = value;
    tree_c->left = left;
    tree_c->right = right;

    return tree_c;
}

char *Skip_Spaces ( char *buffer )
{
    while ( *buffer == ' ' ) {
        ++buffer;
    }

    return buffer;
}

/*void Analitic ( char *buffer, struct Node_t *tree )
{
    if ( tree == nullptr || buffer == '\0' ) {

        return ;
    }
    buffer = Skip_Spaces ( buffer );
    char *start = buffer;

    tree->type = OP;

    if ( isdigit ( *buffer ) ) {
        while ( isdigit ( *buffer ) ) {
            ++buffer;
        }
        tree->type = NUM;
        tree->value = atoi ( start );

        //Analitic ( buffer, tree->left );
        //Analitic ( buffer, tree->right );
    }

    if      ( *buffer == '-' ) {
         tree->value = OP_SUB;
    }
    else if ( *buffer == '+' ) {
        tree->value = OP_ADD;
    }
    else if ( *buffer == '/' ) {
        tree->value = OP_DIV;
    }
    else if ( *buffer == '*' ) {
        tree->value = OP_MUL;
    }
    else if ( *buffer == 'x' ) {
        tree->type = VAR;
        tree->value = OP_VAR;
    }
    ++buffer;  //error
    Analitic ( buffer, tree->left );
    Analitic ( buffer, tree->right );

} */

void Tree_Text_Dump ( const struct Node_t *tree_node )
{

    if ( tree_node == nullptr) {

        return ;
    }
    printf ( " ( " );

    Tree_Text_Dump ( tree_node->left  );

    if ( tree_node->type == NUM ) {
        printf ( "%d", tree_node->value );
    }
    else {
        printf ( "%c", tree_node->value );
    }

    Tree_Text_Dump ( tree_node->right );

    printf ( " ) " );

}

Errors_t Tree_Graph_Dump ( const struct Node_t *tree )
{
    static int file_count = 0;

    FILE *tree_dump = fopen ( "tree.dot", "w" );
    if ( !tree_dump ) {
        perror ( "File opening failed" );

        return ERR_FOPEN;
    }

    fprintf ( tree_dump, "digraph G { \n"
                         "node [shape = record];\n"
                         " \"%p\" ", tree );

    Tree_Dump_Body ( tree, tree_dump );

    fprintf ( tree_dump, "}\n" );
    fclose ( tree_dump );

    //system ( "del list.png" );
    const int SIZE = 100;
    char name[100];
    fprintf( logfile, "<img src=\"tree%d.png\" alt=\"-\" width=\"500\" height=\"600\">\n", file_count);
    sprintf( name, "dot -T png tree.dot -o logs/tree%d.png", file_count++ );
    system ( name );
    //system ( "tree.png" );

    return OK_TREE;
}

void Tree_Dump_Body ( const struct Node_t *tree, FILE *tree_dump )
{
    if ( tree == nullptr) {

        return ;
    }
    if ( tree->type == NUM ) {
        fprintf ( tree_dump , " \"%p\" [shape = Mrecord, style = filled, fillcolor = lightpink "
                          " label = \"data: %d \"];\n",tree, tree->value );
    }
    else {
        fprintf ( tree_dump , " \"%p\" [shape = Mrecord, style = filled, fillcolor = lightpink "
                          " label = \"data: %c \"];\n",tree, tree->value );
    }
    if ( tree->left != nullptr ) {
        fprintf ( tree_dump, "\"%p\" -> \"%p\" ", tree, tree->left );
    }
    if ( tree->right != nullptr ) {
        fprintf ( tree_dump, "\n \"%p\" -> \"%p\" \n", tree, tree->right );
    }

    Tree_Dump_Body ( tree->left,  tree_dump );
    Tree_Dump_Body ( tree->right, tree_dump );
}

double Eval ( const struct Node_t *node )
{
    if ( node == nullptr ) {

        return NULL;
    }
    if ( node->type == NUM ) {

        return node->value;
    }
    else if ( node->type == VAR ) {

        //return atof ( node->data );   //
    }
    double left  = Eval ( node->left );
    double right = Eval ( node->right );

    switch ( node->type ) {
        case OP_ADD : {

            return left + right;
            break;
        }
        case OP_SUB : {

            return left - right; // left or right
            break;
        }
        case OP_DIV : {

            return left / right; // left or right// /
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
    if ( !tree_node || tree_node->type != OP ) {

        return OK_TREE;
    }
    if ( tree_node->type == OP ) {
        tree_node->type = (Node_Type_t)tree_node->value;
        // error
    }
    FromType_ToOption ( tree_node->left  );
    FromType_ToOption ( tree_node->right );

    return OK_TREE;
}

Node_t *d ( const struct Node_t *tree )
{
    // dump
    if ( tree == nullptr ) {

        return nullptr;
    }
    if ( tree->type == NUM ) {

        return Create_Node ( (Option_t)NUM, 0, nullptr, nullptr );
    }
    else if ( tree->type == VAR ) {

        return Create_Node ( (Option_t)NUM, 1, nullptr, nullptr );
    }
    else {
        switch ( tree->type ) {
            case OP_ADD : {
                return Create_Node ( (Option_t)OP, OP_ADD, d ( tree->left ), d ( tree->right ) );
                break;
            }
            case OP_SUB : {
                return Create_Node ( (Option_t)OP, OP_SUB, d ( tree->left ), d ( tree->right ) );
                break;
            }
            case OP_MUL : {
                return Create_Node ( (Option_t)OP, OP_ADD, Create_Node ( (Option_t)OP, OP_MUL, d ( tree->left ), c ( tree->right ) ),
                                                           Create_Node ( (Option_t)OP, OP_MUL, c ( tree->left ), d ( tree->right ) ) );
                break;
            }
            case OP_DIV : {
                return Create_Node ( (Option_t)OP, OP_DIV, Create_Node ( (Option_t)OP, OP_SUB, Create_Node ( (Option_t)OP, OP_MUL, d ( tree->left ), c ( tree->right ) ),
                                                                                               Create_Node ( (Option_t)OP, OP_MUL, c ( tree->left ), d ( tree->right ) )),
                                                           Create_Node ( (Option_t)OP, OP_MUL, c ( tree->right ), c ( tree->right ) ) );
                break;
            }
            // default
        }
    }
    //return tree_c;
}

Node_t *c ( const struct Node_t *tree )
{
    if ( tree == nullptr ) {

        return nullptr;
    }

    return Create_Node ( (Option_t)tree->type, tree->value, tree->left, tree->right );
}







