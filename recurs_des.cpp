#include "recurs_des.h"
// Change them all (names)

Node_t *Get_General ( char *buffer, struct Node_t *tree_node )
{
    struct Position_t position = {};
    position.data = buffer;
    position.index = 0;
    tree_node = Get_Expression ( &position );

    return tree_node;
}

Node_t *Get_Number ( struct Position_t *position )
{
    int value = 0;
    int prev_index = position->index;

    // strtod???
    while ( isdigit ( position->data[position->index] ) ) {
        value = value * 10 + position->data[position->index] - '0';
        ++(position->index);
    }
    assert ( position->index > prev_index );

    return Create_Node ( NODE_TYPE_NUM, value, nullptr, nullptr );
}

Node_t *Get_Index ( struct Position_t *position )
{
    char op_name[20] = {};

    for ( int counter = 0; isalpha ( position->data[position->index] ); (position->index)++, counter++ )  {
        sprintf ( op_name + counter, "%c", position->data[position->index] );
    }

    int unary_option = 0;
    // #include with #defines maybe
    if ( !strcmp ( op_name, "sin" ) ) {
        unary_option = OP_SIN;
    }
    else if ( !strcmp ( op_name, "cos" ) ) {
        unary_option = OP_COS;
    }
    else if ( !strcmp ( op_name, "tg" ) ) {
        unary_option = OP_TG;
    }
    else if ( !strcmp ( op_name, "ctg" ) ) {
        unary_option = OP_CTG;
    }

    if ( unary_option == OP_SIN || unary_option == OP_COS ||
         unary_option == OP_TG  || unary_option == OP_CTG ) {

        Node_t *exp_node = Get_Expression ( position );
        (position->index)++;

        exp_node = Create_Node( NODE_TYPE_OP, unary_option, nullptr, exp_node );

        return exp_node;
    }

    return Create_Node ( NODE_TYPE_VAR, OP_VAR, nullptr, nullptr );
}

Node_t *Get_Expression ( struct Position_t *position )
{
    Node_t *term_node = Get_Term ( position );

    // В одном месте проверки на + -
    while ( position->data[position->index] == '+' ||
            position->data[position->index] == '-' )
    {
        int element = position->data[position->index];
        (position->index)++;
        Node_t *term_node_right = Get_Term ( position );

        switch ( element ) {
            case '+' : {
                term_node = Create_Node( NODE_TYPE_OP, OP_ADD, term_node, term_node_right );
                break;
            }
            case '-' : {
                term_node = Create_Node( NODE_TYPE_OP, OP_SUB, term_node, term_node_right );
                break;
            }
            default : {
                printf ( "Error" );
                break;
            }
        }
    }
    return term_node;
}

Node_t *Get_Term ( struct Position_t *position )
{
    Node_t *part_node = Get_Partititon ( position );

    while ( position->data[position->index] == '*' ||
            position->data[position->index] == '/' ) {
        char element = position->data[position->index];
        (position->index)++;

        Node_t *part_node_right = Get_Partititon ( position );

        switch ( element ) {
            case '*' : {
                part_node = Create_Node( NODE_TYPE_OP, OP_MUL, part_node, part_node_right );
                break;
            }
            case '/' : {
                part_node = Create_Node( NODE_TYPE_OP, OP_DIV, part_node, part_node_right );
                break;
            }
            default : {
                printf ( "Error" );    // more information
                break;
            }
        }
    }
    return part_node;
}

Node_t *Get_Partititon ( struct Position_t *position )
{
    if ( position->data[position->index] == '(' ) {
        (position->index)++;
        Node_t *exp_node = Get_Expression ( position );

        //assert ( Position->data[Position->index] == ')' );
        (position->index)++;

        return exp_node;
    }
    else if ( isalpha ( position->data[position->index] ) ) {

        return Get_Index ( position );;
    }
    else {

        return Get_Number ( position );
    }
}



