#include <stdio.h>

int main ()
{
    FILE *f = fopen ( "test.txt", "r" );

    char word[10] = {};

    int i = 0;

    if ( ( i = fscanf ( f, "%s", &word ) ) == 0 || i == EOF ) {
        printf ( "error" );
    }

    return 0;
}
