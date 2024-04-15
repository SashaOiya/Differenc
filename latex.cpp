#include "latex.h"

void Print_Latex ( Node_t* node, FILE* latex_file )  // stack
{
    fprintf ( latex_file, "\n\\[" );

    Print_Latex_Body ( node, latex_file );

    fprintf ( latex_file, "\\]\n" );
}

void Print_Latex_Body ( Node_t* node, FILE* latex_file )
{
    assert ( node != nullptr );
    assert ( latex_file != nullptr );

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

void Put_Op ( Node_t* node, FILE* latex_file )
{
    if ( node->value == OP_DIV ) {
        fprintf ( latex_file, "}{" );
    }
    else if ( node->value == OP_MUL ) {
        fprintf ( latex_file, " \\cdot " );
    }
    else {
$        fprintf ( latex_file, "%s", Get_Op_Name ( node->value ) );
$
    }
}

void Latex_Op ( Node_t* node, FILE* latex_file ) // -
{
    if ( node == nullptr ) {
$
        return ;
    }
    if ( node->value == OP_DIV ) {
        fprintf ( latex_file, " \\frac{" );
    }
    if ( node->left != nullptr ) {
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
            case NODE_TYPE_OP : {
                Put_Brackets ( node, latex_file, '(' );
                Print_Latex_Body ( node->left, latex_file );
                Put_Brackets ( node, latex_file, ')');
                break;
            }
            default : {
                break;
            }
        }
    }
    Put_Op ( node, latex_file );

    if ( node->right != nullptr ) {
        switch ( node->right->type ) {
            case NODE_TYPE_NUM : {
                fprintf ( latex_file, "%d", node->right->value );
                break;
            }
            case NODE_TYPE_VAR : {
                fprintf ( latex_file, "x" );
                break;
            }
            case NODE_TYPE_OP  : {
                Put_Brackets ( node, latex_file, '(' );
                Print_Latex_Body ( node->right, latex_file );
                Put_Brackets ( node, latex_file, ')' );
                break;
            }
            default : {
                break;
            }
        }
        }
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
