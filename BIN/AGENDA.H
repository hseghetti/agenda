#include <iostream.h>
#include <conio.h>
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

void cerear (char us[20]);
char *newus ();
void newreg (char us[20]);
int dispersion (char ape[20]);
int dispersionII ();
void buscar (char us[20]);
void modificar (char us[20],int pos,agenda r);
void eliminar (char us[20]);
void eliminartotales(char us[20]);

char *newus ()
{
char f[20],pas[20],pas2[20];
gotoxy(1,1);cout<<"Ingrese el nombre de nuevo Usuario ";
gets(f);
FILE *m=fopen(f,"wb");
if (m==NULL) {gotoxy(15,7);cout<<"error al abrir el archivo";exit (1);}
else
{
fseek(m,540*sizeof(agenda),SEEK_SET);
do
{
cout<<"ingrese pasword ";
gets(pas);
cout<<"Confirme pasword ";
gets(pas2);
if(strcmp(pas,pas2)!=0)cout<<"No coinciden los pasword";
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
  cout<<"Ingrese Apellido";
  gets(t.ape);
  cout<<"Ingrese Nombre";
  gets(t.nom);
  cout<<"Ingrese Direccion";
  gets(t.dir);
  cout<<"Ingrese Telefono";
  gets(t.tel);
  cout<<"Ingrese e-mail";
  gets(t.mail);
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
    cout<<pos;getch();
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
  gotoxy(15,15);cout<<"Ingrese Apellido a Buscar";
  gotoxy(18,16);gets(ape);
  gotoxy(15,17);cout<<"Ingrese Nombre a Buscar";
  gotoxy(18,18);gets(nom);
  pos=dispersion(ape);
  fseek(f,pos*sizeof(r),SEEK_SET);
  fread(&r,sizeof(r),1,f);
  posII=pos;
  cout<<r.ape<<" "<<r.prox;getch();
  while((strcmp(ape,r.ape)!=0 || strcmp(nom,r.nom)!=0) && r.prox!=-1)
    {
    posII=r.prox;
    fseek(f,r.prox*sizeof(r),SEEK_SET);
    fread(&r,sizeof(r),1,f);
    }
   if(strcmp(ape,r.ape)==0 && strcmp(nom,r.nom)==0)
   {
     clrscr();
     gotoxy(5,5);cout<<r.ape;
     gotoxy(5,6);cout<<r.nom;
     gotoxy(5,7);cout<<r.dir;
     gotoxy(5,8);cout<<r.tel;
     gotoxy(5,9);cout<<r.mail;
     gotoxy(5,10);cout<<r.prox;
     fclose(f);
     modificar (us,posII,r);
    }
   else cout<<"No se encontro registro con ese apellido";
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
  cout<<"para Modificar Datos presionar M ";
  x=getche();
  x=tolower(x);
  if(x=='m')
   {
   cout<<"Ingrese Nombre";
   gets(r.nom);
   cout<<"Ingrese Direccion";
   gets(r.dir);
   cout<<"Ingrese Telefono";
   gets(r.tel);
   cout<<"Ingrese e-mail";
   gets(r.mail);
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
  cout<<"ingrear el apellido a borrar";
  gets(ape);
  pos=dispersion(ape);
  //
  cout<<" "<<pos;
  //
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
      cout<<"¨Confirma la eliminacion del registro s/n?";
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
	   gotoxy(20,j);cout<<"²ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»²";
	   gotoxy(20,j+1);cout<<"²Ί          Men£ Principal            Ί²";
	   gotoxy(20,j+2);cout<<"²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²";
	   gotoxy(i,8);cout<<"²Ί     1. Crear Nuev";
	   gotoxy(i,9);cout<<"²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ";
	   gotoxy(i,10);cout<<"²Ί     2. Usuario Ex";
	   gotoxy(20,16-j);cout<<"²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²";
	   gotoxy(20,17-j);cout<<"²Ί     3. Salir de la Agenda          Ί²";
	   gotoxy(20,18-j);cout<<"²ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ²";
	   gotoxy(60-i,8);cout<<"o usuario         Ί²";
	   gotoxy(60-i,9);cout<<"ΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²";
	   gotoxy(60-i,10);cout<<"istente           Ί²";
	   delay (23);
	   }
	   break;

  case 1://Menu Secundario
	 for (l;l<14;l++)
	   {
	   clrscr();
	   gotoxy(14,m-l-7);cout<<"°±²ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»²±°";
	   gotoxy(14,m-l-6);cout<<"°±²Ί                                              Ί²±°";
	   gotoxy(14,m-l-5);cout<<"°±²Ί                Men£ Personal                 Ί²±°";
	   gotoxy(14,m-l-4);cout<<"°±²Ί                                              Ί²±°";
	   gotoxy(14,m-l-3);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
	   gotoxy(14,m-l-2);cout<<"°±²Ί     1. Ingresar Nuevo Registro               Ί²±°";
	   gotoxy(14,m-l-1);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
	   gotoxy(14,m-l);cout<<"°±²Ί     2. Buscar un Registro                    Ί²±°";
	   gotoxy(14,l);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
	   gotoxy(14,l+1);cout<<"°±²Ί     3. Buscar un Registro Alfabeticamente    Ί²±°";
	   gotoxy(14,l+2);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
	   gotoxy(14,l+3);cout<<"°±²Ί     4. Eliminar un Registro                  Ί²±°";
	   gotoxy(14,l+4);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
	   gotoxy(14,l+5);cout<<"°±²Ί     5. Entrar al Calendario                  Ί²±°";
	   gotoxy(14,l+6);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
	   gotoxy(14,l+7);cout<<"°±²Ί     6. Desactivar/Activar Animaciones        Ί²±°";
	   gotoxy(14,l+8);cout<<"°±²ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ²±°";
	   gotoxy(50,24);cout<<" ΐ-> Sale con (x)";
	   delay (35);
	   }
	   for (l2;l2<5;l2++)
	     {
	     for (int r=0;r<3;r++)
	       {
	       switch(r)
		 {
		 case 0:
			gotoxy(14,5);cout<<"°±²ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»²±°";
			gotoxy(14,6);cout<<"°±²Ί                                              Ί²±°";
			gotoxy(14,7);cout<<"°±²Ί                Men£ Personal                 Ί²±°";
			gotoxy(14,8);cout<<"°±²Ί                                              Ί²±°";
			gotoxy(14,9);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
			gotoxy(14,10);cout<<"°±²Ί     1. Ingresar Nuevo Registro               Ί²±°";
			gotoxy(14,11);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
			gotoxy(14,12);cout<<"°±²Ί     2. Buscar un Registro                    Ί²±°";
			gotoxy(14,13);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
			gotoxy(14,14);cout<<"°±²Ί     3. Buscar un Registro Alfabeticamente    Ί²±°";
			gotoxy(14,15);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
			gotoxy(14,16);cout<<"°±²Ί     4. Eliminar un Registro                  Ί²±°";
			gotoxy(14,17);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
			gotoxy(14,18);cout<<"°±²Ί     5. Entrar al Calendario                  Ί²±°";
			gotoxy(14,19);cout<<"°±²ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ²±°";
			gotoxy(14,20);cout<<"°±²Ί     6. Desactivar/Activar Animaciones        Ί²±°";
			gotoxy(14,21);cout<<"°±²ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ²±°";
			gotoxy(50,24);cout<<" ΐ-> Sale con (x)";


			break;
		 case 1:
			gotoxy(14,5);cout<<"±²°ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»°²±";
			gotoxy(14,6);cout<<"±²°Ί                                              Ί°²±";
			gotoxy(14,7);cout<<"±²°Ί                Men£ Personal                 Ί°²±";
			gotoxy(14,8);cout<<"±²°Ί                                              Ί°²±";
			gotoxy(14,9);cout<<"±²°ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ°²±";
			gotoxy(14,10);cout<<"±²°Ί     1. Ingresar Nuevo Registro               Ί°²±";
			gotoxy(14,11);cout<<"±²°ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ°²±";
			gotoxy(14,12);cout<<"±²°Ί     2. Buscar un Registro                    Ί°²±";
			gotoxy(14,13);cout<<"±²°ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ°²±";
			gotoxy(14,14);cout<<"±²°Ί     3. Buscar un Registro Alfabeticamente    Ί°²±";
			gotoxy(14,15);cout<<"±²°ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ°²±";
			gotoxy(14,16);cout<<"±²°Ί     4. Eliminar un Registro                  Ί°²±";
			gotoxy(14,17);cout<<"±²°ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ°²±";
			gotoxy(14,18);cout<<"±²°Ί     5. Entrar al Calendario                  Ί°²±";
			gotoxy(14,19);cout<<"±²°ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ°²±";
			gotoxy(14,20);cout<<"±²°Ί     6. Desactivar/Activar Animaciones        Ί°²±";
			gotoxy(14,21);cout<<"±²°ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ°²±";
			gotoxy(50,24);cout<<" ΐ-> Sale con (x)";

			break;
		 case 2:
			gotoxy(14,5);cout<<"²°±ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»±°²";
			gotoxy(14,6);cout<<"²°±Ί                                              Ί±°²";
			gotoxy(14,7);cout<<"²°±Ί                Men£ Personal                 Ί±°²";
			gotoxy(14,8);cout<<"²°±Ί                                              Ί±°²";
			gotoxy(14,9);cout<<"²°±ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ±°²";
			gotoxy(14,10);cout<<"²°±Ί     1. Ingresar Nuevo Registro               Ί±°²";
			gotoxy(14,11);cout<<"²°±ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ±°²";
			gotoxy(14,12);cout<<"²°±Ί     2. Buscar un Registro                    Ί±°²";
			gotoxy(14,13);cout<<"²°±ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ±°²";
			gotoxy(14,14);cout<<"²°±Ί     3. Buscar un Registro Alfabeticamente    Ί±°²";
			gotoxy(14,15);cout<<"²°±ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ±°²";
			gotoxy(14,16);cout<<"²°±Ί     4. Eliminar un Registro                  Ί±°²";
			gotoxy(14,17);cout<<"²°±ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ±°²";
			gotoxy(14,18);cout<<"²°±Ί     5. Entrar al Calendario                  Ί±°²";
			gotoxy(14,19);cout<<"²°±ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ±°²";
			gotoxy(14,20);cout<<"²°±Ί     6. Desactivar/Activar Animaciones        Ί±°²";
			gotoxy(14,21);cout<<"²°±ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ±°²";
			gotoxy(50,24);cout<<" ΐ-> Sale con (x)";
			break;
		 }
		 delay(60);
	       }
	     }
	   break;

  }
}


void calendario ()
{
clrscr();
FILE * m=fopen (calendar","r+b");
if(m==NULL){gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
else
{
calen r;
char w;long pos,pos2;
pos=ftell(m);
fread(&r,sizeof(r),1,m);
visualcalen(r,w);
while (w!='X')
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
          gotoxy(h-1,t);cout<<"Ί";
          gotoxy(h-1,t-1);cout<<"Ι";
          gotoxy(h-1,t+1);cout<<"Θ";
          gotoxy(h,t-1);cout<<"ΝΝ";
          gotoxy(h,t+1);cout<<"ΝΝ";
          gotoxy(h+2,t);cout<<"Ί";
          gotoxy(h+2,t-1);cout<<"»";
          gotoxy(h+2,t+1);cout<<"Ό";
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
int f;char o,p;
cout<<"Ingrese fecha de anotacion";
cin>>f;
for (int i=0;i<38 && r.mes[i].date!=f;i++);
if (i==38)
{clrscr();gotoxy(1,1);cout<<"ingreso mal la fecha";}
else
  {
  cout<<"\nAgendar:   (C) Cumple A€os    (A) Anotacion    (S)Salir";
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
             cout<<"\n¨Desea continuar? (S) Si  (N) No";
             cin>>o;o=tolower(o);
             }while(o!='s'&&o!='n');
           }
           if(o=='n')break;
           cout<<"\nEmpeza a escribir\n";
           gets(r.mes[i].notas);
           break;
  case 'c'://cumple a€os
           o=' ';
           if(r.mes[i].ca.marc==1)
           {
           do
             {
             cout<<"\nSi realiza una nueva anotacion se perderan las notas anteriores";
             cout<<"\n¨Desea continuar? (S) Si  (N) No";
             cin>>o;o=toupper(o);
             }while(o!='s'&& o!='n');
           }
           if(o=='n')break;
           cout<<"\nNombre de Cumpla€ero\n";
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
  cout<<"\nNo Olvides Saludar a  "<<r.mes[i].ca.nom<<" \n por que hoy Cumple A€os...\n";getch();
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
cout<<"(A) Borrar Anotaciones   (C)Borrar Cumplea€os  (S) Salir";
do
  {
  o=getche();
  o=tolower(o);
  }
while(o!='a' && o!='c' && o!='s');
cout<<"\nIngrese Fecha de la Anotacion/Cumplea€os\n";
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

case 'c': //borrar cumple€os
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
