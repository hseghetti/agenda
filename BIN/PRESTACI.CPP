#include<graphics.h>
#include <conio.h>
#include <iostream.h>
#include<dos.h>
void presentacion()
{
    int i=0;int m1=25,m2=15,n1=600,n2=400;
    int gdriver=DETECT, gmode;
    initgraph(&gdriver, &gmode,"c:\\pgr\\");
    int j=630;
    getch();
    for(i=630;i>0;i=i-2){ settextstyle(0,0,7);
                        setcolor(2);
                        outtextxy(i,100,"A G N ©");
                        if(i<580)
                         { if(j<2)j=630;
                           settextstyle(0,0,4);
                           setcolor(14);
                           outtextxy(j,300," by  My-Crosoft ");
                           j=j-5;
                         }
                        cleardevice();
                       }
    setcolor(1);
    setlinestyle(3,1,2);
    setfillstyle(11,2);
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
    setcolor(11);
    cleardevice();
    closegraph();
    restorecrtmode();
    }
