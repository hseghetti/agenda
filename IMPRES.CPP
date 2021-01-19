#include <stdio.h>
#include <string.h>
#include <iostream.h>
#include <conio.h>
void main()
{
char * v=new char[100];
char * p=new char[100];
//int can,
int i=0;
cin>>p;

strcpy(v,p);
getch();
while (v[i])
putc(v[i++], stdout);

// for(int i=0;i<=can;i++)
// putc(v[i],stdprn);
cout<<"final";
getch();
clrscr();
delete v;
}



