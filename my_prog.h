#ifndef MY_PROG
#define MY_PROG

#include <stdio.h>
#include <windows.h>

enum Color_t {
    COLOR_GREEN  = 10,
    COLOR_WHITE  = 15,
    COLOR_RED    =  4,
    COLOR_PINK   = 12,
    COLOR_BLUE   =  9,
    COLOR_YELLOW = 14
};

enum Prog_Mode_t {
    MODE_DIF    = 1,
    MODE_G_DUMP = 2,
    MODE_T_DUMP = 5,
    MODE_TAYLOR = 3,
    MODE_BYE    = 4,
    MODE_ERROR  = 5,
    MODE_HELP   = 6,
};

int Get_File_Size ( FILE * f );
int Factorial     ( size_t number );
void print_color  ( const char *line, enum Color_t COLOR, ... );
Prog_Mode_t interface_input ( );

#endif // MY_PROG
