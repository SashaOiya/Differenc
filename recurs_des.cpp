//#include "front.h"
#include "recurs_des.h"

Node_t *GetG ( char *buffer, struct Node_t *Tree ) //const
{
    struct Position_t Position = {};
    Position.data = buffer; // nullptr
    Position.index = 0;
    // free //my_assert
    Tree = GetE( &Position ); // return
    //assert ( Position.data[Position.index] == '\0' );

    return Tree;
}

Node_t *Get_Number ( struct Position_t *Position )
{
    int val = 0;
    int prev_index = Position->index;

    while ( isdigit ( Position->data[Position->index] ) ) {
        val = val * 10 + Position->data[Position->index] - '0';
        ++(Position->index);
    }
    assert ( Position->index > prev_index );

    return Create_Node ( NUM, val, nullptr, nullptr );
}

Node_t *GetId ( struct Position_t *Position )
{
    char arg[20] = {};// name and number
    int counter = 0;
    int old_position = Position->index;

    while ( isalpha ( Position->data[Position->index] ) )  {
        sprintf ( arg + counter, "%c", Position->data[Position->index] );
        (Position->index)++;
        counter++;
    }

    int unary_option = 0;

    if ( !strcmp ( arg, "sin" ) ) {
        unary_option = OP_SIN;
    }
    else if ( !strcmp ( arg, "cos" ) ) {
        unary_option = OP_COS;
    }
    else if ( !strcmp ( arg, "tg" ) ) {
        unary_option = OP_TG;
    }
    else if ( !strcmp ( arg, "ctg" ) ) {
        unary_option = OP_CTG;
    }
    if ( unary_option == OP_SIN ||
         unary_option == OP_COS ||
         unary_option == OP_TG  ||
         unary_option == OP_CTG ) {

        Node_t *val = GetE ( Position );
        (Position->index)++;

        switch ( unary_option ) {
            case OP_SIN : {
                val = Create_Node( OP, OP_SIN, nullptr, val );
                break;
            }
            case OP_COS : {
                val = Create_Node( OP, OP_COS, nullptr, val );
                break;
            }
            case OP_TG  : {
                val = Create_Node( OP, OP_TG , nullptr, val );
                break;
            }
            case OP_CTG : {
                val = Create_Node( OP, OP_CTG, nullptr, val );
                break;
            }
            default : {
                printf ( "Error" );    // more information
                break;
            }
        }

        return val;
    }
    return Create_Node ( VAR, OP_VAR, nullptr, nullptr );
}

Node_t *GetE ( struct Position_t *Position )
{
    Node_t *val = GetT ( Position );

    while ( Position->data[Position->index] == '+' ||
            Position->data[Position->index] == '-' )
    {
        int element = Position->data[Position->index];
        (Position->index)++;
        Node_t *val_2 = GetT ( Position );

        switch ( element ) {
            case '+' : {
                val = Create_Node( OP, OP_ADD, val, val_2 );
                break;
            }
            case '-' : {
                val = Create_Node( OP, OP_SUB, val, val_2 );
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

Node_t *GetT ( struct Position_t *Position )
{
    Node_t *val = GetP ( Position );    // unary

    while ( Position->data[Position->index] == '*' ||
            Position->data[Position->index] == '/' ) {
        char element = Position->data[Position->index];
        (Position->index)++;

        Node_t *val_2 = GetP ( Position );

        switch ( element ) {
            case '*' : {
                val = Create_Node( OP, OP_MUL, val, val_2 );
                break;
            }
            case '/' : {
                val = Create_Node( OP, OP_DIV, val, val_2 );
                break;
            }
            default : {
                printf ( "Error" );    // more information
                break;
            }
        }
    }
    return val;
}

Node_t *GetP ( struct Position_t *Position )
{
    if ( Position->data[Position->index] == '(' ) {
        Node_t *val = nullptr;
        (Position->index)++;
        val = GetE ( Position );

        assert ( Position->data[Position->index] == ')' );
        (Position->index)++;

        return val;
    }
    else if ( isalpha ( Position->data[Position->index] ) ) {

        Node_t *val = GetId ( Position );

        // function Id '(' E ')'

        return val;
    }
    else {

        return Get_Number ( Position );
    }
}

Node_t* GetA ( struct Position_t *Position )
{
    Node_t* val = GetE ( Position );
    //SkipSpaces (data);
    // изменить и не давать ставить знаки сравнения в теле циклов и условных операторов
    if ( Position->data[Position->index] == '=' ||
         Position->data[Position->index] == '>' ||
         Position->data[Position->index] == '<') // добавить больше/меньше
    {
        char operation = Position->data[Position->index];
        (Position->index)++;
        Node_t* val_2 = GetId ( Position );

        return Create_Node( OP, operation, val, val_2 );//NewNode (OP, GetOpCode (operation), val, val2);
    }
    return val;
}


