#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <ctype.h>
#include "c:\bc\bin\agenda.cpp"


void main()
{
char m,us[20],pas[20],pas2[20],cnom[8],r[20],M;FILE *f;int i=0,anim=0;
clrscr();
presentacion();
menu:;
menus (0,anim);
do{M=getch();M=tolower(M);}while (M!='1'&&M!='2'&&M!='3');

while (M!='3')
{
switch(M)
  {
  case '1'://Crear nuevo usuario
       strcpy (us,newus());
       cerear(us);
       cnom[0]='c';
       strcpy (r,us);
       for(i=1;i<9;i++) cnom[i]=r[i-1];
       renom (cnom);
       break;
  case '2'://Usuario existente
	   anim=0;
       ver();
       gotoxy(27,16);cout<<"Ingrese el nombre de Usuario";
	   gotoxy(30,17);gets(us);
       cnom[0]='c';
       strcpy (r,us);
       for(i=1;i<9;i++) cnom[i]=r[i-1];
       f=fopen(us,"rb");
	   if(f==NULL) {gotoxy(25,16);cout<<"     Usuario   Inexistente    ";getch();goto menu;}
	   else
	     {
         gotoxy(32,19);cout<<"Ingrese pasword   ";
	     gotoxy(30,20);gets(pas);
	     fseek(f,540*sizeof(agenda),SEEK_SET);
	     fread(&pas2,sizeof(pas2),1,f);
	     if(strcmp(pas,pas2)!=0)
	     {
	     for(i=0;i<2;i++)
	       {
           gotoxy(32,19);cout<<"Pasword Incorrecto";
           gotoxy(30,20);cout<<"                  ";
           delay(700);
	       gotoxy(32,19);cout<<"Ingrese pasword   ";
	       gotoxy(30,20);gets(pas);
	       if(strcmp(pas,pas2)==0)
	       break;
	       }
	       if(i==2) exit(1);
	      }
          fclose(f);
	     }
	   break;
  }

  do
  {
  clrscr();
  menus (1,anim);
  m=getch();
  m=tolower(m);
  switch(m)
    {
    case '1'://Nuevo registro
	     newreg(us);
	     break;
    case '2'://Buscar registro
	     buscar (us);
	     break;
    case '3'://Recorre el archivo alfabeticamente
	     alfabeta (us);
	     break;
    case '4'://Elimina Registro
	     eliminar(us);
	     break;
    case '5'://Calendario
	     calendario (cnom);
	     break;
    case '6'://Desactiva/Activa las animaciones
	     char anim2;
	     if (anim==0)
	       {gotoxy(20,25);cout<<"Desea desactivar las animaciones (s/n)?";
	       anim2=getch();anim2=tolower(anim2);
	       if (anim2=='s') anim=1;}
	     else
	       {gotoxy(20,25);cout<<"\nDesea activar las animaciones (s/n)?";
	       anim2=getch();anim2=tolower(anim2);
	       if (anim2=='s') anim=0;}

    }
  }
while (m!='x');
clrscr();
menus (0,anim);
do{M=getch();M=tolower(M);}while (M!='1' && M!='2' && M!='3');
}

}


















                                             


