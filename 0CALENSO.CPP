#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>

struct cumple
{
int marc;
char nom[20];
};
struct comp
{
int date;
cumple ca;
char notas[200];
};


struct calen
{
comp  mes[38];
char nommes[15];
char anio[5];
};


void visualcalen (calen r,char &w);

void main()
{
clrscr();
FILE * m;
calen r;
m=fopen ("c:\\calendar","r+b");
fread(&r,sizeof(r),1,m);

char w;long pos;
visualcalen(r,w);
gotoxy(30,18); cout<<" <--- (a) anterior , siguiente (s) ---> ";
gotoxy(30,20); cout<<" (e) escribir anotacion ";
w=getch();
while (w!='x')
{
clrscr();
switch (w)
  {
  case 's': //posterior
           fread(&r,sizeof(r),1,m);
           visualcalen(r,w);
           break;
  case 'a': //anterior
           pos=ftell(m)-(2 *sizeof(r));
           if (pos>=0)
             {
             fseek(m,pos,SEEK_SET);
             fread(&r,sizeof(r),1,m);
             }
           visualcalen(r,w);
           break;
  case 'e':fclose(m);
           exit(1);

  }

clrscr();

}
fclose(m);
}


void visualcalen (calen r,char &w)
{
gotoxy(2,2);cout<<r.nommes;
gotoxy(13,2);cout<<r.anio;
gotoxy(2,4);cout<<"Domingo   Lunes    Martes   Miercoles  Jueves   Viernes    Sabado  ";
int p=0;
int h=4,t=6;
for (int i=0;i<38;i++)
  {
  if (r.mes[i].date!=-1)
    {
    if (p==7)
      {
      p=0;
      t=t+2;
      h=4;
      }
    gotoxy(h,t);cout<<r.mes[i].date;

    }
     h+=10;
  p++;
  }
gotoxy(30,18); cout<<" <--- (a) anterior , siguiente (s) ---> ";
gotoxy(30,20); cout<<" (e) escribir anotacion ";
w=getch();
}