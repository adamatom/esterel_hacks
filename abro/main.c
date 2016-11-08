#include <stdio.h>
#include <stdlib.h>

void ABRO_O_O(void);



#include "abro.c"

string SOME_STRING = "hello, world\n";
void ABRO_O_O(void)
{
    puts("output state firing!\n");
    ABRO_I_R();
}

void print_hello(string* s)
{
    printf("%s", *s);
}

void help()
{
    puts("Type:\n\t"
            "A - input the A event\n\t"
            "B - input the B event \n\t"
            "Z - input A and B simultaneously\n\t"
            "R - input reset event\n\t"
            "q or Q to quit");
}
int main()
{
    char input = 0;
    help();
    ABRO();
    do {
        input = getchar();
        switch( input )
        {
            case 'q':
            case 'Q': return 0;
            case 'A': ABRO_I_A(); break;
            case 'B': ABRO_I_B(); break;
            case 'Z': ABRO_I_A(); ABRO_I_B(); break;
            case 'R': ABRO_I_R(); break;
            case '\n': break;
            default: help();
        }
    } while(ABRO());
}
