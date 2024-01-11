#include "recurs_des.h"
#include "front.h"
// Ctor
// Dtor[[[[[[[[[[[[[[[[

FILE *logfile = fopen ( "logs/log.html", "w" );

int main ( int argc, char *argv[] )
{
    struct Tree_t Tree = {};
    struct File_t File = {};
    File.file_name = argv[1];
    File_Reader ( &File );

    Tree.start = GetG ( File.out_buffer, Tree.start );

    //Analitic ( buffer, tree.start );

    Tree_Graph_Dump ( Tree.start );
    Tree_Text_Dump ( Tree.start );

    FromType_ToOption ( Tree.start );

    //File_Write_Front ( Tree.start );

    //printf ( "%g\n", Eval ( tree.start ) );
    //Optimization_Const ( tree.start );
    Node_t *tree_c = d ( Tree.start );  // Tree_c

    Tree_Graph_Dump ( tree_c );
    Tree_Text_Dump ( tree_c );

    fclose ( File.front_f );

    return 0;
}

Errors_t File_Reader ( struct File_t *File )
{
    File->front_f = fopen ( File->file_name, "r" );
    assert ( File->front_f != nullptr );   // assert

    File->file_size = GetFileSize ( File->front_f );

    File->out_buffer = ( char *)calloc ( File->file_size + 1, sizeof ( char ) );
    assert ( File->out_buffer != nullptr ); // assert

    int ret_code = fread ( File->out_buffer, sizeof( File->out_buffer[0] ), File->file_size, File->front_f );
    if ( ret_code != File->file_size ) {
        if ( feof ( File->front_f ) ) {
            printf ( "Error reading test.bin: unexpected end of file\n" );
        }
        else if ( ferror ( File->front_f ) ) {
            perror ( "Error reading test.bin" );
        }
        return ERR_FREAD;
    }

    fclose ( File->front_f );

    return OK_FILE;
}

int GetFileSize ( FILE * f ) // +
{
    int prev = ftell ( f );

    fseek ( f, 0, SEEK_END );
    size_t size_not_blue = ftell ( f );
    fseek ( f, prev, SEEK_SET );

    return size_not_blue;
}

Node_t *Create_Node ( Node_Type_t option, int value, struct Node_t *left, struct Node_t *right ) // +
{
    struct Node_t *tree_c = ( Node_t *)calloc ( 1, sizeof ( Node_t ) );
    if ( !tree_c ) {
        free ( tree_c );
    }
    tree_c->type = option;
    tree_c->value = value;
    tree_c->left = left;
    tree_c->right = right;

    return tree_c;
}

char *Skip_Spaces ( char *buffer )   // -----
{
    while ( *buffer == ' '  ||
            *buffer == '\t' ||
            *buffer == '\n' ) {

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
    else if ( tree_node->type == VAR ||
              tree_node->type == OP  ) {
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
    char name[SIZE] = {};
    fprintf( logfile, "<img src=\"tree%d.png\" alt=\"-\" width=\"500\" height=\"600\">\n", file_count);
    sprintf( name, "dot -T png tree.dot -o logs/tree%d.png", file_count++ );
    system ( name );
    //system ( "tree.png" );

    return OK_TREE;
}

void Tree_Dump_Body ( const struct Node_t *tree, FILE *tree_dump ) // +     // name
{
    if ( tree == nullptr) {

        return ;
    }
    if ( tree->type == NUM ) {
        fprintf ( tree_dump , " \"%p\" [shape = Mrecord, style = filled, fillcolor = lightpink "
                          " label = \"data: %d \"];\n",tree, tree->value );
    }
    else if ( tree->type == VAR ||
              tree->type == OP ) {
        fprintf ( tree_dump, " \"%p\" [shape = Mrecord, style = filled, fillcolor = lightpink "
                             " label = \"data: %c \"];\n", tree, tree->value );
    }
    else {
        printf ( "Add more options\n" );
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

double Eval ( const struct Node_t *node ) // +
{
    if ( node == nullptr ) {

        return 0;
    }
    if ( node->type == NUM ) {

        return node->value;
    }
    else if ( node->type == VAR ){
        printf ( "Error, because i dont't know this value\n" );
    }

    double left  = Eval ( node->left );
    double right = Eval ( node->right );

    if ( node->type == OP ) {
        switch ( (Option_t) node->value ) {
            case OP_ADD : {

                return left + right;
                break;
            }
            case OP_SUB : {

                return left - right;
                break;
            }
            case OP_DIV : {

                return left / right;
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
    }

    return ERR_CTYPE;
}

Errors_t FromType_ToOption ( struct Node_t *tree_node ) // ----
{
    if ( !tree_node || tree_node->type != OP ) {

        return OK_TREE;
    }
    /*if ( tree_node->type == OP ) {
        tree_node->value = (Node_Type_t)tree_node->value;
        // error
    } */
    FromType_ToOption ( tree_node->left  );
    FromType_ToOption ( tree_node->right );

    return OK_TREE;
}

Node_t *d ( const struct Node_t *tree )  // +
{
    if ( tree == nullptr ) {

        return nullptr;
    }
    if ( tree->type == NUM ) {

        return Create_Node ( NUM, 0, nullptr, nullptr );
    }
    else if ( tree->type == VAR ) {

        return Create_Node ( NUM, 1, nullptr, nullptr );
    }
    else if ( tree->type == OP ){
        switch ( tree->value ) {
            case OP_ADD : {
                Node_t *tree_c = Create_Node ( OP, OP_ADD, d ( tree->left ), d ( tree->right ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_SUB : {
                Node_t *tree_c = Create_Node ( OP, OP_SUB, d ( tree->left ), d ( tree->right ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_MUL : {
                Node_t *tree_c = Create_Node ( OP, OP_ADD, Create_Node ( OP, OP_MUL, d ( tree->left ), c ( tree->right ) ),
                                                           Create_Node ( OP, OP_MUL, c ( tree->left ), d ( tree->right ) ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_DIV : {
                Node_t *tree_c = Create_Node ( OP, OP_DIV, Create_Node ( OP, OP_SUB, Create_Node ( OP, OP_MUL, d ( tree->left ), c ( tree->right ) ),
                                                                           Create_Node ( OP, OP_MUL, c ( tree->left ), d ( tree->right ) ) ),
                                                 Create_Node ( OP, OP_MUL, c ( tree->right ), c ( tree->right ) ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            default    : {
                printf ( "Option error\n" );
                break;
            }
        }
    }
    return nullptr;
}

Node_t *c ( const struct Node_t *tree )  // +
{
    if ( tree == nullptr ) {

        return nullptr;
    }

    return Create_Node ( tree->type, tree->value, tree->left, tree->right );
}

int Optimization_Const ( struct Node_t *tree ) // +
{
$   if ( tree == nullptr || tree->right == nullptr || tree->left == nullptr ) {

        return 0;
    }
$   if ( tree->left->type  == NUM &&
         tree->right->type == NUM  ) {

$       tree->value = (int)Eval ( tree );
$       tree->type = NUM;
$       Node_Free ( &(tree->left  ) );
$       Node_Free ( &(tree->right ) );

        return OK_OCCURR;
    }
    else {
$       return ( Optimization_Const ( tree->left ) ||
$                Optimization_Const ( tree->right ) );
    }
}

int Optimization_Option ( struct Node_t **tree )  // +
{
$   if ( (*tree) == nullptr  ) {

        return 0;
    }
$   if ( (*tree)->type == OP && (*tree)->value == OP_MUL ) {
        if ( (*tree)->left->value  == 0 || (*tree)->right->value == 0 ) {
$           (*tree)->value = 0;
$           (*tree)->type  = NUM;
$           Node_Free ( &((*tree)->left ) );
$           Node_Free ( &((*tree)->right ) );

            return OK_OCCURR;
        }
        if ( (*tree)->left->value  == 1 ) {  // func
            Node_Free ( &((*tree)->left ) );
            (*tree) = (*tree)->right;

            return OK_OCCURR;
        }
        else if ( (*tree)->right->value == 1 ) {
            Node_Free ( &((*tree)->right ) );
            *tree = (*tree)->left; // for this moment

            return OK_OCCURR;
        }

        return 0;
    }
    else {
$       return ( Optimization_Option ( &(*tree)->left ) ||
$                Optimization_Option ( &(*tree)->right )  );
    }
}

void Optimization ( struct Node_t *tree )  // +
{
    int occurrences_n = 0;
    int prev_occuttences_n = 0;

    do {
        prev_occuttences_n = occurrences_n;
        if ( Optimization_Const  ( tree) ||
             Optimization_Option ( &tree ) ) {
            ++occurrences_n;
            //Tree_Text_Dump ( tree );
        }
    } while ( prev_occuttences_n != occurrences_n );
}

void Node_Free ( struct Node_t **tree ) // +
{
    if ( *tree != nullptr ) {
        Node_Free ( &((*tree)->left) );
        Node_Free ( &((*tree)->right));

        (*tree)->left = nullptr;
        (*tree)->right = nullptr;

        (*tree) = nullptr;
    }
}

/*void File_Write_Front ( const struct Node_t *tree )
{
    FILE *asm_f = fopen ( "asm.txt", "w" );

    File_Write_Asm_Text ( tree, asm_f );

    fprintf ( asm_f, "hlt;" );
}

void File_Write_Asm_Text ( const struct Node_t *tree, FILE *start_f )
{
    if ( tree == nullptr ) {

        return ;
    }
    File_Write_Asm_Text ( tree->left, start_f );
    File_Write_Asm_Text ( tree->right, start_f );

    if ( tree->type == NUM ) {
        fprintf ( start_f, "push %d;\n", tree->value );
    }
    if ( tree->type == OP && tree->value == OP_MUL ) {
        fprintf ( start_f, "mul;\n" );
    }
} */


