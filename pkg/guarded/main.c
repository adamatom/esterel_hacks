#include <stdio.h>
#include <stdlib.h>

void GUARDED_O_STOP_Z( int z_loc );
void GUARDED_O_STEP_Z( );
void GUARDED_O_ABORT_Z();
int GUARDED_S_zpos();


#include "guarded.c"

string BUBBLE_ERR = "Too many bubbles!\n";
void GUARDED_O_STOP_Z( int z_loc )
{
    printf("Stopping Z, currently at: %d\n", z_loc );
}

static int zlocation = 0;

void GUARDED_O_STEP_Z()
{
    puts("Advancing Z\n");
    zlocation++;
}

void GUARDED_O_ABORT_Z()
{
    printf("Aborting Z!\n");
}

int GUARDED_S_zpos()
{
    return zlocation;
}

void LOG(string* s)
{
    printf("%s", *s);
}

void help()
{
    puts("Type:\n\t"
            "C - input the cup bottom event\n\t"
            "B - input the bubble event\n\t"
            "q or Q to quit");
}
int main()
{
    char input = 0;
    help();
    GUARDED_reset();
    GUARDED();
    do {
        input = getchar();
        switch( input )
        {
            case 'q':
            case 'Q': return 0;
            case 'C': GUARDED_I_CupBottom(); break;
            case 'B': GUARDED_I_Bubble(); break;
            default: break;
        }
    } while(GUARDED());
}
