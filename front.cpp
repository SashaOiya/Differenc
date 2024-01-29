#include "recurs_des.h"
#include "front.h"
// Dtor[[[[[[[[[[[[[[[[

FILE *logfile = fopen ( "logs/log.html", "w" );

int main ( int argc, char *argv[] )
{
    struct Tree_t Tree = {};
    struct File_t File = {};

    Diff_Ctor ( argv[1], &File, &Tree );

    Tree_Graph_Dump ( Tree.start );
    Tree_Text_Dump ( Tree.start );

    Node_t *tree_c = d ( Tree.start );  // Tree_c

    Tree_Graph_Dump ( tree_c );
    Tree_Text_Dump ( tree_c );

    free ( File.out_buffer );
    fclose ( File.front_f );

    return 0;
}

Errors_t File_Reader ( struct File_t *File )  // +
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

    int ret_code = fread ( File->out_buffer, sizeof( File->out_buffer[0] ), File->file_size, File->front_f );
    if ( ret_code != File->file_size ) {
        if ( feof ( File->front_f ) ) {
            printf ( "Error reading test.bin: unexpected end of file\n" );
        }
        else if ( ferror ( File->front_f ) ) {
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

    if ( tree_node->type == NUM ) {
        printf ( "%d", tree_node->value );
    }
    else if ( tree_node->type == OP && tree_node->value == OP_SIN ) {
              printf ( "sin" );
    }
    else if ( tree_node->type == OP && tree_node->value == OP_COS ) {
              printf ( "cos" );
    }
    else if ( tree_node->type == OP && tree_node->value == OP_TG  ) {
              printf ( "tg" );
    }
    else if ( tree_node->type == OP && tree_node->value == OP_CTG ) {
              printf ( "ctg" );
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
        fprintf ( tree_dump, " \"%p\" [shape = Mrecord, style = filled, fillcolor = lightpink "
                             " label = \"data: sin \"];\n", tree );    // !!!!!!!!!!!
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

Node_t *d ( const struct Node_t *tree )  // +    // node
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
            case OP_SIN : {
                Node_t *tree_c = c ( tree );
                tree_c->value = OP_COS;
                tree_c = Create_Node ( OP, OP_MUL, tree_c, d ( tree->right) );

                return tree_c;
                break;
            }
            case OP_COS : {
                Node_t *tree_c = c ( tree );
                tree_c->value = OP_SIN;
                tree_c  = Create_Node ( OP, OP_MUL, tree_c, d ( tree->right) );
                tree_c = Create_Node ( OP, OP_MUL, Create_Node ( NUM, -1, nullptr, nullptr ), tree_c );

                return tree_c;
                break;
            }
            case OP_TG  : {
                Node_t *tree_c = c ( tree );
                tree_c->value = OP_COS;
                tree_c = Create_Node ( OP, OP_MUL, tree_c, tree_c );
                tree_c = Create_Node ( OP, OP_DIV, Create_Node ( NUM, 1, nullptr, nullptr ), tree_c );
                tree_c = Create_Node ( OP, OP_MUL, tree_c, d ( tree->right ) );

                return tree_c;
                break;
            }
            case OP_CTG  : {
                Node_t *tree_c = c ( tree );
                tree_c->value = OP_SIN;
                tree_c = Create_Node ( OP, OP_MUL, tree_c, tree_c );
                tree_c = Create_Node ( OP, OP_DIV, Create_Node ( NUM, -1, nullptr, nullptr ), tree_c );
                tree_c = Create_Node ( OP, OP_MUL, tree_c, d ( tree->right ) );

                return tree_c;
                break;
            }
            default    : {
             ///////
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

Errors_t Diff_Ctor ( char *open_file, struct File_t *File, struct Tree_t *Tree ) // +
{
    File->file_name = open_file;
    Errors_t error_name = File_Reader ( File );
    if ( error_name != OK_FILE ) {

        return ERR_FREAD;
    }
    File->out_buffer = File_Skip_Spaces ( File->out_buffer, File->file_size );
    Tree->start = GetG ( File->out_buffer, Tree->start );

    return OK_FILE;
}

/*void PrintLatex (TreeNode* node, FILE* latex_file)
{
    switch (node->type)
    {
        case OP:
            LatexOp (node, latex_file);
            break;
        case FUNC:
            TextFuncName (node->right, latex_file, GetFuncName ((int)node->value));
            break;
        case NUM:
            fprintf (latex_file, "%f", (float)node->value);
            break;
        case VAR:
            fprintf (latex_file, "x");
            break;
    };
}

void TextFuncName (TreeNode* node, FILE* file, char* func_name)
{
    fprintf (file, "%s ", func_name);
    if (node->type != OP || node->value != OP_DIV)
        fprintf (file, "(");
    PrintLatex (node, file);
    if (node->type != OP || node->value != OP_DIV)
        fprintf (file, ")");
}

void LatexOp (TreeNode* node, FILE* latex_file)
{
    if (node->value == OP_DIV)
        fprintf (latex_file, " \\frac{");

    switch (node->left->type)
    {
        case NUM:
        {
            if (node->value == OP_MUL)
            {
                if (node->left->value == -1)
                    fprintf (latex_file, "-");
                else
                    fprintf (latex_file, "%f", (float)node->left->value);
            }
            else
                fprintf (latex_file, "%f", (float)node->left->value);
            break;
        }
        case VAR:
            fprintf (latex_file, "x");
            break;
        default:
        {
            PutBracketsBefore (node, latex_file, '(');
            PrintLatex (node->left, latex_file);
            PutBracketsBefore (node, latex_file, ')');
            break;
        }
    };

    PutOp (node, latex_file);

    switch (node->right->type)
    {
        case NUM:
            fprintf (latex_file, "%f", (float)node->right->value);
            break;
        case VAR:
            fprintf (latex_file, "x");
            break;
        default:
        {
            PutBracketsAfter (node, latex_file, '(');
            PrintLatex (node->right, latex_file);
            PutBracketsAfter (node, latex_file, ')');
            break;
        }
    };

    if (node->value == OP_EXP || node->value == OP_DIV)
        fprintf (latex_file, "}");
}

 */
