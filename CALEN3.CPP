#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

struct cumple
{
int marc;
char nom[20];
};

struct comp
{
int date;
cumple ca;
char notas[80];
};


struct calen
{
comp  mes[38];
char nommes[15];
char anio[38];
};

void main ()
{
clrscr();
FILE *m=fopen ("calendar","wb");
calen r;char q;int a,b;
q=getch();
while (q!='x')
{
cout<<"Sale con x....";
cout<<" ingersar 1: 2004; 2: 2005";
cin>>a;
cout<<" ingresar el nombre del mes: \n";
gets(r.nommes);
cout<<"Ingresar dias del mes";
for (int i=0;i<38;i++)
  {
  cout<<"Dia "<<i<<"  ";
  cin>>r.mes[i].date;
  r.mes[i].ca.marc=0;
  r.mes[i].notas[0]='&';
  switch (a)
  {case 1:strcpy(r.anio,"2004");break;
   case 2:strcpy(r.anio,"2005");break;}
  }

  cout<<"Queres grabar";
  cin>>b;
  if (b==1) fwrite(&r,sizeof(r),1,m);

cout<<"sale con x";
q=getch();
}
fclose(m);









clrscr();
m=fopen ("calendar","r+b");
fread(&r,sizeof(r),1,m);
gotoxy(2,2);cout<<r.nommes;
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
    gotoxy(h,t);cout<<r.mes[i].date<<" "<<r.mes[i].notas[0];

    }
     h+=10;
  p++;
  }
char w;long pos;

gotoxy(30,18); cout<<" <--- (a) anterior , siguiente (s) ---> ";
cout<<" q Escribir en una fecha/n";
cout<<" e Leer anotacion de un dia/n";
w=getch();
while (w!='x')
{
clrscr();
switch (w)
  {
  case 's':
           fread(&r,sizeof(r),1,m);
           break;
  case 'a':
           pos=ftell(m)-(2 *sizeof(r));
           if (pos>=0)
             {
             fseek(m,pos,SEEK_SET);
             fread(&r,sizeof(r),1,m);
             }
           break;
  }

clrscr();
cout<<r.nommes;
gotoxy(2,4);cout<<"Domingo   Lunes    Martes   Miercoles  Jueves   Viernes    Sabado  ";
int p=0;
int h=4,t=6;
for (int i=0;i<35;i++)
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

gotoxy(20,18); cout<<" <--- (a) anterior , siguiente (s) ---> ";
w=getch();

}
fclose(m);
}





