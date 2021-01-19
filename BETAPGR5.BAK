#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>
#include "c:\bc\bin\agenda.h"

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


void calendario ();
void visualcalen (calen r,char &w);
int escribir(FILE *m);

void main()
{
clrscr();
char m,us[20],pas[20],pas2[20];FILE *f;int i=0;
int M;
do
{
cout<<"Ingrese Opci¢n de Usuario\n";
cout<<" 1 Crear Nuevo Usuario\n";
cout<<" 2 Usuario existente\n";
cout<<" 3 Salir del programa\n";
cin>>M;
}
while (M<1 || M>3);

while (M!=9)
{
switch(M)
  {
  case 1://Crear nuevo usuario
           strcpy (us,newus());
           cerear(us);
           break;
  case 2://Usuario existente
            cout<<"\nIngrese el nombre de Usuario";
           gets(us);
           f=fopen(us,"rb");
           if(f==NULL) {cout<<"\nUsuario Inexistente";getch();exit(1);}
           else
           {
           cout<<"\ningrese pasword";
           gets(pas);
           fseek(f,540*sizeof(agenda),SEEK_SET);
           fread(&pas2,sizeof(pas2),1,f);
           if(strcmp(pas,pas2)!=0)
           {
           for(i=0;i<2;i++)
             {
             cout<<"\ningrese pasword";
             gets(pas);
             if(strcmp(pas,pas2)==0)
             break;
             }
           if(i==2)exit(1);
           }
           }
           break;

  case 3://Salir del programa
           exit(1);
           break;
  }
do
{
  clrscr();
  cout<<"ingresar opcion\n";
  cout<<" 1 ingresar registro\n";
  cout<<" 2 buscar registro\n";
  cout<<" 3 eliminar registro\n";
  cout<<" 4 ingresar al calendario\n";
  cout<<" Sale con 'x'\n ";
  cin>>m;
  switch(m)
    {
    case '1'://Nuevo registro
             newreg(us);
             break;
    case '2'://Buscar registro
             buscar (us);
             break;
    case '3'://Elimina Registro en forma logica
	         eliminar(us);
             break;
    case '4'://calendario
             calendario ();
             break;
    }
}
while (m!='x');
clrscr();


do
{
cout<<"Ingrese Opci¢n de Usuario\n";
cout<<" 1 Crear Nuevo Usuario\n";
cout<<" 2 Usuario existente\n";
cout<<" 3 Salir del programa\n";
cin>>M;
}
while (M<1 || M>3);

}

}



void calendario ()
{
clrscr();
FILE * m;
calen r;
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
gotoxy(30,20); cout<<" (e) escribir anotacion ";
w=getch();
while (w!='x')
{
clrscr();
switch (w)
  {
  case 's': //posterior
           fread(&r,sizeof(r),1,m);
           break;
  case 'a': //anterior
           pos=ftell(m)-(2 *sizeof(r));
           if (pos>=0)
             {
             fseek(m,pos,SEEK_SET);
             fread(&r,sizeof(r),1,m);
             }
           break;
  case 'e'://anotacion
           escribir(m);
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




int escribir(FILE *m)
{
calen r;
int f;char o;
long pos;
cout<<"/nIngrese fecha de anotacion";
cin>>f;
cout<<"/n ¨Esta seguro de hacer la anotacion?  (S) Si / (N) No " ;
cin>>o;
if (o=='n')return 0;
pos=(ftell(m)-sizeof(r));
fseek (m,pos*sizeof(r),SEEK_SET);
fread (&r,sizeof(r),1,m);
for (int i=0;i<38 && r.mes[i].date!=f;i++);
if (i==38)
{clrscr();gotoxy(1,1);cout<<"ingreso mal la fecha";}
else
  {
  char car='z';
  cout<<"Empeza a escribir";
  for (int j=0;j<80 && (r.mes[i].notas[j]!='*' || car!='*');i++)
    {
    car=r.mes[i].notas[j];
    r.mes[i].notas[j]=getche();
    }
  }
return 1;
}