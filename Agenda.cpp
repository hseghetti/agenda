#include <iostream.h>
#include <conio.h>
#include <graphics2.lib>
#include <pgchart.lib>
#include <dos.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>

struct agenda
{
char ape[50],nom[50];
char dir[90],tel[30];
char mail[50];int flag;
int prox;
};
struct cumple
{
int marc;
char nom[50];
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




void cerear (char us[20]);
char *newus ();
void newreg (char us[20]);
int dispersion (char ape[20]);
int dispersionII ();
void buscar (char us[20]);
void modificar (char us[20],int pos,agenda r);
void calendario (char cnom[8]);
void visualcalen (calen r,char &w);
int escribir(calen& r);
void leernota (calen r);
int borrar(calen &r);
void alfabeta (char us[20]);
void renom (char cnom[8]);
void ver();
void ver2();
void ver3(int x1,int y1,int x2,int y2,int d);
void presentacion();


char *newus ()
{
char f[20],pas[20],pas2[20];
ver();
gotoxy(22,16);cout<<"Ingrese el nombre de nuevo Usuario ";
gotoxy(23,17);gets(f);
FILE *m=fopen(f,"wb");
if (m==NULL) {gotoxy(22,16);cout<<"  error  al  abrir  el archivo";exit (1);}
else
{
fseek(m,540*sizeof(agenda),SEEK_SET);
do
{
gotoxy(28,19);cout<<"Ingrese  pasword        ";
gotoxy(25,20);gets(pas);
gotoxy(28,19);cout<<"Confirme pasword        ";
gotoxy(25,20);cout<<"                              ";
gotoxy(25,20);gets(pas2);
if(strcmp(pas,pas2)!=0){gotoxy(28,19);cout<<"No coinciden los Pasword";getch();}
}
while(strcmp(pas,pas2)!=0);
fwrite(&pas,sizeof(pas),1,m);
fclose(m);
}
return (f);
}


void cerear (char us[20])
{
FILE *m=fopen (us,"r+b");
if (m==NULL){gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
else
  {
  agenda r;
  for (int i=0;i<540;i++)
    {
    strcpy(r.ape,"vacio");
    r.flag=0;
    r.prox=-1;
    fwrite (&r,sizeof(r),1,m);
    }
  fclose(m);
  }
}


void newreg (char us[20])
{
FILE *m=fopen (us,"r+b");
if (m==NULL) {gotoxy(1,1);cout<<"error al abrir el archivo";exit (1);}
else
  {
  agenda r,s,t;
  int pos,aux;
  clrscr();
  ver2();
  gotoxy(12,9); cout<<"Ingrese Apellido   -->";
  gotoxy(36,9); gets(t.ape);
  gotoxy(12,11);cout<<"Ingrese Nombre     -->";
  gotoxy(36,11);gets(t.nom);
  gotoxy(12,13);cout<<"Ingrese Direccion  -->";
  gotoxy(36,13);gets(t.dir);
  gotoxy(12,15);cout<<"Ingrese Telefono   -->";
  gotoxy(36,15);gets(t.tel);
  gotoxy(12,17);cout<<"Ingrese e-mail     -->";
  gotoxy(36,17);gets(t.mail);
  t.prox=-1;t.flag=0;
  pos=dispersion (t.ape);
  fseek (m,pos*sizeof(r),SEEK_SET);
  fread (&r,sizeof(r),1,m);
  if (strcmp(r.ape,"vacio")==0)//si esta vacio
    {
    fseek (m,pos*sizeof(t),SEEK_SET);
    fwrite (&t,sizeof(t),1,m);
    }
  else
    {
    aux=pos;
    while (r.prox!=-1)
      {
      aux=r.prox;
      fseek (m,r.prox*sizeof(r),SEEK_SET);
      fread (&r,sizeof(r),1,m);
      }
    pos=dispersionII();
    fseek (m,pos*sizeof(s),SEEK_SET);
    fread (&s,sizeof(s),1,m);
    while (strcmp(s.ape,"vacio")!=0)
      {
      pos=dispersionII();
      fseek (m,pos*sizeof(s),SEEK_SET);
      fread (&s,sizeof(s),1,m);
      }

    fseek (m,pos*sizeof(s),SEEK_SET);
    fwrite (&t,sizeof(t),1,m);
    r.prox=pos;
    fseek (m,aux*sizeof(r),SEEK_SET);
    fwrite (&r,sizeof(r),1,m);
    }
    fclose(m);
  }
}



int dispersion (char ape[20])
{
int can,dis=0;
can=strlen(ape);
for (int i=0; i<=can;i++) dis+=(ape[i]%103);
dis=dis%103;
return (dis);
}


int dispersionII ()
{
int r;
randomize();
r=(rand()%540);
while (r<103 || r>540) r=(rand()%540);
return (r);
}

void buscar(char us[20])
{
FILE *f=fopen(us,"r+b");
if (f==NULL){gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1); }
else
  {
  agenda r;char ape[20];char nom[20];int pos,posII;
  clrscr();
  ver3(20,2,60,8,10);
  gotoxy(25,3);cout<<"Ingrese Apellido a Buscar";
  gotoxy(25,4);gets(ape);
  gotoxy(25,6);cout<<"Ingrese Nombre a Buscar";
  gotoxy(25,7);gets(nom);
  pos=dispersion(ape);
  fseek(f,pos*sizeof(r),SEEK_SET);
  fread(&r,sizeof(r),1,f);
  posII=pos;
  while((strcmp(ape,r.ape)!=0 || strcmp(nom,r.nom)!=0) && r.prox!=-1)
    {
    posII=r.prox;
    fseek(f,r.prox*sizeof(r),SEEK_SET);
    fread(&r,sizeof(r),1,f);
    }
   if(strcmp(ape,r.ape)==0 && strcmp(nom,r.nom)==0)
   {
     ver2();
     gotoxy(12,9); cout<<" A p e l l i d o   -->";
     gotoxy(36,9);cout<<r.ape;
     gotoxy(12,11);cout<<"   N o m b r e     -->";
     gotoxy(36,11);cout<<r.nom;
     gotoxy(12,13);cout<<"D i r e c c i o n  -->";
     gotoxy(36,13);cout<<r.dir;
     gotoxy(12,15);cout<<" T e l e f o n o   -->";
     gotoxy(36,15);cout<<r.tel;
     gotoxy(12,17);cout<<"   e - m a i l     -->";
     gotoxy(36,17);cout<<r.mail;

     fclose(f);
     modificar (us,posII,r);
    }
   else {ver3(20,2,60,8,1);
         gotoxy(25,3);cout<<" No se encontro registro          ";
         gotoxy(25,4);cout<<"                                  ";
         gotoxy(25,6);cout<<"                                  ";
         gotoxy(25,7);cout<<"Presione una tecla para continuar ";
         getch(); }
  fclose(f);
  }
}

void modificar(char us[20],int pos,agenda r)
{
  FILE *f=fopen(us,"r+b");
  if (f==NULL) {gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
  else
  {
  char x;
  ver3(20,22,57,24,5);
  gotoxy(21,23);cout<<" (M) Para  Modificar  Datos  ";
  x=getche();
  x=tolower(x);
  if(x=='m')
   {
  clrscr();
  ver2();
  gotoxy(12,10);cout<<"Ingrese Nombre     -->";
  gotoxy(36,10);gets(r.nom);
  gotoxy(12,12);cout<<"Ingrese Direccion  -->";
  gotoxy(36,12);gets(r.dir);
  gotoxy(12,14);cout<<"Ingrese Telefono   -->";
  gotoxy(36,14);gets(r.tel);
  gotoxy(12,16);cout<<"Ingrese e-mail     -->";
  gotoxy(36,16);gets(r.mail);
   fseek(f,pos*sizeof(r),SEEK_SET);
   fwrite(&r,sizeof(r),1,f);
   }
   fclose(f);
   }
}



void eliminar (char us[20])
{
FILE *m=fopen (us,"r+b");
if (m==NULL) {gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
else
  {
  char ape[20],nom[20];
  agenda r,a;int pos,aux,aux2;
  clrscr();
  ver3(20,2,60,8,10);
  gotoxy(25,3);cout<<"Ingrese Apellido a Buscar";
  gotoxy(25,4);gets(ape);
  gotoxy(25,6);cout<<"Ingrese Nombre a Buscar";
  gotoxy(25,7);gets(nom);
  pos=dispersion(ape);
  fseek(m,pos*sizeof(r),SEEK_SET);
  fread(&r,sizeof(r),1,m);

   while((strcmp(ape,r.ape)!=0 || strcmp(nom,r.nom)!=0) && r.prox!=-1)
    {
    aux=pos;
    pos=r.prox;
    fseek(m,pos*sizeof(r),SEEK_SET);
    fread(&r,sizeof(r),1,m);
    }
   if(strcmp(ape,r.ape)==0 && strcmp(nom,r.nom)==0)
    {
      char c;
      ver3(15,10,65,12,5);
      gotoxy(16,11);cout<<"�Confirma la eliminacion del registro (S / N) ?";
      do
      {  gotoxy(64,11);c=getche();
	 c=tolower(c);
      }
      while(c!='s'&& c!='n');
      if (c=='s')
	if (pos<103)//Es cabecera
	  if (r.prox==-1)
	    {
	    strcpy(r.ape,"vacio");r.prox=-1;
	    fseek(m,pos*sizeof(r),SEEK_SET);
	    fwrite(&r,sizeof(r),1,m);
	    }
	  else
	    {
	    fseek(m,pos*sizeof(r),SEEK_SET);
	    fread(&r,sizeof(r),1,m);
	    aux2=r.prox;
	    fseek(m,aux2*sizeof(r),SEEK_SET);
	    fread(&a,sizeof(a),1,m);
	    r=a;
	    strcpy(a.ape,"vacio");a.prox=-1;
	    fseek(m,aux2*sizeof(r),SEEK_SET);
	    fwrite(&a,sizeof(a),1,m);
	    fseek(m,pos*sizeof(r),SEEK_SET);
	    fwrite(&r,sizeof(r),1,m);
	    }
	else
	  {
	  fseek(m,pos*sizeof(r),SEEK_SET);
	  fread(&r,sizeof(r),1,m);
	  aux2=r.prox;
	  strcpy(r.ape,"vacio");r.prox=-1;
	  fseek(m,pos*sizeof(r),SEEK_SET);
	  fwrite(&r,sizeof(r),1,m);
	  fseek(m,aux*sizeof(r),SEEK_SET);
	  fread(&r,sizeof(r),1,m);
	  r.prox=aux2;
	  fseek(m,aux*sizeof(r),SEEK_SET);
	  fwrite(&r,sizeof(r),1,m);
	  }
    }
  else {clrscr();ver3(18,10,65,12,1);gotoxy(23,11);cout<<"El apellido ingresado no existe";getch();}
  fclose(m);
  }
}



void calendario (char cnom[8])
{
clrscr();
FILE * m=fopen (cnom,"r+b");
if(m==NULL){clrscr();gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
else
{
calen r;
char w;long pos,pos2;
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
}

void visualcalen (calen r,char &w)
{
int tar,modo;
detectgraph(&tar,&modo);
initgraph(&tar,&modo,"c:\\pgr\\");
//lineas horizontales
line(6,10,550,10);line(6,35,550,35);line(6,74,550,74);line(6,105,550,105);line(6,136,550,136);
line(6,168,550,168);line(6,198,550,198);line(6,230,550,230);line(6,262,550,262);
//lineas verticales
line(6,10,6,262);line(77,10,77,262);line(148,10,148,262);line(225,10,225,262);
line(311,10,311,262);line(386,10,386,262);line(472,10,472,262);line(550,10,550,262);
//dias
gotoxy(21,2);cout<<r.nommes;
gotoxy(42,2);cout<<r.anio;
gotoxy(2,4);cout<<" Domingo";
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
ver3(15,19,60,25,5);
for(int n=1;n<18;n++)
      {gotoxy(n,20); cout<<" <--- (A) Anterior | Siguiente (S) ---> ";
       gotoxy(n,21); cout<<"      (E) Escribir anotacion ";
       gotoxy(n,22); cout<<"      (L) Leer anotacion ";
       gotoxy(n,23); cout<<"      (B) Borrar ";
       gotoxy(n,24); cout<<"      (X) Salir ";delay(20);}
ver3(15,19,60,25,1);
for(n=0;n<3;n++)
{gotoxy(20,18);cout<<"[ E l i j a   u n a   o p c i o n ]";delay(600);
 gotoxy(20,18);cout<<"                                   ";delay(600);}
do
{
w=getche();
w=tolower(w);
}
while(w!='a' && w!='s' && w!='e' &&w!='l' &&w!='x' &&w!='b');
closegraph();
restorecrtmode();
}





int escribir(calen &r)
{
int f;char o;
clrscr();
ver3(1,1,80,5,1);
ver3(20,2,55,4,10);
gotoxy(22,3);cout<<"Ingrese fecha de anotacion :";
gotoxy(50,3);cin>>f;
for (int i=0;i<38 && r.mes[i].date!=f;i++);
if (i==38)
{clrscr();gotoxy(22,3);cout<<" Ingreso   mal   la   fecha";}
else
  {
  for(int n=1;n<11;n++){gotoxy(n,6);cout<<" Agendar:   (C) Cumplea�os    (A) Anotacion    (S)Salir";delay(40);}
  ver3(7,5,9,7,1);
  gotoxy(8,6);
  do
  cin>>o;
  while(o!='c' && o!='a' && o!='s');
  switch (o)
  {
  case 'a'://Anotacion
	   char o=' ';
	   if(r.mes[i].notas[0]!='&')
	   {
	   do
	     {
	     gotoxy(8,8);cout<<"Si realiza una nueva anotacion se perderan las notas anteriores";
	     gotoxy(20,9);cout<<"�Desea continuar? (S) Si  (N) No";
	     ver3(26,10,28,12,1);
	     gotoxy(27,11);cin>>o;o=tolower(o);
	     }while(o!='s'&& o!='n');
	   }
	   if(o=='n')break;
	   gotoxy(8,8);cout<<"                                                               ";
	   gotoxy(20,9);cout<<"                                      ";
	   gotoxy(26,10);cout<<"   ";gotoxy(26,11);cout<<"   ";gotoxy(26,12);cout<<"   ";
	   gotoxy(15,8);cout<<"Puede empezar a escribir...";
	   ver3(1,9,80,24,1);
	   gotoxy(2,12);gets(r.mes[i].notas);
	   break;
  case 'c'://cumple a�os
	   o=' ';
	   if(r.mes[i].ca.marc==1)
	   {
	   do
	     {
	     gotoxy(8,8);cout<<"Si realiza una nueva anotacion se perderan las notas anteriores";
	     gotoxy(20,9);cout<<"�Desea continuar? (S) Si  (N) No";
	     ver3(26,10,28,12,1);
	     gotoxy(27,11);cin>>o;o=tolower(o);
	     }while(o!='s'&& o!='n');
	   }
	   if(o=='n')break;
	   clrscr();
	   for(n=0;n<5;n++){ver3(26-n,9-n,50+n,17+n,3);}
	   gotoxy(28,11);cout<<"Nombre de Cumplea�ero";
	   for(n=27;n<50;n++){gotoxy(n,13);cout<<"�";}
	   gotoxy(28,15);gets(r.mes[i].ca.nom);
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
ver3(1,1,80,5,1);
ver3(20,2,55,4,10);
gotoxy(22,3);cout<<"Ingrese fecha de consulta  :";
gotoxy(50,3);cin>>d;
for (int i=0;i<38 && r.mes[i].date!=d;i++);
if (i==38)
{clrscr();gotoxy(22,3);cout<<" Ingreso   mal   la   fecha ";getch();}
else
{
if(r.mes[i].ca.marc==1)
  {
  clrscr();band=1;
  for(int n=0;n<5;n++){ver3(15-n,9-n,65+n,17+n,4);}
  gotoxy(25,11);cout<<"No olvides saludar a  ";
  gotoxy(25,13);cout<<r.mes[i].ca.nom;
  gotoxy(23,15);cout<<"  por que hoy Cumplea�os...";
  sound (400);delay (300);nosound();delay (50);
  sound (400);delay (300);nosound();delay (20);
  sound (450);delay (400);
  sound (400);delay (400);
  sound (530);delay (400);
  sound (500);delay (400);

  sound (400);delay (300);nosound();delay (50);
  sound (400);delay (300);nosound();delay (20);
  sound (450);delay (400);
  sound (400);delay (400);
  sound (600);delay (400);
  sound (530);delay (400);

  sound (400);delay (300);nosound();delay (20);
  sound (400);delay (300);nosound();delay (20);
  sound (670);delay (550);
  sound (530);delay (400);nosound();

  sound (500);delay (400);nosound();delay (50);
  sound (500);delay (500);nosound();delay (20);
  sound (500);delay (400);nosound();delay (20);
  sound (450);delay (800);nosound();delay (20);

  sound (700);delay (400);nosound();delay (50);
  sound (700);delay (500);nosound();delay (20);
  sound (670);delay (400);nosound();delay (20);
  sound (530);delay (700);nosound();delay (20);

  sound (600);delay (700);nosound();delay (50);
  sound (530);delay (1100);nosound();
  for(n=0;n<3;n++)
    {gotoxy(20,25);cout<<"                                       ";delay(600);
    gotoxy(20,25);cout<<"[ P r e s i o n e   u n a   t e c l a ]";delay(600);}
 getch();


  }
if(r.mes[i].notas[0]!='&')
  {
  clrscr();band=1;
  ver3(30,3,53,5,1);
  gotoxy(31,4);cout<<" A n o t a c i o n e s";
  ver3(1,6,80,24,1);
  gotoxy(2,9);cout<<r.mes[i].notas;getch();
  }
  if(band==0){gotoxy(15,7);cout<<"Este dia no tiene anotaciones...";
              for(int n=0;n<3;n++)
              {gotoxy(15,9);cout<<"                                       ";delay(600);
               gotoxy(15,9);cout<<"[ P r e s i o n e   u n a   t e c l a ]";delay(600);}
               getch();}
}


}

int borrar(calen &r)
{
int d;
clrscr();
char o;
ver3(1,1,80,5,1);
gotoxy(15,3);cout<<"(A) Borrar Anotaciones   (C)Borrar Cumplea�os  (S) Salir";
do
  {
  gotoxy(73,3);o=getche();
  o=tolower(o);
  }
while(o!='a' && o!='c' && o!='s');
ver3(17,6,62,9,10);
gotoxy(19,7);cout<<"Ingrese Fecha de la Anotacion/Cumplea�os:";
gotoxy(60,7);cin>>d;
for (int i=0;i<38 && r.mes[i].date!=d;i++);
if (i==38)
{  clrscr();gotoxy(16,8);cout<<"ingreso mal la fecha";
    for(int n=0;n<3;n++)
    {gotoxy(16,9);cout<<"                                       ";delay(600);
     gotoxy(16,9);cout<<"[ P r e s i o n e   u n a   t e c l a ]";delay(600);};getch();}
else
{
switch(o)
{
case 'a'://borrar anotacion
         r.mes[i].notas[0]='&';
         return 1;

case 'c': //borrar cumple�os
         r.mes[i].ca.marc=0;
         return 1;

case 's'://salir
         return 0;

}

}
return 0;
}


void alfabeta (char us[20])
{
FILE *m=fopen(us,"rb");
if (m==NULL) {clrscr();gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
else
  {
  clrscr();
  agenda r;char c;int i=0,j=8,flag=0;
  ver3(10,2,70,25,1);
  gotoxy(18,3);cout<<"Ingrese la letra en la que desea buscar : ";
  for(int p=11;p<70;p++){gotoxy(p,5);cout<<"�";}
  gotoxy(62,3);cin>>c;
  gotoxy(11,6);cout<<"     Apellido            Nombre              Telefono";
  for(p=11;p<70;p++){gotoxy(p,7);cout<<"�";}
  fread (&r,sizeof(r),1,m);
  while (i<540)
    {
    i++;
    if (r.ape[0]==c&& strcmp(r.ape,"vacio")!=0)
      {
      flag=1;
      if(j>23){j=8;for(int n=0;n<3;n++)
                   {gotoxy(12,24);cout<<"                                          ";delay(600);
                    gotoxy(12,24);cout<<"[Presione una tecla para limpiar pantalla ";delay(600);} getch();}
      gotoxy(12,j);cout<<r.ape;
      gotoxy(31,j);cout<<r.nom;
      gotoxy(51,j);cout<<r.tel;
      j++;
      }
    fread (&r,sizeof(r),1,m);
    }
    if(flag==0){gotoxy(25,10);cout<<"No se encontraron registros";
                for(int n=0;n<3;n++)
                {gotoxy(22,11);cout<<"                                       ";delay(600);
                 gotoxy(22,11);cout<<"[ P r e s i o n e   u n a   t e c l a ]";delay(600);};getch();
               }
    else{gotoxy(11,24);cout<<" Busqueda Finalizada  [presione una tecla para continuar]";}
  getch();
  fclose (m);
  }
}


void renom (char cnom[8])
{
FILE *m=fopen ("c:\\pgr\\calendar","rb");
if(m==NULL){clrscr();gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
FILE *f=fopen (cnom,"wb");
if(f==NULL){clrscr();gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
calen r;
for (int i=0;i<24;i++)
  {
  fread (&r,sizeof(r),1,m);
  fwrite (&r,sizeof(r),1,f);
  }
  fclose(m);
  fclose(f);
}


void menus(int men,int anim)
{
clrscr();
int i=1,j=1,l=1,m=25,l2=0;
if (anim==1) {j=5;i=20;l=13;m=25;l2=5;}
switch (men)
  {
  case 0://Menu Principal
	 for (i;i<21;i++)
	   {
	   clrscr();
	   if (i>14&&j<5) j++;
	   gotoxy(20,j);cout<<"�������������������������������������ͻ�";
	   gotoxy(20,j+1);cout<<"��          Men� Principal            ��";
	   gotoxy(20,j+2);cout<<"�������������������������������������͹�";
	   gotoxy(i,8);cout<<"��   [1]. Crear Nuev";
	   gotoxy(i,9);cout<<"��������������������";
	   gotoxy(i,10);cout<<"��   [2]. Usuario Ex";
	   gotoxy(20,16-j);cout<<"�������������������������������������͹�";
	   gotoxy(20,17-j);cout<<"��   [3]. Salir de la Agenda          ��";
	   gotoxy(20,18-j);cout<<"�������������������������������������ͼ�";
	   gotoxy(60-i,8);cout<<"o usuario         ��";
	   gotoxy(60-i,9);cout<<"�����������������͹�";
	   gotoxy(60-i,10);cout<<"istente           ��";
	   delay (23);
	   }
       for(int n=0;n<3;n++)
{gotoxy(23,18);cout<<"[ E l i j a   u n a   o p c i o n ]";delay(600);
 gotoxy(23,18);cout<<"                                   ";delay(600);}
	   break;

  case 1://Menu Secundario
	 for (l;l<14;l++)
	   {
	   clrscr();
	   gotoxy(14,m-l-7);cout<<"�������������������������������������������������ͻ���";
	   gotoxy(14,m-l-6);cout<<"����                                              ����";
	   gotoxy(14,m-l-5);cout<<"����                Men� Personal                 ����";
	   gotoxy(14,m-l-4);cout<<"����                                              ����";
	   gotoxy(14,m-l-3);cout<<"�������������������������������������������������͹���";
	   gotoxy(14,m-l-2);cout<<"����    [1]. Ingresar Nuevo Registro              ����";
	   gotoxy(14,m-l-1);cout<<"�������������������������������������������������͹���";
	   gotoxy(14,m-l);cout<<"����    [2]. Buscar un Registro                   ����";
	   gotoxy(14,l);cout<<"�������������������������������������������������͹���";
	   gotoxy(14,l+1);cout<<"����    [3]. Buscar un Registro Alfabeticamente   ����";
	   gotoxy(14,l+2);cout<<"�������������������������������������������������͹���";
	   gotoxy(14,l+3);cout<<"����    [4]. Eliminar un Registro                 ����";
	   gotoxy(14,l+4);cout<<"�������������������������������������������������͹���";
	   gotoxy(14,l+5);cout<<"����    [5]. Entrar al Calendario                 ����";
	   gotoxy(14,l+6);cout<<"�������������������������������������������������͹���";
	   gotoxy(14,l+7);cout<<"����    [6]. Desactivar/Activar Animaciones       ����";
	   gotoxy(14,l+8);cout<<"�������������������������������������������������ͼ���";
	   gotoxy(50,24);cout<<" �-> Sale con (x)";
	   delay (35);
	   }
	   for (l2;l2<5;l2++)
	     {
	     for (int r=0;r<3;r++)
	       {
	       switch(r)
		 {
		 case 0:
			gotoxy(14,5);cout<<"�������������������������������������������������ͻ���";
			gotoxy(14,6);cout<<"����                                              ����";
			gotoxy(14,7);cout<<"����                Men� Personal                 ����";
			gotoxy(14,8);cout<<"����                                              ����";
			gotoxy(14,9);cout<<"�������������������������������������������������͹���";
			gotoxy(14,10);cout<<"����    [1]. Ingresar Nuevo Registro              ����";
			gotoxy(14,11);cout<<"�������������������������������������������������͹���";
			gotoxy(14,12);cout<<"����    [2]. Buscar un Registro                   ����";
			gotoxy(14,13);cout<<"�������������������������������������������������͹���";
			gotoxy(14,14);cout<<"����    [3]. Buscar un Registro Alfabeticamente   ����";
			gotoxy(14,15);cout<<"�������������������������������������������������͹���";
			gotoxy(14,16);cout<<"����    [4]. Eliminar un Registro                 ����";
			gotoxy(14,17);cout<<"�������������������������������������������������͹���";
			gotoxy(14,18);cout<<"����    [5]. Entrar al Calendario                 ����";
			gotoxy(14,19);cout<<"�������������������������������������������������͹���";
			gotoxy(14,20);cout<<"����    [6]. Desactivar/Activar Animaciones       ����";
			gotoxy(14,21);cout<<"�������������������������������������������������ͼ���";
			gotoxy(50,24);cout<<" �-> Sale con (x)";


			break;
		 case 1:
			gotoxy(14,5);cout<<"�������������������������������������������������ͻ���";
			gotoxy(14,6);cout<<"����                                              ����";
			gotoxy(14,7);cout<<"����                Men� Personal                 ����";
			gotoxy(14,8);cout<<"����                                              ����";
			gotoxy(14,9);cout<<"�������������������������������������������������͹���";
			gotoxy(14,10);cout<<"����    [1]. Ingresar Nuevo Registro              ����";
			gotoxy(14,11);cout<<"�������������������������������������������������͹���";
			gotoxy(14,12);cout<<"����    [2]. Buscar un Registro                   ����";
			gotoxy(14,13);cout<<"�������������������������������������������������͹���";
			gotoxy(14,14);cout<<"����    [3]. Buscar un Registro Alfabeticamente   ����";
			gotoxy(14,15);cout<<"�������������������������������������������������͹���";
			gotoxy(14,16);cout<<"����    [4]. Eliminar un Registro                 ����";
			gotoxy(14,17);cout<<"�������������������������������������������������͹���";
			gotoxy(14,18);cout<<"����    [5]. Entrar al Calendario                 ����";
			gotoxy(14,19);cout<<"�������������������������������������������������͹���";
			gotoxy(14,20);cout<<"����    [6]. Desactivar/Activar Animaciones       ����";
			gotoxy(14,21);cout<<"�������������������������������������������������ͼ���";
			gotoxy(50,24);cout<<" �-> Sale con (x)";

			break;
		 case 2:
			gotoxy(14,5);cout<<"�������������������������������������������������ͻ���";
			gotoxy(14,6);cout<<"����                                              ����";
			gotoxy(14,7);cout<<"����                Men� Personal                 ����";
			gotoxy(14,8);cout<<"����                                              ����";
			gotoxy(14,9);cout<<"�������������������������������������������������͹���";
			gotoxy(14,10);cout<<"����    [1]. Ingresar Nuevo Registro              ����";
			gotoxy(14,11);cout<<"�������������������������������������������������͹���";
			gotoxy(14,12);cout<<"����    [2]. Buscar un Registro                   ����";
			gotoxy(14,13);cout<<"�������������������������������������������������͹���";
			gotoxy(14,14);cout<<"����    [3]. Buscar un Registro Alfabeticamente   ����";
			gotoxy(14,15);cout<<"�������������������������������������������������͹���";
			gotoxy(14,16);cout<<"����    [4]. Eliminar un Registro                 ����";
			gotoxy(14,17);cout<<"�������������������������������������������������͹���";
			gotoxy(14,18);cout<<"����    [5]. Entrar al Calendario                 ����";
			gotoxy(14,19);cout<<"�������������������������������������������������͹���";
			gotoxy(14,20);cout<<"����    [6]. Desactivar/Activar Animaciones       ����";
			gotoxy(14,21);cout<<"�������������������������������������������������ͼ���";
			gotoxy(50,24);cout<<" �-> Sale con (x)";
			break;
		 }
		 delay(60);
	       }
	     }
       for(n=0;n<3;n++)
       {gotoxy(23,25);cout<<"[ E l i j a   u n a   o p c i o n ]";delay(600);
       gotoxy(23,25);cout<<"                                   ";delay(600);}
	   break;

  }

}

void ver()
{
for(int q=20;q<60;q++){gotoxy(q,15);cout<<"�";delay(10);}gotoxy(60,15);cout<<"�";
for(q=16;q<21;q++)    {gotoxy(60,q);cout<<"�";delay(10);}gotoxy(60,21);cout<<"�";
for(q=59;q>20;q--)    {gotoxy(q,21);cout<<"�";delay(10);}gotoxy(20,21);cout<<"�";
for(q=20;q>15;q--)    {gotoxy(20,q);cout<<"�";delay(10);}gotoxy(20,15);cout<<"�";
for(q=21;q<60;q++){gotoxy(q,18);cout<<"�";delay(10);}gotoxy(20,18);cout<<"�";gotoxy(60,18);cout<<"�";
}

void ver2()
{
for(int q=10;q<70;q++){gotoxy(q,8);cout<<"�";delay(2);}gotoxy(70,8);cout<<"�";
for(q=9;q<20;q++)    {gotoxy(70,q);cout<<"�";delay(2);}gotoxy(70,20);cout<<"�";
for(q=69;q>10;q--)    {gotoxy(q,20);cout<<"�";delay(2);}gotoxy(10,20);cout<<"�";
for(q=19;q>8;q--)    {gotoxy(10,q);cout<<"�";delay(2);}gotoxy(10,8);cout<<"�";

}

void ver3(int x1,int y1,int x2,int y2,int d)
{
for(int q=x1;q<x2;q++){gotoxy(q,y1);cout<<"�";delay(d);}gotoxy(x2,y1);cout<<"�";
for(q=y1+1;q<y2;q++)    {gotoxy(x2,q);cout<<"�";delay(d);}gotoxy(x2,y2);cout<<"�";
for(q=x2-1;q>x1;q--)    {gotoxy(q,y2);cout<<"�";delay(d);}gotoxy(x1,y2);cout<<"�";
for(q=y2-1;q>y1;q--)    {gotoxy(x1,q);cout<<"�";delay(d);}gotoxy(x1,y1);cout<<"�";
}

void presentacion()
{
    int i=0;int m1=25,m2=15,n1=600,n2=400;
    int gdriver=DETECT, gmode;
    initgraph(&gdriver, &gmode,"c:\\pgr\\");
    int j=630;
    for(i=630;i>0;i=i-2){ settextstyle(0,0,7);
                        setcolor(2);
                        outtextxy(i,100,"A G N �");
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

