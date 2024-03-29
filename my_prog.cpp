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

Prog_Mode_t interface_input ( )
{
    const int max_buf_value = 100;
    char buf[max_buf_value] = {};

    print_color ( "Select mode\n", COLOR_BLUE );
    scanf ( "%s", buf );
    getchar ( );

    if ( strcmp( buf, "help" ) == 0 ) {

        print_color ( "Here is a list of supported features :"
                      "\n\n  help  \n\n  bye  \n\n  difference  \n\n \n\n taylot \n\n g_dump \n\n"
                                                                               " \n\n t_dump \n\n", COLOR_BLUE );

        return MODE_HELP;
    }
    else if ( strcmp ( buf, "bye" ) == 0 ) {

        return MODE_BYE;
    }
    else if ( strcmp ( buf, "difference" ) == 0 ) {

        return MODE_DIF;
    }
    else if ( strcmp ( buf, "taylor" ) == 0 ) {

        return MODE_TAYLOR;
    }
    else if ( strcmp ( buf, "g_dump" ) == 0 ) {

        return MODE_G_DUMP;
    }
    else if ( strcmp ( buf, "t_dump" ) == 0 ) {

        return MODE_T_DUMP;
    }
    else {

        print_color ( "This option was not found. Use the list of presented functions:\n", COLOR_RED );

        return MODE_ERROR;
    }

    return MODE_ERROR;
}
