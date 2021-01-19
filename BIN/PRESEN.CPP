#include <iostream.h>
#include <dos.h>
#include <conio.h>
void main()
{
int i,t;
t=0;
gotoxy(19,5);cout<<"ษออออออออออออออออออออป";
gotoxy(19,6);cout<<"บ                    บ";
gotoxy(19,7);cout<<"ศออออออออออออออออออออผ";

for (i=34;i>20;i--)
{
gotoxy(i,3);cout<<"C ";
delay(100);
}

for (i=34;i>22;i--)
{
gotoxy(i,3);cout<<"A ";
delay(100);
}

for (i=34;i>24;i--)
{
gotoxy(i,3);cout<<"R ";
delay(100);
}

for (i=34;i>26;i--)
{
gotoxy(i,3);cout<<"G ";
delay(100);
}

for (i=34;i>28;i--)
{
gotoxy(i,3);cout<<"A ";
delay(100);
}

for (i=34;i>30;i--)
{
gotoxy(i,3);cout<<"N ";
delay(100);
}

for (i=34;i>32;i--)
{
gotoxy(i,3);cout<<"D ";
delay(100);
}

for (i=37;i>34;i--)
{
gotoxy(i,3);cout<<"O ";
delay(100);
}

for (i=20;i<40; i++)
{
t++;
gotoxy(i,6);cout<<"ฒ";
gotoxy(29,8);cout<<  t*5 ;
delay(300);
}
getch();
clrscr();
}

