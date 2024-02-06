#include "recurs_des.h"
#include "front.h"

int main ( int argc, char *argv[] )
{
    struct Tree_t Tree = {};
    struct File_t File = {};

    Diff_Tree_Ctor ( argv[1], &File, &Tree );

    Tree_Graph_Dump ( Tree.start );
    Tree_Text_Dump ( Tree.start );

    FILE* latex_file = fopen ( "eval.txt", "w" );
   // Print_Latex ( Tree.start, latex_file);

    Node_t *tree_c = d ( Tree.start );  // Tree_c  d == death!!!!!!

    //Tree_Graph_Dump ( tree_c );
    Tree_Text_Dump ( tree_c );

    //Node_t *tailor_node = Teilor ( c( Tree.start ), 3 );  // taylor? c??!!?!?!??!?

    //Tree_Graph_Dump ( tailor_node );

    fclose ( latex_file );
    Diff_Tree_Dtor ( &File, &Tree );

    return 0;
}

Errors_t File_Reader ( struct File_t *File )  // -
{
    File->front_f = fopen ( File->file_name, "r" );
    if ( !File->front_f ) {
        printf ( "File opening error\n" );

        return ERR_FREAD;
    }

    File->file_size = GetFileSize ( File->front_f );

    File->out_buffer = ( char *)calloc ( File->file_size + 1, sizeof ( char ) );
    if ( !File->out_buffer ) {
        printf ( "buffer memory allocation error\n" );
        fclose ( File->front_f );

        return ERR_FREAD;
    }

    int ret_code = fread ( File->out_buffer, sizeof( File->out_buffer[0] ),
                           File->file_size, File->front_f );
    if ( ret_code != File->file_size ) {
        if ( feof ( File->front_f ) ) { //! why?
            printf ( "Error reading test.bin: unexpected end of file\n" );
        }
        else if ( ferror ( File->front_f ) ) { //! try to
            perror ( "Error reading test.bin" );
        }
        free ( File->out_buffer );
        fclose ( File->front_f );

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

char *File_Skip_Spaces ( char *data, int file_size ) // +
{
    char *buffer = (char *)calloc ( file_size + 1, sizeof ( char ) );
    if ( !buffer ) {
        printf ( "buffer memory allocation error\n" );

        return data;
    }
    int position = 0;

    for ( ; *data != '\0'; ++data ) {
        while ( *data == ' '  ||
                *data == '\t' ||
                *data == '\n' ) {

            ++data;
        }
        buffer[position++] = *data;
    }
    buffer[position] = '\0';

    return buffer;
}

void Tree_Text_Dump ( const struct Node_t *tree_node ) // +
{
    if ( tree_node == nullptr) {

        return ;
    }
    printf ( " ( " );

    Tree_Text_Dump ( tree_node->left  );

    if ( tree_node->type == NODE_TYPE_NUM ) {
        printf ( "%d", tree_node->value );
    }
    else if ( tree_node->type == NODE_TYPE_OP ||
              tree_node->type == NODE_TYPE_VAR ) {
        printf ( "%s", Get_Op_Name ( tree_node->value ) );
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

    const int SIZE = 100; // ??
    char name[SIZE] = {}; // name??? cmd
    fprintf( log(), "<img src=\"tree%d.png\" alt=\"-\" width=\"500\" height=\"600\">\n", file_count);
    sprintf( name, "dot -T png tree.dot -o logs/tree%d.png", file_count++ );
    system ( name );

    return OK_TREE;
}

void Tree_Dump_Body ( const struct Node_t *tree, FILE *tree_dump ) // -
{
    if ( tree == nullptr) {

        return ;
    }
    // No copy pasta: %s + function print node data(type) return char*?
    if ( tree->type == NODE_TYPE_NUM ) {
        fprintf ( tree_dump , " \"%p\" [shape = Mrecord, style = filled, fillcolor = lightpink "
                              " label = \"%d \"];\n",tree, tree->value );
    }
    else if ( tree->type == NODE_TYPE_VAR ||
              tree->type == NODE_TYPE_OP ) {
        fprintf ( tree_dump, " \"%p\" [shape = Mrecord, style = filled, fillcolor = lightpink "
                             " label = \"%s \"];\n", tree, Get_Op_Name ( tree->value ) );
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

double Eval ( const struct Node_t *node ) // - add var
{
    if ( node == nullptr ) {

        return 0;
    }
    if ( node->type == NODE_TYPE_NUM ) {

        return node->value;
    }
    else if ( node->type == NODE_TYPE_VAR ) {  // if calc expression with variables (e.g. x = 1)
        printf ( "Error, because i dont't know this value\n" );

        return 0;
    }

    double left  = Eval ( node->left );
    double right = Eval ( node->right );

    if ( node->type == NODE_TYPE_OP ) {
        switch ( node->value ) {
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
            case OP_SIN : {

                return sin ( right );
                break;
            }
            case OP_COS : {

                return cos ( right );
                break;
            }
            case OP_TG  : {

                return tan ( right );
                break;
            }
            case OP_CTG : {

                return 1 / tan ( right );
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

Node_t *d ( const struct Node_t *tree )  // -    // node
{
    // allocator оцени
    // calloc blockami

    if ( tree == nullptr ) {

        return nullptr;
    }
    if ( tree->type == NODE_TYPE_NUM ) {

        return Create_Node ( NODE_TYPE_NUM, 0, nullptr, nullptr );
    }
    else if ( tree->type == NODE_TYPE_VAR ) {

        return Create_Node ( NODE_TYPE_NUM, 1, nullptr, nullptr );
    }
    else if ( tree->type == NODE_TYPE_OP ){
        switch ( tree->value ) {
            case OP_ADD : {
                Node_t *tree_c = Create_Node ( NODE_TYPE_OP, OP_ADD, d ( tree->left ), d ( tree->right ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_SUB : {
                Node_t *tree_c = Create_Node ( NODE_TYPE_OP, OP_SUB, d ( tree->left ), d ( tree->right ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_MUL : {
                Node_t *tree_c = Create_Node ( NODE_TYPE_OP, OP_ADD, Create_Node ( NODE_TYPE_OP, OP_MUL, d ( tree->left ), c ( tree->right ) ),
                                                                     Create_Node ( NODE_TYPE_OP, OP_MUL, c ( tree->left ), d ( tree->right ) ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_DIV : {
                Node_t *tree_c = Create_Node ( NODE_TYPE_OP, OP_DIV, Create_Node ( NODE_TYPE_OP, OP_SUB, Create_Node ( NODE_TYPE_OP, OP_MUL, d ( tree->left ), c ( tree->right ) ),
                                                                                                         Create_Node ( NODE_TYPE_OP, OP_MUL, c ( tree->left ), d ( tree->right ) ) ),
                                                                     Create_Node ( NODE_TYPE_OP, OP_MUL, c ( tree->right ), c ( tree->right ) ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_SIN : {
                Node_t *tree_c = c ( tree );
                tree_c->value = OP_COS;
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, d ( tree->right) );
                return tree_c;
                break;
            }
            case OP_COS : {
                Node_t *tree_c = c ( tree );
                tree_c->value = OP_SIN;
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, d ( tree->right) );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, Create_Node ( NODE_TYPE_NUM, -1, nullptr, nullptr ), tree_c );

                return tree_c;
                break;
            }
            case OP_TG  : {
                Node_t *tree_c = c ( tree );
                tree_c->value = OP_COS;
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, tree_c );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_DIV, Create_Node ( NODE_TYPE_NUM, 1, nullptr, nullptr ), tree_c );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, d ( tree->right ) );

                return tree_c;
                break;
            }
            case OP_CTG  : {
                Node_t *tree_c = c ( tree );
                tree_c->value = OP_SIN;
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, tree_c );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_DIV, Create_Node ( NODE_TYPE_NUM, -1, nullptr, nullptr ), tree_c );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, d ( tree->right ) );

                return tree_c;
                break;
            }
            default    : {
                printf ( "ERROR\n" );
            }
        }
    }
    return nullptr;
}

Node_t *c ( const struct Node_t *tree )  // -     // NAMES!!! AAA!
{
    if ( tree == nullptr ) {

        return nullptr;
    }

    return Create_Node ( tree->type, tree->value, tree->left, tree->right );
}

int Optimization_Const ( struct Node_t *tree ) // -      // **
{
    if ( tree == nullptr || tree->right == nullptr || tree->left == nullptr ) {
$
        return 0;
    }
$   if ( tree->left->type  == NODE_TYPE_NUM &&
         tree->right->type == NODE_TYPE_NUM  ) {

$       tree->value = (int)Eval ( tree );
$       tree->type = NODE_TYPE_NUM;
$       Node_Free ( &(tree->left  ) );
$       Node_Free ( &(tree->right ) );

        return OK_OCCURR;
    }
    else {
        return ( Optimization_Const ( tree->left ) ||
                 Optimization_Const ( tree->right ) );
    }
}

int Optimization_Option ( struct Node_t **tree )  // +-
{
$   if ( (*tree) == nullptr  ) {

        return 0;
    }
$   if ( (*tree)->type == NODE_TYPE_OP && (*tree)->value == OP_MUL ) {
        if ( (*tree)->left->value  == 0 || (*tree)->right->value == 0 ) {
$           (*tree)->value = 0;
$           (*tree)->type  = NODE_TYPE_NUM;
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
$
        return 0;
    }
    else {
       return ( Optimization_Option ( &(*tree)->left ) ||
                Optimization_Option ( &(*tree)->right )  );
    }
}

void Optimization ( struct Node_t *tree )  // +
{

    while ( Optimization_Const  ( tree) ||
            Optimization_Option ( &tree ) );
    /*int occurrences_n = 0;
    int prev_occuttences_n = 0;

    do {
        prev_occuttences_n = occurrences_n;
        if ( Optimization_Const  ( tree) ||
             Optimization_Option ( &tree ) ) {
            ++occurrences_n;
            //Tree_Text_Dump ( tree );
        }
    } while ( prev_occuttences_n != occurrences_n );  */
}

void Node_Free ( struct Node_t **tree ) // +
{
    //assert ( tree );
    if ( *tree != nullptr ) {
        Node_Free ( &((*tree)->left) );
        Node_Free ( &((*tree)->right));

        (*tree)->left = nullptr;
        (*tree)->right = nullptr;

        *tree = nullptr;
    }
}

Errors_t Diff_Tree_Ctor ( char *open_file, struct File_t *File, struct Tree_t *Tree ) // +
{
    File->file_name = open_file;
    Errors_t error_name = File_Reader ( File );
    if ( error_name != OK_FILE ) {

        return ERR_FREAD;
    }
    File->out_buffer = File_Skip_Spaces ( File->out_buffer, File->file_size );
    Tree->start = Get_General ( File->out_buffer, Tree->start );

    return OK_FILE;
}

Errors_t Diff_Tree_Dtor ( struct File_t *File, struct Tree_t *Tree )
{
    Node_Free ( &(Tree->start) );
    free ( File->out_buffer );
    fclose ( File->front_f );
}

const char *Get_Op_Name ( int op_type )
{
    if ( op_type == OP_SIN ) {

        return "sin";
    }
    else if ( op_type == OP_COS ) {

        return "cos";
    }
    else if ( op_type == OP_TG ) {

        return "tg";
    }
    else if ( op_type == OP_CTG ) {

        return "ctg";
    }

    return strdup ( (char *)(&op_type) );
}

void Print_Latex ( Node_t* node, FILE* latex_file )
{
    fprintf ( latex_file, "\\[" );

    Print_Latex_Body ( node, latex_file );

    fprintf ( latex_file, "\\]" );
}

void Print_Latex_Body ( Node_t* node, FILE* latex_file)
{
    switch (node->type)
    {
        case NODE_TYPE_OP  : {
            LatexOp ( node, latex_file );
            break;
        }
        case NODE_TYPE_NUM : {
            fprintf ( latex_file, "%d", node->value );
            break;
        }
        case NODE_TYPE_VAR : {
            fprintf ( latex_file, "x" );
            break;
        }
    }
}

void PutOp ( Node_t* node, FILE* latex_file)
{
    if (node->value == OP_DIV) {
        fprintf (latex_file, "}{");
    }
    else if (node->value == OP_MUL) {
        fprintf (latex_file, " \\cdot ");
    }
    else {
        fprintf (latex_file, "%s", Get_Op_Name ( node->value ) );
    }
}

void LatexOp ( Node_t* node, FILE* latex_file)
{
    if ( node->value == OP_DIV ) {
        fprintf (latex_file, " \\frac{");
    }

    switch (node->left->type)
    {
        case NODE_TYPE_NUM:
        {
            if ( node->value == OP_MUL)
            {
                if ( node->left->value == -1 ) {
                    fprintf ( latex_file, "-" );
                }
                else {
                    fprintf ( latex_file, "%d", node->left->value );
                }
            }
            else {
                fprintf (latex_file, "%d", node->left->value);
            }
            break;
        }
        case NODE_TYPE_VAR: {
            fprintf (latex_file, "x" );
            break;
        }
        default:
        {
            Brackets (node, latex_file, '(');
            Print_Latex_Body (node->left, latex_file);
            Brackets (node, latex_file, ')');
            break;
        }
    };

    PutOp ( node, latex_file );

    switch (node->right->type)
    {
        case NODE_TYPE_NUM: {
            fprintf (latex_file, "%d", node->right->value);
            break;
        }
        case NODE_TYPE_VAR: {
            fprintf (latex_file, "x");
            break;
        }
        default: {
            Brackets (node, latex_file, '(');
            Print_Latex_Body (node->right, latex_file);
            Brackets (node, latex_file, ')');
            break;
        }
    };

    if ( node->value == OP_DIV ) {
        fprintf ( latex_file, "}" );
    }
}

void Brackets ( Node_t* node, FILE* latex_file, char bracket_type)
{
    if (node->value == OP_MUL)
    {
        if ( (node->left->type  != NODE_TYPE_NUM || (node->right->type != NODE_TYPE_OP || node->right->value != OP_DIV)) &&
             (node->left->value != OP_DIV || node->right->value != OP_DIV))
            fprintf (latex_file, "%c", bracket_type);
    }
    else if (node->value != OP_DIV)
    {
        if (node->right->value != OP_MUL && node->right->value != OP_DIV &&
           (node->right->value != OP_ADD && node->right->value != OP_SUB) )
            fprintf (latex_file, "%c", bracket_type);
    }
}

Node_t *Teilor ( struct Node_t *tree_node, const int number )
{
    struct Tree_t Tree_Tailor = {};
    Tree_Tailor.start = Create_Node( NODE_TYPE_NUM, 0, nullptr, nullptr );
    Node_t *tailor_node = tree_node; // copy

    for ( int i = 0; i < number; ++i ) {
        //Tree_Tailor.start = Create_Node ( OP, OP_ADD, Tree_Tailor.start, tailor_node );
        Tree_Graph_Dump ( tailor_node );
        tailor_node = Teilor_Body ( tailor_node, i+1 );
    }

    return Tree_Tailor.start;
}

Node_t *Teilor_Body ( const struct Node_t *tree_node, const int number ) // name
{
    Node_t *factorial_n = Create_Node ( NODE_TYPE_NUM, factorial ( number), nullptr, nullptr );    // nameeeee
    Node_t *x = Create_Node ( NODE_TYPE_VAR, OP_VAR, nullptr, nullptr );
    Node_t *pow_x = Create_Node ( NODE_TYPE_NUM, 1, nullptr, nullptr );  // nameeeeee

    for ( int i = 0; i < number; ++i ) {
        pow_x = Create_Node ( NODE_TYPE_OP, OP_MUL, x, pow_x );
    }
    pow_x = Create_Node ( NODE_TYPE_OP, OP_DIV, pow_x, factorial_n );
    pow_x = Create_Node ( NODE_TYPE_OP, OP_MUL, d( tree_node ), pow_x );

    return pow_x;
}

int factorial ( unsigned number )
{
    if ( number == 0 || number == 1 ) { // number <= 1

        return 1;
    }
    return number * factorial ( number - 1 );
}
