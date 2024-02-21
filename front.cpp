#include "recurs_des.h"
#include "front.h"
#include "my_prog.h"

// double or int
// $$$$

int main ( int argc, char *argv[] )
{
    struct Tree_t tree = {};
    struct File_t file = {};

    Diff_Tree_Ctor ( &file, &tree, argv[1] );

    Tree_Graph_Dump ( tree.start_node );
    Tree_Text_Dump ( tree.start_node );

    FILE* latex_file = fopen ( "latex.txt", "w" );
    Print_Latex ( tree.start_node, latex_file );

    //Node_t *tree_c = Differentiation ( tree.start_node );  //

    //Tree_Graph_Dump ( tree_c );
    //Tree_Text_Dump ( tree_c );

    struct Tree_t taylor_tree = {};
    taylor_tree.start_node = Teylor ( tree.start_node, 3 );

    Tree_Graph_Dump ( taylor_tree.start_node );

    Node_Free ( &(taylor_tree.start_node) );
    Diff_Tree_Dtor ( &file, &tree );
    fclose ( latex_file );

    return 0;
}

Errors_t File_Reader ( struct File_t *File )  // -
{
    File->front_f = fopen ( File->file_name, "r" );
    if ( !File->front_f ) {
        print_color ( "File opening error\n", COLOR_RED );

        return ERR_FREAD;
    }

    File->file_size = Get_File_Size ( File->front_f );

    File->out_buffer = ( char *)calloc ( File->file_size + 1, sizeof ( char ) );
    if ( !File->out_buffer ) {
        print_color ( "buffer memory allocation error\n", COLOR_RED );
        fclose ( File->front_f );

        return ERR_FREAD;
    }

    int ret_code = fread ( File->out_buffer, sizeof( File->out_buffer[0] ),
                           File->file_size, File->front_f );
    if ( ret_code != File->file_size ) {
        if ( feof ( File->front_f ) ) { //! why?
            perror ( "Error reading test.bin: unexpected end of file\n" );
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
        perror ( "buffer memory allocation error\n" );

        return data;
    } // fix error
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
    print_color ( " ( ", COLOR_GREEN );

    Tree_Text_Dump ( tree_node->left  );

    if ( tree_node->type == NODE_TYPE_NUM ) {
        print_color ( "%d", COLOR_GREEN, tree_node->value );
    }
    else if ( tree_node->type == NODE_TYPE_OP ||
              tree_node->type == NODE_TYPE_VAR ) {
        print_color ( "%s", COLOR_GREEN, Get_Op_Name ( tree_node->value ) );
    }

    Tree_Text_Dump ( tree_node->right );

    print_color ( " ) ", COLOR_GREEN );

}

Errors_t Tree_Graph_Dump ( const struct Node_t *tree ) // +
{
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

    static int file_counter = 0;
    const int DUMP_COUNTER = 100;
    char command_buffer[DUMP_COUNTER] = {};
    fprintf( log(), "<img src=\"tree%d.png\" alt=\"-\" width=\"500\" height=\"600\">\n", file_counter );
    sprintf( command_buffer, "dot -T png tree.dot -o logs/tree%d.png", file_counter++ );
    system ( command_buffer );

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

double Eval ( const struct Node_t *node ) // + scanf_s
{
    if ( node == nullptr ) {

        return 0;
    }
    int var_value = 0;

    if ( Search_Var ( node ) == VAR_FOUND ) {
        print_color ( "\nPlease, enter the value of the variable\n", COLOR_YELLOW );
        scanf ( "%d", &var_value );  // scanf_s
    }

    return Eval_Body ( node, var_value );
}

Errors_t Search_Var ( const struct Node_t *node )  // +
{
    if ( node == nullptr ) {

        return VAR_N_FOUND;
    }
    if ( node->type == NODE_TYPE_VAR ) {

        return VAR_FOUND;
    }
    Errors_t left_node_res  = Search_Var ( node->left  );
    Errors_t right_node_res = Search_Var ( node->right );

    if ( left_node_res == VAR_FOUND ||
         right_node_res == VAR_FOUND ) {

        return VAR_FOUND;
    }

    return VAR_N_FOUND;
}

double Eval_Body ( const struct Node_t *node, const int var_value ) // - double or int
{
    if ( node == nullptr ) {

        return 0;
    }
    if ( node->type == NODE_TYPE_NUM ) {

        return node->value;
    }
    else if ( node->type == NODE_TYPE_VAR ) {

        return var_value;
    }

    double left  = Eval_Body ( node->left,  var_value );
    double right = Eval_Body ( node->right, var_value );

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

Node_t *Differentiation ( const struct Node_t *tree )  // -    // node
{
    // allocator оцени
    // calloc blockami
    // code generation

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
                Node_t *tree_c = Create_Node ( NODE_TYPE_OP, OP_ADD, Differentiation ( tree->left ), Differentiation ( tree->right ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_SUB : {
                Node_t *tree_c = Create_Node ( NODE_TYPE_OP, OP_SUB, Differentiation ( tree->left ), Differentiation ( tree->right ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_MUL : {
                Node_t *tree_c = Create_Node ( NODE_TYPE_OP, OP_ADD, Create_Node ( NODE_TYPE_OP, OP_MUL, Differentiation ( tree->left ), Copy_Node ( tree->right ) ),
                                                                     Create_Node ( NODE_TYPE_OP, OP_MUL, Copy_Node ( tree->left ), Differentiation ( tree->right ) ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_DIV : {
                Node_t *tree_c = Create_Node ( NODE_TYPE_OP, OP_DIV, Create_Node ( NODE_TYPE_OP, OP_SUB, Create_Node ( NODE_TYPE_OP, OP_MUL, Differentiation ( tree->left ), Copy_Node ( tree->right ) ),
                                                                                                         Create_Node ( NODE_TYPE_OP, OP_MUL, Copy_Node ( tree->left ), Differentiation ( tree->right ) ) ),
                                                                     Create_Node ( NODE_TYPE_OP, OP_MUL, Copy_Node ( tree->right ), Copy_Node ( tree->right ) ) );
                Optimization ( tree_c );

                return tree_c;
                break;
            }
            case OP_SIN : {
                Node_t *tree_c = Copy_Node ( tree );
                tree_c->value = OP_COS;
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, Differentiation ( tree->right) );
                return tree_c;
                break;
            }
            case OP_COS : {
                Node_t *tree_c = Copy_Node ( tree );
                tree_c->value = OP_SIN;
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, Differentiation ( tree->right) );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, Create_Node ( NODE_TYPE_NUM, -1, nullptr, nullptr ), tree_c );

                return tree_c;
                break;
            }
            case OP_TG  : {
                Node_t *tree_c = Copy_Node ( tree );
                tree_c->value = OP_COS;
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, tree_c );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_DIV, Create_Node ( NODE_TYPE_NUM, 1, nullptr, nullptr ), tree_c );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, Differentiation ( tree->right ) );

                return tree_c;
                break;
            }
            case OP_CTG  : {
                Node_t *tree_c = Copy_Node ( tree );
                tree_c->value = OP_SIN;
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, tree_c );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_DIV, Create_Node ( NODE_TYPE_NUM, -1, nullptr, nullptr ), tree_c );
                tree_c = Create_Node ( NODE_TYPE_OP, OP_MUL, tree_c, Differentiation ( tree->right ) );

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

Node_t *Copy_Node ( const struct Node_t *tree )  // +
{
    if ( tree == nullptr ) {

        return nullptr;
    }

    return Create_Node ( tree->type, tree->value, tree->left, tree->right );
}

int Optimization_Const  ( struct Node_t **tree_node ) // +     // **
{
    if ( *tree_node == nullptr || (*tree_node)->right == nullptr || (*tree_node)->left == nullptr ) {
$
        return 0;
    }
$   if ( (*tree_node)->left->type  == NODE_TYPE_NUM &&
         (*tree_node)->right->type == NODE_TYPE_NUM  ) {

$       (*tree_node)->value = (int)Eval_Body ( *tree_node, 0 );
$       (*tree_node)->type = NODE_TYPE_NUM;
$       Node_Free ( &((*tree_node)->left  ) );
$       Node_Free ( &((*tree_node)->right ) );

        return OK_OCCURR;
    }
    else {
        return ( Optimization_Const ( &((*tree_node)->left) ) ||
                 Optimization_Const ( &((*tree_node)->right ) ) );
    }
}

int Optimization_Option ( struct Node_t **tree_node )  // +-
{
$   if ( *tree_node == nullptr  ) {

        return 0;
    }
$   if ( (*tree_node)->type == NODE_TYPE_OP && (*tree_node)->value == OP_MUL ) {
        if ( (*tree_node)->left->value  == 0 || (*tree_node)->right->value == 0 ) {
$           (*tree_node)->value = 0;
$           (*tree_node)->type  = NODE_TYPE_NUM;
$           Node_Free ( &((*tree_node)->left ) );
$           Node_Free ( &((*tree_node)->right ) );

            return OK_OCCURR;
        }
        if ( (*tree_node)->left->value  == 1 ) {  // func
            Node_Free ( &((*tree_node)->left ) );
            (*tree_node) = (*tree_node)->right;

            return OK_OCCURR;
        }
        else if ( (*tree_node)->right->value == 1 ) {
            Node_Free ( &((*tree_node)->right ) );
            *tree_node = (*tree_node)->left; // for this moment

            return OK_OCCURR;
        }
$
        return 0;
    }
    else {
       return ( Optimization_Option ( &(*tree_node)->left ) ||
                Optimization_Option ( &(*tree_node)->right )  );
    }
}

void Optimization ( struct Node_t *tree_node )
{
    while ( Optimization_Const  ( &tree_node ) || Optimization_Option ( &tree_node ) );
}

void Node_Free ( struct Node_t **tree_node ) // +
{
    if ( tree_node != nullptr && *tree_node != nullptr ) {
        Node_Free ( &((*tree_node)->left) );
        Node_Free ( &((*tree_node)->right));

        (*tree_node)->left = nullptr;
        (*tree_node)->right = nullptr;

        *tree_node = nullptr;
    }
}

Errors_t Diff_Tree_Ctor ( struct File_t *file, struct Tree_t *tree, char *open_file ) // +
{
    file->file_name = open_file;
    Errors_t error_name = File_Reader ( file );
    if ( error_name != OK_FILE ) {

        return ERR_FREAD;
    }
    file->out_buffer = File_Skip_Spaces ( file->out_buffer, file->file_size );
    tree->start_node = Get_General ( file->out_buffer, tree->start_node );

    return OK_FILE;
}

void Diff_Tree_Dtor ( struct File_t *file, struct Tree_t *tree ) // +
{
    Node_Free ( &(tree->start_node) );
    free ( file->out_buffer );
    fclose ( file->front_f );
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

void Print_Latex ( Node_t* node, FILE* latex_file )  // stack
{
    fprintf ( latex_file, "\\[" );

    Print_Latex_Body ( node, latex_file );

    fprintf ( latex_file, "\\]" );
}

void Print_Latex_Body ( Node_t* node, FILE* latex_file)
{
    switch ( node->type )
    {
        case NODE_TYPE_OP  : {
            Latex_Op ( node, latex_file );
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
        default : {
            printf ( "Latex error\n" );
        }
    }
}

void Put_Op ( Node_t* node, FILE* latex_file)
{
    if ( node->value == OP_DIV ) {
        fprintf ( latex_file, "}{" );
    }
    else if ( node->value == OP_MUL ) {
        fprintf ( latex_file, " \\cdot " );
    }
    else {
        fprintf ( latex_file, "%s", Get_Op_Name ( node->value ) );
    }
}

void Latex_Op ( Node_t* node, FILE* latex_file ) // - copy paste
{
    if ( node->value == OP_DIV ) {
        fprintf ( latex_file, " \\frac{" );
    }

    switch ( node->left->type ) {
        case NODE_TYPE_NUM : {
            if ( node->value == OP_MUL && node->left->value == -1 ) {
                fprintf ( latex_file, "-" );
            }
            else {
                fprintf ( latex_file, "%d", node->left->value );
            }
            break;
        }
        case NODE_TYPE_VAR : {
            fprintf ( latex_file, "x" );
            break;
        }
        default: {
            Put_Brackets ( node, latex_file, '(' );
            Print_Latex_Body ( node->left, latex_file );
            Put_Brackets ( node, latex_file, ')');
            break;
        }
    };
    Put_Op ( node, latex_file );

    switch ( node->right->type ) {
        case NODE_TYPE_NUM: {
            fprintf ( latex_file, "%d", node->right->value );
            break;
        }
        case NODE_TYPE_VAR: {
            fprintf ( latex_file, "x" );
            break;
        }
        default: {
            Put_Brackets ( node, latex_file, '(' );
            Print_Latex_Body ( node->right, latex_file );
            Put_Brackets ( node, latex_file, ')' );
            break;
        }
    };

    if ( node->value == OP_DIV ) {
        fprintf ( latex_file, "}" );
    }
}

void Put_Brackets ( Node_t* node, FILE* latex_file, char bracket_type)
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

Node_t *Teylor ( const struct Node_t *tree_node, const int number )
{
    struct Tree_t tree_taylor = {};
    tree_taylor.start_node = Create_Node( NODE_TYPE_NUM, 0, nullptr, nullptr );
    Node_t *taylor_node = Copy_Node ( tree_node );

    int var_value = 0;
    if ( Search_Var ( tree_node ) == VAR_FOUND ) {
        print_color ( "\nEnter the point at which you want to perform the Taylor expansion\n", COLOR_YELLOW );
        scanf ( "%d", &var_value );  // scanf_s
    }

    for ( int i = 0; i <= number; ++i ) {
        tree_taylor.start_node = Create_Node ( NODE_TYPE_OP, OP_ADD, tree_taylor.start_node,
                                                                     Teylor_Body ( taylor_node, i, var_value ) );
    }
    Tree_Graph_Dump ( tree_taylor.start_node );/////////
    Optimization ( tree_taylor.start_node );

    return tree_taylor.start_node;
}

Node_t *Teylor_Body ( const struct Node_t *tree_node, const int member_n, const int variable_val ) // name
{
    Node_t *var_node       = Create_Node ( NODE_TYPE_VAR, OP_VAR, nullptr, nullptr );
    Node_t *power_var_node = Create_Node ( NODE_TYPE_NUM, 1, nullptr, nullptr );  // nameeeeee
    Node_t *dif_node = Copy_Node ( tree_node );

    for ( int i = 0; i < member_n; ++i ) {
        power_var_node = Create_Node ( NODE_TYPE_OP, OP_MUL, var_node, power_var_node );
        dif_node = Differentiation ( dif_node );
    }
    ////////
    Tree_Text_Dump ( dif_node );
    double eval_val = Eval_Body ( dif_node, variable_val );
    printf ( "\n%d\n", (int)eval_val );
    //////
    Node_t *eval_node = Create_Node ( NODE_TYPE_NUM, (int)eval_val / Factorial ( member_n ), nullptr, nullptr );
    //////
    printf ( "\n%g\n", ( eval_val / Factorial ( member_n ) ) ); ///??????????????
    //////
    power_var_node = Create_Node ( NODE_TYPE_OP, OP_MUL, eval_node, power_var_node );

    return power_var_node;
}
