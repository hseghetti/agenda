#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>
#include "c:\bc\bin\aaa.cpp"

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
int escribir(calen& r);
void leernota (calen r);
int borrar(calen &r);

void main()
{
clrscr();
char m,us[20],pas[20],pas2[20];FILE *f;int i=0;
int M;
do
{
cout<<"Ingrese Opci�n de Usuario\n";
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
    case '3'://Elimina Registro
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
cout<<"Ingrese Opci�n de Usuario\n";
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
FILE * m,*k;
calen r;
char w;long pos,pos2;
m=fopen ("calendar","r+b");
k=fopen("c:\\has\\lalala.dat","wb");
pos=ftell(m);
fread(&r,sizeof(r),1,m);
visualcalen(r,w);
while (w!='x')
{
clrscr();
switch (w)
  {
  case 's': //posterior
           pos=ftell(m);
           fread(&r,sizeof(r),1,m);
           visualcalen(r,w);
           break;
  case 'a': //anterior
           pos=ftell(m)-(2 *sizeof(r));
           if (pos>=0)
             {
             rewind(m);
             fseek(m,pos,SEEK_SET);
             fread(&r,sizeof(r),1,m);
             }
           visualcalen(r,w);
           break;
  case 'e': //escribir
            if(escribir(r)==1)
            {
            pos2=ftell(m)-(1 *sizeof(r));
            if(pos2==0)rewind(m); else fseek(m,pos2,SEEK_SET);
            fwrite(&r,sizeof(r),1,m);
            rewind(m);
            fseek(m,pos,SEEK_SET);
            fread(&r,sizeof(r),1,m);
            }
            clrscr();
            visualcalen(r,w);
            break;
  case 'l': //leer anotaciones
            leernota (r);
            clrscr();
            visualcalen(r,w);
            break;
  case 'b'://borrar anotaciones
           if(borrar(r)==1)
            {
            pos2=ftell(m)-(1 *sizeof(r));
            if(pos2==0)rewind(m); else fseek(m,pos2,SEEK_SET);
            fwrite(&r,sizeof(r),1,m);
            rewind(m);
            fseek(m,pos,SEEK_SET);
            fread(&r,sizeof(r),1,m);
            }
           clrscr();
           visualcalen(r,w);
           break;

  }

clrscr();

}
fclose(m);
}

void visualcalen (calen r,char &w)
{
int tar,modo;
detectgraph(&tar,&modo);
initgraph(&tar,&modo,"");
//lineas horizontales
line(6,10,550,10);line(6,35,550,35);line(6,74,550,74);line(6,105,550,105);line(6,136,550,136);
line(6,168,550,168);line(6,198,550,198);line(6,230,550,230);line(6,262,550,262);
//lineas verticales
line(6,10,6,262);line(77,10,77,262);line(148,10,148,262);line(225,10,225,262);
line(311,10,311,262);line(386,10,386,262);line(472,10,472,262);line(550,10,550,262);
//dias
gotoxy(2,2);cout<<r.nommes;
gotoxy(13,2);cout<<r.anio;
gotoxy(2,4);cout<<"Domingo";
gotoxy(12,4);cout<<" Lunes";
gotoxy(20,4);cout<<" Martes";
gotoxy(30,4);cout<<"Miercoles";
gotoxy(41,4);cout<<"Jueves";
gotoxy(50,4);cout<<" Viernes";
gotoxy(61,4);cout<<"Sabado";

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
          if(r.mes[i].ca.marc==1)
          {
          gotoxy(h-1,t);cout<<"�";
          gotoxy(h-1,t-1);cout<<"�";
          gotoxy(h-1,t+1);cout<<"�";
          gotoxy(h,t-1);cout<<"��";
          gotoxy(h,t+1);cout<<"��";
          gotoxy(h+2,t);cout<<"�";
          gotoxy(h+2,t-1);cout<<"�";
          gotoxy(h+2,t+1);cout<<"�";
          }

    }
     h+=10;
  p++;
  }
gotoxy(20,19); cout<<" <--- (A) anterior , siguiente (S) ---> ";
gotoxy(20,20); cout<<" (E) escribir anotacion ";
gotoxy(20,21); cout<<" (L) leer anotacion ";
gotoxy(20,22); cout<<" (B) Borrar" ;
gotoxy(20,23); cout<<" (X) Salir";
do
{
w=getche();
w=toupper(w);
}
while(w!='A' && w!='S' && w!='E' &&w!='L' &&w!='X' &&w!='B');
closegraph();
restorecrtmode();
}

int escribir(calen &r)
{
int f;char o;
cout<<"Ingrese fecha de anotacion";
cin>>f;
for (int i=0;i<38 && r.mes[i].date!=f;i++);
if (i==38)
{clrscr();gotoxy(1,1);cout<<"ingreso mal la fecha";}
else
  {
  cout<<"\nAgendar:   (C) Cumple A�os    (A) Anotacion    (S)Salir";
  do
  cin>>o;
  while(o!='c' && o!='a' && o!='s');
  clrscr();
  switch (o)
  {
  case 'a'://Anotacion
           char o=' ';
           if(r.mes[i].notas[0]!='&')
           {
           do
             {
             cout<<"Si realiza una nueva anotacion se perderan las notas anteriores";
             cout<<"\n�Desea continuar? (S) Si  (N) No";
             cin>>o;o=toupper(o);
             }while(o!='S'&&o!='N');
           }
           if(o=='N')break;
           cout<<"\nEmpeza a escribir\n";
           gets(r.mes[i].notas);
           break;
  case 'c'://cumple a�os
           o=' ';
           if(r.mes[i].ca.marc==1)
           {
           do
             {
             cout<<"\nSi realiza una nueva anotacion se perderan las notas anteriores";
             cout<<"\n�Desea continuar? (S) Si  (N) No";
             cin>>o;o=toupper(o);
             }while(o!='S'&& o!='N');
           }
           if(o=='N')break;
           cout<<"\nNombre de Cumpla�ero\n";
           gets(r.mes[i].ca.nom);
           r.mes[i].ca.marc=1;
           break;
  case 's':return 0;

  }

  }
return 1;
}

void leernota (calen r)
{
int d,band=0;
cout<<"\nIngrese Dia a leer\n";
cin>>d;
for (int i=0;i<38 && r.mes[i].date!=d;i++);
if (i==38)
{clrscr();gotoxy(1,1);cout<<"ingreso mal la fecha";getch();}
else
{
if(r.mes[i].ca.marc==1)
  {
  clrscr();band=1;
  cout<<"\nNo Olvides Saludar a  "<<r.mes[i].ca.nom<<" \n por que hoy Cumple A�os...\n";getch();
  }
if(r.mes[i].notas[0]!='&')
  {
  clrscr();band=1;
  cout<<r.mes[i].notas;getch();
  }
  if(band==0){ cout<<"\nEste dia no tiene anotaciones...";getch();}
}


}
int borrar(calen &r)
{
int d;
clrscr();
char o;
cout<<"(A) Borrar Anotaciones   (C)Borrar Cumplea�os  (S) Salir";
do
  {
  o=getche();
  o=toupper(o);
  }
while(o!='A' && o!='C' && o!='S');
cout<<"\nIngrese Fecha de la Anotacion/Cumplea�os\n";
cin>>d;
for (int i=0;i<38 && r.mes[i].date!=d;i++);
if (i==38)
{clrscr();gotoxy(1,1);cout<<"ingreso mal la fecha";getch();}
else
{
switch(o)
{
case 'A'://borrar anotacion
         r.mes[i].notas[0]='&';
         return 1;

case 'C': //borrar cumple�os
         r.mes[i].ca.marc=0;
         return 1;

case 'S'://salir
         return 0;

}

}
return 0;
}













