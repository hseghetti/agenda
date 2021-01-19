#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>

struct agenda
{
char ape[20],nom[20];
char dir[30],tel[11];
char mail[20];int flag;
int prox;
};
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
void ver3(int x1,int y1,int x2,int y2);


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
if (m==NULL){cout<<"error";exit(1);}
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
  ver3(20,2,60,8);
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
   else {ver3(20,2,60,8);
         gotoxy(25,3);cout<<"No se encontro registro con ese apellido";
         gotoxy(25,4);cout<<"                                    ";
         gotoxy(25,6);cout<<"                                    ";
         gotoxy(25,7);cout<<" Presione una tecla para continuar  ";
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
  ver3(20,22,57,24);
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
if (m==NULL) {gotoxy(1,1);cout<<"error al abrir el archivo";getch();}
else
  {
  char ape[20];
  agenda r,a;int pos,aux;
  clrscr();
  ver3(20,2,60,8);
  gotoxy(25,3);cout<<"Ingrese Apellido a Buscar";
  gotoxy(25,4);gets(ape);
  gotoxy(25,6);cout<<"Ingrese Nombre a Buscar";
  gotoxy(25,7);gets(nom);
  pos=dispersion(ape);
  fseek(m,pos*sizeof(r),SEEK_SET);
  fread(&r,sizeof(r),1,m);
  while(strcmp(ape,r.ape)!=0 && r.prox!=-1)
    {
    aux=pos;
    pos=r.prox;
    fseek(m,pos*sizeof(r),SEEK_SET);
    fread(&r,sizeof(r),1,m);
    }
  if(strcmp(ape,r.ape)==0)
    {
      char c;
      cout<<"จConfirma la eliminacion del registro s/n?";
      c=getche();
      c=tolower(c);
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
	    fseek(m,r.prox*sizeof(r),SEEK_SET);
	    fread(&a,sizeof(a),1,m);
	    r=a;
	    a.flag=1;strcpy(a.ape,"vacio");a.prox=-1;
	    fseek(m,a.prox*sizeof(r),SEEK_SET);
	    fwrite(&a,sizeof(a),1,m);
	    fseek(m,pos*sizeof(r),SEEK_SET);
	    fwrite(&r,sizeof(r),1,m);
	    fseek(m,pos*sizeof(r),SEEK_SET);
	    fread(&r,sizeof(r),1,m);
	    }
	else
	  {
	  fseek(m,pos*sizeof(r),SEEK_SET);
	  fread(&r,sizeof(r),1,m);
	  r.flag=1;
	  pos=r.prox;
	  fwrite(&r,sizeof(r),1,m);
	  fseek(m,aux*sizeof(r),SEEK_SET);
	  fread(&r,sizeof(r),1,m);
	  r.prox=pos;
	  fseek(m,aux*sizeof(r),SEEK_SET);
	  fwrite(&r,sizeof(r),1,m);
	  }
    }
  else cout<<"El apellido ingresado no existe";getch();
  fclose(m);
  }
}



void calendario (char cnom[8])
{
clrscr();
cout<<"2 "<<cnom;getch();
FILE * m=fopen (cnom,"r+b");
if(m==NULL){gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
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
          gotoxy(h-1,t);cout<<"บ";
          gotoxy(h-1,t-1);cout<<"ษ";
          gotoxy(h-1,t+1);cout<<"ศ";
          gotoxy(h,t-1);cout<<"ออ";
          gotoxy(h,t+1);cout<<"ออ";
          gotoxy(h+2,t);cout<<"บ";
          gotoxy(h+2,t-1);cout<<"ป";
          gotoxy(h+2,t+1);cout<<"ผ";
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
w=tolower(w);
}
while(w!='a' && w!='s' && w!='e' &&w!='l' &&w!='x' &&w!='b');
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
  cout<<"\nAgendar:   (C) Cumple Aคos    (A) Anotacion    (S)Salir";
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
             cout<<"\nจDesea continuar? (S) Si  (N) No";
             cin>>o;o=tolower(o);
             }while(o!='s'&&o!='n');
           }
           if(o=='n')break;
           cout<<"\nEmpeza a escribir\n";
           gets(r.mes[i].notas);
           break;
  case 'c'://cumple aคos
           o=' ';
           if(r.mes[i].ca.marc==1)
           {
           do
             {
             cout<<"\nSi realiza una nueva anotacion se perderan las notas anteriores";
             cout<<"\nจDesea continuar? (S) Si  (N) No";
             cin>>o;o=toupper(o);
             }while(o!='s'&& o!='n');
           }
           if(o=='n')break;
           cout<<"\nNombre de Cumplaคero\n";
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
  cout<<"\nNo Olvides Saludar a  "<<r.mes[i].ca.nom<<" \n por que hoy Cumple Aคos...\n";getch();
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
cout<<"(A) Borrar Anotaciones   (C)Borrar Cumpleaคos  (S) Salir";
do
  {
  o=getche();
  o=tolower(o);
  }
while(o!='a' && o!='c' && o!='s');
cout<<"\nIngrese Fecha de la Anotacion/Cumpleaคos\n";
cin>>d;
for (int i=0;i<38 && r.mes[i].date!=d;i++);
if (i==38)
{clrscr();gotoxy(1,1);cout<<"ingreso mal la fecha";getch();}
else
{
switch(o)
{
case 'a'://borrar anotacion
         r.mes[i].notas[0]='&';
         return 1;

case 'c': //borrar cumpleคos
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
if (m==NULL) {gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
else
  {
  clrscr();
  agenda r;char c;int i=0,j=3;
  cout<<"Ingrese la letra en la que desea buscar";
  c=getche();
  fread (&r,sizeof(r),1,m);
  while (i<540)
    {
    i++;
    if (r.ape[0]==c)
      {
      gotoxy(3,2);cout<<"Apellido";
      gotoxy(15,2);cout<<"Nombre";
      gotoxy(3,j);cout<<r.ape;
      gotoxy(15,j);cout<<r.nom;
      j++;
      }
    fread (&r,sizeof(r),1,m);
    }
  getch();
  fclose (m);
  }
}


void renom (char cnom[8])
{
FILE *m=fopen ("calendar","rb");
FILE *f=fopen (cnom,"wb");
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
	   gotoxy(20,j);cout<<"ฒษออออออออออออออออออออออออออออออออออออปฒ";
	   gotoxy(20,j+1);cout<<"ฒบ          Menฃ Principal            บฒ";
	   gotoxy(20,j+2);cout<<"ฒฬออออออออออออออออออออออออออออออออออออนฒ";
	   gotoxy(i,8);cout<<"ฒบ     1. Crear Nuev";
	   gotoxy(i,9);cout<<"ฒฬออออออออออออออออออ";
	   gotoxy(i,10);cout<<"ฒบ     2. Usuario Ex";
	   gotoxy(20,16-j);cout<<"ฒฬออออออออออออออออออออออออออออออออออออนฒ";
	   gotoxy(20,17-j);cout<<"ฒบ     3. Salir de la Agenda          บฒ";
	   gotoxy(20,18-j);cout<<"ฒศออออออออออออออออออออออออออออออออออออผฒ";
	   gotoxy(60-i,8);cout<<"o usuario         บฒ";
	   gotoxy(60-i,9);cout<<"ออออออออออออออออออนฒ";
	   gotoxy(60-i,10);cout<<"istente           บฒ";
	   delay (23);
	   }
	   break;

  case 1://Menu Secundario
	 for (l;l<14;l++)
	   {
	   clrscr();
	   gotoxy(14,m-l-7);cout<<"ฐฑฒษออออออออออออออออออออออออออออออออออออออออออออออปฒฑฐ";
	   gotoxy(14,m-l-6);cout<<"ฐฑฒบ                                              บฒฑฐ";
	   gotoxy(14,m-l-5);cout<<"ฐฑฒบ                Menฃ Personal                 บฒฑฐ";
	   gotoxy(14,m-l-4);cout<<"ฐฑฒบ                                              บฒฑฐ";
	   gotoxy(14,m-l-3);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
	   gotoxy(14,m-l-2);cout<<"ฐฑฒบ     1. Ingresar Nuevo Registro               บฒฑฐ";
	   gotoxy(14,m-l-1);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
	   gotoxy(14,m-l);cout<<"ฐฑฒบ     2. Buscar un Registro                    บฒฑฐ";
	   gotoxy(14,l);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
	   gotoxy(14,l+1);cout<<"ฐฑฒบ     3. Buscar un Registro Alfabeticamente    บฒฑฐ";
	   gotoxy(14,l+2);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
	   gotoxy(14,l+3);cout<<"ฐฑฒบ     4. Eliminar un Registro                  บฒฑฐ";
	   gotoxy(14,l+4);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
	   gotoxy(14,l+5);cout<<"ฐฑฒบ     5. Entrar al Calendario                  บฒฑฐ";
	   gotoxy(14,l+6);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
	   gotoxy(14,l+7);cout<<"ฐฑฒบ     6. Desactivar/Activar Animaciones        บฒฑฐ";
	   gotoxy(14,l+8);cout<<"ฐฑฒศออออออออออออออออออออออออออออออออออออออออออออออผฒฑฐ";
	   gotoxy(50,24);cout<<" ภ-> Sale con (x)";
	   delay (35);
	   }
	   for (l2;l2<5;l2++)
	     {
	     for (int r=0;r<3;r++)
	       {
	       switch(r)
		 {
		 case 0:
			gotoxy(14,5);cout<<"ฐฑฒษออออออออออออออออออออออออออออออออออออออออออออออปฒฑฐ";
			gotoxy(14,6);cout<<"ฐฑฒบ                                              บฒฑฐ";
			gotoxy(14,7);cout<<"ฐฑฒบ                Menฃ Personal                 บฒฑฐ";
			gotoxy(14,8);cout<<"ฐฑฒบ                                              บฒฑฐ";
			gotoxy(14,9);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
			gotoxy(14,10);cout<<"ฐฑฒบ     1. Ingresar Nuevo Registro               บฒฑฐ";
			gotoxy(14,11);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
			gotoxy(14,12);cout<<"ฐฑฒบ     2. Buscar un Registro                    บฒฑฐ";
			gotoxy(14,13);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
			gotoxy(14,14);cout<<"ฐฑฒบ     3. Buscar un Registro Alfabeticamente    บฒฑฐ";
			gotoxy(14,15);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
			gotoxy(14,16);cout<<"ฐฑฒบ     4. Eliminar un Registro                  บฒฑฐ";
			gotoxy(14,17);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
			gotoxy(14,18);cout<<"ฐฑฒบ     5. Entrar al Calendario                  บฒฑฐ";
			gotoxy(14,19);cout<<"ฐฑฒฬออออออออออออออออออออออออออออออออออออออออออออออนฒฑฐ";
			gotoxy(14,20);cout<<"ฐฑฒบ     6. Desactivar/Activar Animaciones        บฒฑฐ";
			gotoxy(14,21);cout<<"ฐฑฒศออออออออออออออออออออออออออออออออออออออออออออออผฒฑฐ";
			gotoxy(50,24);cout<<" ภ-> Sale con (x)";


			break;
		 case 1:
			gotoxy(14,5);cout<<"ฑฒฐษออออออออออออออออออออออออออออออออออออออออออออออปฐฒฑ";
			gotoxy(14,6);cout<<"ฑฒฐบ                                              บฐฒฑ";
			gotoxy(14,7);cout<<"ฑฒฐบ                Menฃ Personal                 บฐฒฑ";
			gotoxy(14,8);cout<<"ฑฒฐบ                                              บฐฒฑ";
			gotoxy(14,9);cout<<"ฑฒฐฬออออออออออออออออออออออออออออออออออออออออออออออนฐฒฑ";
			gotoxy(14,10);cout<<"ฑฒฐบ     1. Ingresar Nuevo Registro               บฐฒฑ";
			gotoxy(14,11);cout<<"ฑฒฐฬออออออออออออออออออออออออออออออออออออออออออออออนฐฒฑ";
			gotoxy(14,12);cout<<"ฑฒฐบ     2. Buscar un Registro                    บฐฒฑ";
			gotoxy(14,13);cout<<"ฑฒฐฬออออออออออออออออออออออออออออออออออออออออออออออนฐฒฑ";
			gotoxy(14,14);cout<<"ฑฒฐบ     3. Buscar un Registro Alfabeticamente    บฐฒฑ";
			gotoxy(14,15);cout<<"ฑฒฐฬออออออออออออออออออออออออออออออออออออออออออออออนฐฒฑ";
			gotoxy(14,16);cout<<"ฑฒฐบ     4. Eliminar un Registro                  บฐฒฑ";
			gotoxy(14,17);cout<<"ฑฒฐฬออออออออออออออออออออออออออออออออออออออออออออออนฐฒฑ";
			gotoxy(14,18);cout<<"ฑฒฐบ     5. Entrar al Calendario                  บฐฒฑ";
			gotoxy(14,19);cout<<"ฑฒฐฬออออออออออออออออออออออออออออออออออออออออออออออนฐฒฑ";
			gotoxy(14,20);cout<<"ฑฒฐบ     6. Desactivar/Activar Animaciones        บฐฒฑ";
			gotoxy(14,21);cout<<"ฑฒฐศออออออออออออออออออออออออออออออออออออออออออออออผฐฒฑ";
			gotoxy(50,24);cout<<" ภ-> Sale con (x)";

			break;
		 case 2:
			gotoxy(14,5);cout<<"ฒฐฑษออออออออออออออออออออออออออออออออออออออออออออออปฑฐฒ";
			gotoxy(14,6);cout<<"ฒฐฑบ                                              บฑฐฒ";
			gotoxy(14,7);cout<<"ฒฐฑบ                Menฃ Personal                 บฑฐฒ";
			gotoxy(14,8);cout<<"ฒฐฑบ                                              บฑฐฒ";
			gotoxy(14,9);cout<<"ฒฐฑฬออออออออออออออออออออออออออออออออออออออออออออออนฑฐฒ";
			gotoxy(14,10);cout<<"ฒฐฑบ     1. Ingresar Nuevo Registro               บฑฐฒ";
			gotoxy(14,11);cout<<"ฒฐฑฬออออออออออออออออออออออออออออออออออออออออออออออนฑฐฒ";
			gotoxy(14,12);cout<<"ฒฐฑบ     2. Buscar un Registro                    บฑฐฒ";
			gotoxy(14,13);cout<<"ฒฐฑฬออออออออออออออออออออออออออออออออออออออออออออออนฑฐฒ";
			gotoxy(14,14);cout<<"ฒฐฑบ     3. Buscar un Registro Alfabeticamente    บฑฐฒ";
			gotoxy(14,15);cout<<"ฒฐฑฬออออออออออออออออออออออออออออออออออออออออออออออนฑฐฒ";
			gotoxy(14,16);cout<<"ฒฐฑบ     4. Eliminar un Registro                  บฑฐฒ";
			gotoxy(14,17);cout<<"ฒฐฑฬออออออออออออออออออออออออออออออออออออออออออออออนฑฐฒ";
			gotoxy(14,18);cout<<"ฒฐฑบ     5. Entrar al Calendario                  บฑฐฒ";
			gotoxy(14,19);cout<<"ฒฐฑฬออออออออออออออออออออออออออออออออออออออออออออออนฑฐฒ";
			gotoxy(14,20);cout<<"ฒฐฑบ     6. Desactivar/Activar Animaciones        บฑฐฒ";
			gotoxy(14,21);cout<<"ฒฐฑศออออออออออออออออออออออออออออออออออออออออออออออผฑฐฒ";
			gotoxy(50,24);cout<<" ภ-> Sale con (x)";
			break;
		 }
		 delay(60);
	       }
	     }
	   break;

  }
}

void ver()
{
for(int q=20;q<60;q++){gotoxy(q,15);cout<<"อ";delay(10);}gotoxy(60,15);cout<<"ป";
for(q=16;q<21;q++)    {gotoxy(60,q);cout<<"บ";delay(10);}gotoxy(60,21);cout<<"ผ";
for(q=59;q>20;q--)    {gotoxy(q,21);cout<<"อ";delay(10);}gotoxy(20,21);cout<<"ศ";
for(q=20;q>15;q--)    {gotoxy(20,q);cout<<"บ";delay(10);}gotoxy(20,15);cout<<"ษ";
for(q=21;q<59;q++){gotoxy(q,18);cout<<"อ";delay(10);}
}

void ver2()
{
for(int q=10;q<70;q++){gotoxy(q,8);cout<<"อ";delay(2);}gotoxy(70,8);cout<<"ป";
for(q=9;q<20;q++)    {gotoxy(70,q);cout<<"บ";delay(2);}gotoxy(70,20);cout<<"ผ";
for(q=69;q>10;q--)    {gotoxy(q,20);cout<<"อ";delay(2);}gotoxy(10,20);cout<<"ศ";
for(q=19;q>8;q--)    {gotoxy(10,q);cout<<"บ";delay(2);}gotoxy(10,8);cout<<"ษ";

}

void ver3(int x1,int y1,int x2,int y2)   //x1 20 / y1 15 / x2 60 / y2 21
{
for(int q=x1;q<x2;q++){gotoxy(q,y1);cout<<"อ";delay(10);}gotoxy(x2,y1);cout<<"ป";
for(q=y1+1;q<y2;q++)    {gotoxy(x2,q);cout<<"บ";delay(10);}gotoxy(x2,y2);cout<<"ผ";
for(q=x2-1;q>x1;q--)    {gotoxy(q,y2);cout<<"อ";delay(10);}gotoxy(x1,y2);cout<<"ศ";
for(q=y2-1;q>y1;q--)    {gotoxy(x1,q);cout<<"บ";delay(10);}gotoxy(x1,y1);cout<<"ษ";
}
