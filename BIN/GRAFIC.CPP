#include "C:\BC\show.h"
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include<string.h>
main()
{
    int i=0; char msg[20];
    int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode,"");
	ShowBMP("c:\\age.bmp",0,0);
    strcpy(msg,"me salio");
    while(msg)
    {
    putc(msg[i],stdprn);
    i++;
    }
	getch();


}
