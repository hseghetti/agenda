#include <iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>

void main()
{
clrscr();
int dis=0;
int can;
char c[20] ;
cout<<"ingrese cadena";
gets(c);
can=strlen(c);
for (int i=0; i<=can;i++)    dis+=(c[i]%541); 

dis=dis%541;
cout<<dis;
getch();



}