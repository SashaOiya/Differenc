//#include "front.h"
#include "recurs_des.h"

Node_t *GetG ( char *buffer, struct Node_t *Tree ) //const
{
    struct Position_t Position = {};
    Position.data = Skip_Spaces ( buffer );
    Position.index = 0;
    // free //my_assert
    Tree = GetE( &Position ); // return
    //Tree = GetA( &Position );
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

    return Create_Node ( (Option_t)NUM, val, nullptr, nullptr );
}

Node_t *GetId ( struct Position_t *Position )
{
    char data[50] = {};//size
    int prev_index = Position->index;

    for ( int i = 0; isalpha( Position->data[Position->index] ); ) {
        data[i++] = Position->data[Position->index];
        ++(Position->index);
    }
    assert ( Position->index > prev_index );
    if ( strcmp ( data, "x" ) == 0 ) {
        Node_t *val_2 = GetA ( Position );
        if ( val_2 != nullptr ) {
            return val_2;
        }

        return Create_Node ( (Option_t)VAR, OP_VAR, nullptr, nullptr );
    }
    else if ( strcmp ( data, "if" ) == 0 ) {
        /*while ( Position->data[Position->index] == ' '  ||     //krivooooooooooo
                Position->data[Position->index] == '\t' ||
                Position->data[Position->index] == '\n' ) {

        ++(Position->index);
        }*/
        Node_t *val_2 = GetA ( Position );
        assert ( Position->data[++(Position->index)] == ')' );
        val_2->type = KEY;
        val_2->value = KEY_W_IF;

        return val_2;//Create_Node ( (Option_t)KEY, KEY_W_IF, nullptr, nullptr );
    }
    printf ( "NO X\n" );

    return nullptr;  // val???
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

Node_t *GetT ( struct Position_t *Position )
{
    Node_t *val = GetP ( Position );

    while ( Position->data[Position->index] == '*' ||
            Position->data[Position->index] == '/' ) {
        char element = Position->data[Position->index];
        (Position->index)++;

        Node_t *val_2 = GetP ( Position );

        switch ( element ) {
            case '*' : {
                val = Create_Node( (Option_t)OP, OP_MUL, val, val_2 );
                break;
            }
            case '/' : {
                val = Create_Node( (Option_t)OP, OP_DIV, val, val_2 );
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
        ++(Position->index); // ()++
        if ( isdigit ( Position->data[Position->index] ) ) {
            val = GetE ( Position );
        }
        else if ( isalpha ( Position->data[Position->index] ) ) {
            val = GetId ( Position );       // x if while d
            printf ( "goood\n" ); //
        }
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

        return GetE ( Position );  // get_n
    }
}

Node_t *GetA ( struct Position_t *Position )
{
    Node_t *val = GetId ( Position );     // only_X
    assert ( val != nullptr ); // assert

    ++(Position->index);
    if ( Position->data[Position->index] == '=' ) {
        ++(Position->index);
        Node_t *val_2 = GetE ( Position );      //  |
                                                //  |
        val->value = (int)Eval ( val_2 );//int  //  ^

        return val;
    }

    return nullptr;
}

/*Node_t *GetIf ( struct Position_t *Position )
{
    Node_t *val = GetId ( Position );
    assert ( val != nullptr ); // assert
 */

