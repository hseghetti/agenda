#include<graphics.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include<STDLIB.H>
#include<dos.h>
void main()
{
    int i=0;int m1=25,m2=15,n1=600,n2=400;
    int gdriver=DETECT, gmode;
    initgraph(&gdriver, &gmode,"");
    setcolor(1);
    setlinestyle(3,1,2);
    setfillstyle(11,2);
    getch();
    for(i=0;i<151;i++)
    {
    m1++;m2++;
    n1--;n2--;
    rectangle(m1,m2,n1,n2);
    delay(15);
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
    delay(10);
    }
    settextstyle(0,0,7);
    setcolor(1);

    for(i=0;i<10;i++)
    {
    clrscr();
    outtextxy(100,100," A " );//gotoxy(15,20);cout<<"A";
    outtextxy(200,400," G " );//gotoxy(16,21);cout<<"G";
    outtextxy(300,100," E " );//gotoxy(17,20);cout<<"E";
    outtextxy(400,400," N " );//gotoxy(18,21);cout<<"N";
    outtextxy(500,100," D " );//gotoxy(19,20);cout<<"D";
    outtextxy(600,400," A " );//gotoxy(20,21);cout<<"A";
    delay(200);clrscr();
    outtextxy(100,400," A " );//gotoxy(15,20);cout<<"A";
    outtextxy(200,100," G " );//gotoxy(16,21);cout<<"G";
    outtextxy(300,400," E " );//gotoxy(17,20);cout<<"E";
    outtextxy(400,100," N " );//gotoxy(18,21);cout<<"N";
    outtextxy(500,400," D " );//gotoxy(19,20);cout<<"D";
    outtextxy(600,100," A " );//gotoxy(20,21);cout<<"A";
    delay(200);
    clrscr();

    }


    cleardevice();
    closegraph();
    restorecrtmode();
    }
