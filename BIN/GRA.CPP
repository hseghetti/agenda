#include <stdlib.h>
#include <iostream.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <stdio.h>
void present ();
void ini_graficos();
void main()
{
ini_graficos;
int num,tamano;
char mod[42];
int flag; flag=0;

textcolor(2);
present();

do
  {
  gotoxy(25,5);cout<<"INGRESE  EL  NUMERO  DE  PIEZA";
  gotoxy(30,7);cin>>num;
  }
while (num<-1);

while (num !=-1)
  {
  flag=1;
  do
    {
    gotoxy(25,10);cout<<"INGRESE EL TAMAฅO DE LA PIEZA";
    gotoxy(30,12);cin>>tamano;
    }
  while (tamano<1);

  if(num>=200 && num <=300)
  {
  if (tamano==3)
      strcpy(mod,"A - C");
      else
      strcpy(mod,"A");
  }
  else
  {
  if(num>=500 && num<=1000)
     {
     if (tamano==1 || tamano==2)
           strcpy(mod,"A - B");
           else
           {
           if (num>=0 && num<=1000 && tamano >=1 && tamano <=3)
           strcpy(mod,"A");
           else
           strcpy(mod,"NO EXISTE PIEZA CON ESAS CARACTERISTICAS");
           }
     }
     else
     {
     if (num>=0 && num<=1000 && tamano >=1 && tamano <=3)
           strcpy(mod,"A");
           else
           strcpy(mod,"NO EXISTE PIEZA CON ESAS CARACTERISTICAS");
     }
  }

  clrscr();

  gotoxy(12,5);cout<<"LA PIEZA BUSCADA CORRESPONDE AL SIGUIENTE/TES MODELOS:";
  gotoxy(25,7);cout<<mod;
  gotoxy(12,15);cout<<"Presione una tecla para un nuevo ingreso de Datos";
  getch();
  clrscr();
  do
  {
  gotoxy(25,5);cout<<"INGRESE  EL  NUMERO  DE  PIEZA";
  gotoxy(30,7);cin>>num;
  }
  while(num<-1);


  }
  clrscr();
  if(flag==0)
  {
  gotoxy(25,10);cout<<"NO SE INGRESARON DATOS";
  getch();
  }



clrscr();

}

void ini_graficos()
{
int gd = DETECT, gm, errorcode;
initgraph( &gd , &gm , "C:\\BC\\BIN\\BGI");

errorcode = graphresult();
if (errorcode != grOk) /*Con error ocurrido*/
{
printf("Error en graficos: %s\n", grapherrormsg(errorcode));
printf("Presione cualquier tecla para salir:");
getch();
exit(1); /* terminacion con error de codigo */
}
}







void present ()
{
int i,t;
t=0;
textcolor(2);
gotoxy(19,5);cout<<"ษออออออออออออออออออออป";
gotoxy(19,6);cout<<"บ                    บ";
gotoxy(19,7);cout<<"ศออออออออออออออออออออผ";

for (i=34;i>20;i--)
{
gotoxy(i,3);cout<<"C ";
delay(50);
}

for (i=34;i>22;i--)
{
gotoxy(i,3);cout<<"A ";
delay(50);
}

for (i=34;i>24;i--)
{
gotoxy(i,3);cout<<"R ";
delay(50);
}

for (i=34;i>26;i--)
{
gotoxy(i,3);cout<<"G ";
delay(50);
}

for (i=34;i>28;i--)
{
gotoxy(i,3);cout<<"A ";
delay(50);
}

for (i=34;i>30;i--)
{
gotoxy(i,3);cout<<"N ";
delay(50);
}

for (i=34;i>32;i--)
{
gotoxy(i,3);cout<<"D ";
delay(50);
}

for (i=37;i>34;i--)
{
gotoxy(i,3);cout<<"O ";
delay(50);
}

for (i=20;i<40; i++)
{
t++;
gotoxy(i,6);cout<<"ฒ";
gotoxy(29,8);cout<<  t*5 ;
delay(200);
}    clrscr();
gotoxy(10,10);cout<<"PRECIONE UNA TECLA PARA INCICIAR LA CARGA DE DATOS";
gotoxy(9,15);cout<<"La Carga Finaliza Ingresando Como Numero de pieza \" -1\" ";
getch();
clrscr();
}

