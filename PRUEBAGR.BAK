#include<graphics.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include<STDLIB.H>
#include<dos.h>
void main()
{
    int i=0;int a,b,c,d,m1=25,m2=15,n1=600,n2=400;
    int gdriver=DETECT, gmode;
    initgraph(&gdriver, &gmode,"");
    setlinestyle(0,1,2);
    setfillstyle(11,2);
    for (i=0;i<15;i++)
    {
    a=random(600);b=random(400);c=random(600);d=random(400);
    bar3d(a,b,c,d,40,1);
    delay(200);
    cleardevice();
    }

    //putpixel(15+i,15,2);
                                    //125/115/500/300
    //line(15,20,600,20);
    for(i=0;i<150;i++)
    {
    m1++;m2++;
    n1--;n2--;
    rectangle(m1,m2,n1,n2);
    delay(20);
    }
    for(i=53;i>23;i--){gotoxy(i,14);cout<<" C ";delay(20);}
    for(i=53;i>27;i--){gotoxy(i,14);cout<<" A ";delay(20);}
    for(i=53;i>31;i--){gotoxy(i,14);cout<<" R ";delay(20);}
    for(i=53;i>35;i--){gotoxy(i,14);cout<<" G ";delay(20);}
    for(i=53;i>39;i--){gotoxy(i,14);cout<<" A ";delay(20);}
    for(i=53;i>43;i--){gotoxy(i,14);cout<<" N ";delay(20);}
    for(i=53;i>47;i--){gotoxy(i,14);cout<<" D ";delay(20);}
    for(i=53;i>51;i--){gotoxy(i,14);cout<<" O ";delay(20);}

  //cuando sale
    delay(200);
    for(i=51;i<53;i++){gotoxy(i,14);cout<<" O ";delay(20);}
    for(i=47;i<53;i++){gotoxy(i,14);cout<<" D ";delay(20);}
    for(i=43;i<53;i++){gotoxy(i,14);cout<<" N ";delay(20);}
    for(i=39;i<53;i++){gotoxy(i,14);cout<<" A ";delay(20);}
    for(i=35;i<53;i++){gotoxy(i,14);cout<<" G ";delay(20);}
    for(i=31;i<53;i++){gotoxy(i,14);cout<<" R ";delay(20);}
    for(i=27;i<53;i++){gotoxy(i,14);cout<<" A ";delay(20);}
    for(i=23;i<53;i++){gotoxy(i,14);cout<<" C ";delay(20);}
    gotoxy(51,14);cout<<"   ";

    setcolor(0);
    for(i=0;i<150;i++)
    {
    m1--;m2--;
    n1++;n2++;
    rectangle(m1,m2,n1,n2);
    delay(20);
    }

    cleardevice();







    
    //setbkcolor(15);



	getch();
    //cout<<"HOLAS AMIGOSSSSSSSSSSS";
    //for(i=0;i<10;i++)
    //{
    // gotoxy(i,i);cout<<"hola";
    //delay(150);
    //}


    //getch();


}
