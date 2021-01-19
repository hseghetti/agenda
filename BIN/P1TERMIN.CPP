#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
void main()
{
int cont,cm,cf,cp,may,edad;
char sexo,sexmay;
float prom,dni,dnimay;
cont=cm=cf=cp=may=0;

gotoxy(10,1);
cout<<"INGRESE LOS DATOS SOLICITADOS"<<endl<<"la carga finalizara cuando el D.N.I. ingresado sea 0"<<endl;
cout<<endl<<endl;
cout<<"presione una tecla para inicializar la carga de datos";
getch();
clrscr();

gotoxy(5,1);
cout<<"Ingrese D.N.I.";
do
{
gotoxy(5,2);
cin>>(float)dni;
}
while(dni<0);

while(dni!=0)
      {
      cont++;

gotoxy(5,4);
cout<<"Ingrese Edad";
do
{
gotoxy(5,5);
cin>>(int)edad;
}
while(edad<0);
gotoxy(5,7);
cout<<"Ingrese Sexo (ùMù para Masculino -ùFù para Femenino)";
do
{
gotoxy(5,8);
sexo=(char)getche();
sexo=toupper(sexo);
}
while(sexo!='F'&&sexo!='M');
clrscr();


      if(sexo=='M')
      cm++;
      else
      cf++;

      if(edad>16 && edad<65)cp++;
      prom=(float) cp*100/cm;

      if(edad>may)
              {
              may=edad;
              sexmay=sexo;
              dnimay=(float)dni;
              }
      gotoxy(1,20);cout<<"personas censadas hasta el momento: "<<cont;

      gotoxy(5,1);
      cout<<"Ingrese D.N.I.";
      do
      {
      gotoxy(5,2);
      cin>>(float)dni;
      }
      while(dni<0);

            }

clrscr();
if(cont==0)
cout<<"No se han ingresado datos";
else
{
cout<<"Total de personas censadas"<<endl;
cout<<       cont<<endl;
cout<<"Censados de sexo Masculino"<<endl;
cout<<       cm<<endl;
cout<<"Censados de sexo Femenino"<<endl;
cout<<       cf<<endl;
cout<<endl;
cout<<"Porcentaje de censados de sexo masculino cuya edad varia entre 16 y 65 a¤os"<<endl;
cout<<       prom<<endl;
cout<<endl;
cout<<"Datos de la persona mayor"<<endl;
cout<<       "Edad:"<< may<<endl;
cout<<       "Sexo:"<<sexmay<<endl;
cout<<       "dni:"<<dnimay<<endl;
}
getch();
clrscr();
}






