#include "C:\BC\show.h"
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include<string.h>
#include<dos.h>
void main()
{
    int i=0; char msg[20];
    int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode,"");
    //setcolor(2);
    //setbkcolor(15);
	ShowBMP("c:\\age.bmp",0,0);
    getch();
    cout<<"HOLAS AMIGOSSSSSSSSSSS";
    for(i=0;i<10;i++)
    {
     gotoxy(i,i);cout<<"hola";
    delay(150);
    }


    getch();


}
