#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
void main()
{
int cont,cm,cf,cp,may,dni,edad,dnimay;
char sexo,sexmay;
float prom;
cont=cm=cf=cp=may=0;

gotoxy(5,1);
cout<<"Ingrese D.N.I.";
gotoxy(5,2);
do
cin>>dni;
while(dni<0);

while(dni!=0)
      {
      cont++;

gotoxy(5,4);
cout<<"Ingrese Edad";
gotoxy(5,5);
do
cin>>edad;
while(edad<0);
gotoxy(5,7);
cout<<"Ingrese Sexo (ùMù para Masculino -ùFù para Femenino)";
gotoxy(5,8);
do
{
sexo=getche();
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
              dnimay=dni;
              }

      gotoxy(5,1);
      cout<<"Ingrese Edad";
      gotoxy(5,2);
      do
      cin>>edad;
      while(edad<0);
      gotoxy(5,4);
      cout<<"Ingrese D.N.I.";
      gotoxy(5,5);
      do
      cin>>dni;
      while(dni<0);
      gotoxy(5,7);
      cout<<"Ingrese Sexo (ùMù para Masculino -ùFù para Femenino)";
      gotoxy(5,8);
      do
      {
      sexo=getche();
      sexo=toupper(sexo);
      }
      while(sexo!='F'&& sexo!='M');
      clrscr();
      }

if(cont==0)cout<<"No se han ingresado datos";
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
getch();
}






