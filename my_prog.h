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

enum Errors_t {
    OK_TREE     = 0,
    ERR_FREAD   = 1,
    ERR_INPUT   = 2,
    ERR_FOPEN   = 3,
    ERR_RLINE   = 4,
    ERR_CALLO   = 5,
    ERR_CYCLE   = 6,
    ERR_CTYPE   = 7,
    OK_FILE     = 8,
    OK_OCCURR   = 9,
    VAR_FOUND   = 10,
    VAR_N_FOUND = 11
};

int Get_File_Size ( FILE * f );
int Factorial     ( size_t number );
void print_color  ( const char *line, enum Color_t COLOR, ... );
char *   File_Skip_Spaces ( char *data, int file_size );
Errors_t File_Reader      ( struct File_t *File );

Prog_Mode_t interface_input ( );

#endif // MY_PROG
