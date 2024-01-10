//#include "front.h"
#include "recurs_des.h"

Node_t *GetG ( char *buffer, struct Node_t *Tree ) //const
{
    struct Position_t Position = {};
    Position.data = Skip_Spaces ( buffer );
    Position.index = 0;
    // free //my_assert
    Tree = GetE( &Position ); // return
    assert ( Position.data[Position.index] == '\0' );

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

    /*if ( Position->data[Position->index] == '(' )
    {
        //int func_name_code = SearchFuncName (arg, names);
        //printf ("func_code = %d\n", func_name_code);
        //TreeNode* val = NULL;
        //data->position++;
        Node_t *val = GetE ( Position );
        (Position->index)++;
        return NewNode (FUNC, func_name_code, NULL, val);
    }*/
    if ( strcmp ( data, "if") == 0 ) {
        Node_t *val = GetE ( Position );
        (Position->index)++;

        return Create_Node ( (Option_t)KEY, KEY_W_IF, NULL, val );
    }
    if ( strcmp ( data, "x" ) == 0 ) {

        return Create_Node ( (Option_t)VAR, OP_VAR, nullptr, nullptr );
    }

    return Create_Node ( (Option_t)KEY, KEY_W_DONT, nullptr, nullptr );  // val???
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
    // �������� � �� ������ ������� ����� ��������� � ���� ������ � �������� ����������
    if ( Position->data[Position->index] == '=' ||
         Position->data[Position->index] == '>' ||
         Position->data[Position->index] == '<') // �������� ������/������
    {
        char operation = Position->data[Position->index];
        (Position->index)++;
        Node_t* val_2 = GetId ( Position );
        return Create_Node( (Option_t)OP, operation, val, val_2 );//NewNode (OP, GetOpCode (operation), val, val2);
    }
    return val;
}

