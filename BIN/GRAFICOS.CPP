#include <graphics.h>
#include <iostream.h>
#include<conio.h>
void main()
{
cout<<"hola";
int tarjeta,modo,error;
detectgraph(&tarjeta,&modo);
initgraph(&tarjeta,&modo,"c:\\BC\\BIN");
error=graphresult();
if (error!=0){ cout<<*grapherrormsg(error); getch();}

line(20,60,60,20);
circle(300,200,25);
pieslice(10,20,45,45,60);
getch();
getimage(10,10,60,50,"C:\\dedo.bmp");
putimage(10,10,"C:\\dedo.bmp",3);
closegraph();




getch();
clrscr();

}