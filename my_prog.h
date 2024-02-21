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

int Get_File_Size ( FILE * f );
int Factorial     ( size_t number );
void print_color  ( const char *line, enum Color_t COLOR, ... );

#endif // MY_PROG
