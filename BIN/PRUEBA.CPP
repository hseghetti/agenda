#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
char dispersionx (int &q);
void main()
{
clrscr();
int q=rand ()%5;
char xnom[4],nom;
randomize ();
strcpy(xnom,"       ");
for (int i=0;i<4;i++)
{
nom=dispersionx (q);
xnom[i]=nom;
}
cout<<xnom;getch();
char xxn[4];
strcpy (xxn,"BBBB");
for (i=0;i<4;i++)
{cout<<xnom[i];getch();cout<<" ";xxn[i];getch();xxn[i]=xnom[i];}
cout<<"   "<<xxn;getch();
}


char dispersionx (int &q)
{
int p;char nom;
randomize ();
p=rand () % 5;
while (p==q)
{randomize();p=rand () % 5;}
q=p;
switch(p)
  {
    case 1:nom='x';break;
    case 2:nom='n';break;
    case 3:nom='b';break;
    case 4:nom='v';break;
    case 5:nom='c';break;
    case 0:nom='z';break;
  }
  return (nom);
}
