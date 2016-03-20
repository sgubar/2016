#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
IntNode *CreateN(int perevod);

void main(int argc, const char * argv[])
{
    int i;

    if (argc==1)
        printf ("Netu chisel\n");

    else

        for ( i=1; i<argc; i++)
            {
            int perevod;
            perevod=atoi(argv[i]);
            CreateN(perevod);
            }

    printf("%c",*argv[2]);

    //system ("pause");
}


