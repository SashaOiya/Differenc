#include "my_prog.h"
#include "front.h"

int Factorial ( size_t number )
{
    if ( number <= 1 ) {

        return 1;
    }

    return number * Factorial ( number - 1 );
}

void print_color ( const char *line, enum Color_t COLOR, ... )
{
    HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );

    va_list args;
    va_start ( args, COLOR );

    SetConsoleTextAttribute ( hConsole, COLOR );

    vprintf ( line, args );

    SetConsoleTextAttribute ( hConsole, COLOR_WHITE );

    va_end ( args );
}

int Get_File_Size ( FILE * f )
{
    int prev = ftell ( f );

    fseek ( f, 0, SEEK_END );
    size_t size_not_blue = ftell ( f );
    fseek ( f, prev, SEEK_SET );

    return size_not_blue;
}
