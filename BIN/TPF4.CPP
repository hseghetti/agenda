#include <mouse.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <dos.h>
#define N 30

void Cerear (int xClP [3][5],int xEd[N][6],int xVc[],int xVa[]);
void Carga (int xCl[N][5],int xEd[N][6],char xNom[N][20],int xVa[],int &i);
int Niniera(int xEd [N][6],int Va[],int y);
void NuMa (int xCl[N][5],int xClP[3][5],int xi);
void Contar (int xCl[N][5],int xVc[],int xVa[],int xi);
void Listado(int xCl[N][5],int xEd[N][6],char xNom[N][20],int xVa[] ,int xi);
//Funciones de ayuda Graficas
void Clases (int xp);void Prof (int xr);
void Viaje (int xr);void Destino (int xr);

void main ()
{
//Declaracion de Variables
int Cl[N][5],Ed[N][6],ClP[3][5],Vc[3],Va[N],n,i=0;
char Nom[N][20],L;
clrscr();
Cerear (ClP,Ed,Vc,Va);
do
{
clrscr();
gotoxy(4,4);cout<<"旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커";
gotoxy(4,5);cout<<"�                Elija una opci줻                    �";
gotoxy(4,6);cout<<"�                                                    �";
gotoxy(4,7);cout<<"� 1. Iniciar Carga de Datos                          �";
gotoxy(4,8);cout<<"� 2. Cantidad de Ni쨎ras Necesarias                  �";
gotoxy(4,9);cout<<"� 3. Clasificacion de clientes por Profesion         �";
gotoxy(4,10);cout<<"� 4. Cantidad de Personas por clase de viaje         �";
gotoxy(4,11);cout<<"� 5. Solteros con mas de 30 a쨚s y sin acompa쨅ntes  �";
gotoxy(4,12);cout<<"� 6. Iniciar Nueva Carga                             �";
gotoxy(4,13);cout<<"�                                                    �";
gotoxy(4,14);cout<<"�                           Presione \"F\" para salir  �";
gotoxy(4,15);cout<<"읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸";
gotoxy(50,5);L=getch();L=tolower(L);
	switch(L)
    {
       case '1':
            Carga (Cl,Ed,Nom,Va,i);
            break;
       case '2':
			n=Niniera(Ed,Va,i);
            gotoxy(4,17);cout<<"                           旼컴커 ";
		    gotoxy(4,18);cout<<"La cantidad de ni쨎ras es: �    � ";
		    gotoxy(4,19);cout<<"                           읕컴켸 ";
            gotoxy(33,18);cout<<n;getch();
            break;
       case '3':
       		NuMa (Cl,ClP,i);
            break;
       case '4':
			Contar (Cl,Vc,Va,i);
            break;
       case '5':
			Listado (Cl,Ed,Nom,Va,i);
            break;
       case '6':
	        Cerear(ClP,Ed,Vc,Va);i=0;
            clrscr();
            gotoxy(22,6);cout<<"Han sido borrados los datos anteriores";
            gotoxy(22,7);cout<<"  Puede comenzar con una nueva carga";
            getch();
            break;
	}
}
while (L!='f');
}

//Funciones

void Cerear (int xClP [3][5],int xEd[N][6],int xVc[],int xVa[])
{
for (int i=0;i<3;i++)
  {
  xVc[i]=0;
  for (int j=0;j<5;j++) xClP[i][j]=0;
  }
for (i=0;i<N;i++)
  {
  xVa[i]=0;
  for (int j=0;j<6;j++) xEd[i][j]=100;
  }

}

void Carga (int xCl[N][5],int xEd[N][6],char xNom[N][20],int xVa[],int &i)
{
clrscr();
gotoxy(3,2);cout<<"Ingrese Nombre del Cliente:  ";
gets(xNom[0]);
for (int j=0;j<20;j++)
xNom[0][j]=toupper(xNom[0][j]);
while (i<N && (xNom[i][0]!='E' || xNom[i][1]!='X' || xNom[i][2]!='I' || xNom[i][3]!='T'))
{
    xCl[i][0]=i+1;
    gotoxy(3,4);cout<<"旼컴� ";
    gotoxy(3,5);cout<<"�   � Estado Civil";
    gotoxy(3,6);cout<<"읕컴� ";
    gotoxy(3,7);cout<<"旼컴� ";
    gotoxy(3,8);cout<<"�   � Profesi줻";
    gotoxy(3,9);cout<<"읕컴� ";
    gotoxy(3,10);cout<<"旼컴� ";
    gotoxy(3,11);cout<<"�   � Clase de Viaje";
    gotoxy(3,12);cout<<"읕컴� ";
    gotoxy(3,13);cout<<"旼컴� ";
    gotoxy(3,14);cout<<"�   � Destino";
    gotoxy(3,15);cout<<"읕컴� ";
  	do{
    Clases(0);
    gotoxy(5,5);cout<<"  ";
    gotoxy(5,5);cin>>xCl[i][1];} while (xCl[i][1]<0 || xCl[i][1]>2);
	do{
    Clases(1);
    gotoxy(5,8);cout<<"  ";
    gotoxy(5,8);cin>>xCl[i][2];} while (xCl[i][2]<0 || xCl[i][2]>4);
	do{
    Clases (2);
    gotoxy(50,13);cout<<"                   ";gotoxy(50,14);cout<<"                   ";
 	gotoxy(50,15);cout<<"                   ";gotoxy(50,16);cout<<"                   ";
    gotoxy(5,11);cout<<"  ";
    gotoxy(5,11);cin>>xCl[i][3];} while (xCl[i][3]<0 || xCl[i][3]>2);
	do{
    Clases(3);
    gotoxy(5,14);cout<<"  ";
	gotoxy(5,14);cin>>xCl[i][4];} while (xCl[i][4]<0 || xCl[i][4]>3);
    clrscr();
	do
	{gotoxy(3,3);cout<<"                  旼컴커 ";
  	gotoxy(3,4);cout<<"Edad del Cliente: �    � ";
    gotoxy(3,5);cout<<"                  읕컴켸 ";
    gotoxy(23,4);cout<<"  ";
	gotoxy(23,4);cin>>xEd[i][0];} while (xEd[i][0]<0);
	do
	{gotoxy(3,6);cout<<"                           旼컴커 ";
  	gotoxy(3,7);cout<<"Cantidad de Acompa쨅ntes:  �    � ";
    gotoxy(3,8);cout<<"                           읕컴켸 ";
    gotoxy(32,7);cout<<"  ";
	gotoxy(32,7);cin>>xVa[i];}while (xVa[i]<0 || xVa[i]>5);
	if (xVa[i]!=0)
	{
		for (int t=1;t<xVa[i]+1;t++)
		{gotoxy(38,t+6);cout<<"Ingrese la edad del "<<t<<"� acompa쨅nte: ";
		gotoxy(75,t+6);cin>>xEd[i][t];}
	}
clrscr();
i++;
gotoxy(3,2);cout<<"								";
gotoxy(3,2);cout<<"Ingrese Nombre del Cliente:  ";
gets(xNom[i]);
for (int j=0;j<20;j++)
xNom[i][j]=toupper(xNom[i][j]);

}

}


int Niniera(int xEd [][6],int Va[],int y)
{
int i,j,cedad=0,nin;
for(i=0;i<y;i++)
{
  for(j=1;j<Va[i];j++)
     if(xEd[i][j]<8) cedad++;

}
nin=cedad/5;
if (cedad<5) return(1);
else
  if (nin%5==0)
  return (nin);
  else
  return (nin+1);
}


void NuMa (int xCl[N][5],int xClP[3][5],int xi)
{
int y,w,j,t;
for (j=0;j<xi;j++) xClP[xCl[j][3]][xCl[j][2]]++;


clrscr();
gotoxy(23,3);cout<<"            a                   ";
gotoxy(23,4);cout<<"            b                   ";
gotoxy(23,5);cout<<"            g    i    v    e    ";
gotoxy(23,6);cout<<"            d    n    e    s    ";
gotoxy(23,7);cout<<"            o    g    t    t    ";
gotoxy(23,8);cout<<"          旼컴컫컴컴쩡컴컫컴컴� ";
gotoxy(23,9);cout<<"      Vip �    �    �    �    � ";
gotoxy(23,10);cout<<"          쳐컴컵컴컴탠컴컵컴컴� ";
gotoxy(23,11);cout<<" Est쟮dar �    �    �    �    � ";
gotoxy(23,12);cout<<"          쳐컴컵컴컴탠컴컵컴컴� ";
gotoxy(23,13);cout<<"Econ줺ica �    �    �    �    � ";
gotoxy(23,14);cout<<"          읕컴컨컴컴좔컴컨컴컴� ";
y=9;
for (j=0;j<3;j++)
{
    w=35;
	for (t=0;t<4;t++)
    {
    gotoxy(t+w,j+y);cout<<xClP[j][t];
    w+=4;
    delay(100);
    }
    y+=1;
    delay(100);
}
getch();
}



void Contar (int xCl[N][5],int xVc[],int xVa[],int xi)
{
int z=6;
clrscr();
Clases(2);
for (int j=0;j<xi;j++) xVc[xCl[j][3]]=xVa[j]+1;
gotoxy(10,2);cout<<"Cantidad de personas por \"Clase de Viaje\": ";

for (j=0;j<3;j++)
	{
    gotoxy(10,j+z);cout<<"            旼컴� ";
	gotoxy(10,j+1+z);cout<<"Clase n� "<<j<<"  �   � ";
	gotoxy(10,j+2+z);cout<<"            읕컴� ";
    gotoxy(24,j+1+z);cout<<xVc[j];
    z+=3;
	}
    getch();
}

void Listado(int xCl[N][5],int xEd[N][6],char xNom[N][20],int xVa[] ,int xi)
{
clrscr();
int z=0;
for (int i=0;i<xi;i++)
{
if (xCl[i][1]==0 && xEd[i][0]>30 && xVa[i]==0)
{
gotoxy(10,3);cout<<"  Datos de pasajeros que cumplen las siguientes condiciones: ";
gotoxy(10,5);cout<<"  � Solteros";
gotoxy(10,6);cout<<"  � Mayores de 30 a쨚s";
gotoxy(10,7);cout<<"  � Sin acompa쨅ntes";
gotoxy(1,9);cout<<"旼컴컴컴컴컴컴컴컫컴컴컴쩡컴컴컴컴컴컴쩡컴컴컴컴컴컴쩡컴컴컴컴컴컴컴컴쩡컴컴컴�";
gotoxy(1,10);cout<<"�     Nombre     � Edad �  Profesi줻  � Clas. Viaje �     Destino     � n� Cl �";
gotoxy(1,11+z);cout<<"쳐컴컴컴컴컴컴컴컵컴컴컴탠컴컴컴컴컴컴탠컴컴컴컴컴컴탠컴컴컴컴컴컴컴컴탠컴컴컴�";
gotoxy(1,12+z);cout<<"�                �      �             �             �                 �       �";
gotoxy(1,13+z);cout<<"쳐컴컴컴컴컴컴컴컵컴컴컴탠컴컴컴컴컴컴탠컴컴컴컴컴컴탠컴컴컴컴컴컴컴컴탠컴컴컴�";
gotoxy(6,12+z);cout<<xNom[i];gotoxy(21,12+z);cout<<xEd[i][0];gotoxy(27,12+z);Prof(xCl[i][2]);
gotoxy(42,12+z);Viaje(xCl[i][3]);gotoxy(55,12+z);Destino(xCl[i][4]);gotoxy(75,12+z);cout<<(i+1);
z+=2;
gotoxy(1,11+z);cout<<"읕컴컴컴컴컴컴컴컨컴컴컴좔컴컴컴컴컴컴좔컴컴컴컴컴컴좔컴컴컴컴컴컴컴컴좔컴컴컴�";
}
}
if (z==0){gotoxy(33,10);cout<<"No habia solteros";}
getch();
}


//Funciones Graficas

void Clases (int xp)
{
switch(xp)
{
case 0:
    gotoxy(50,4);cout<<"旼컴컴컴컴컴컴컴컴�";
	gotoxy(50,5);cout<<"�     C줰igos     �";
	gotoxy(50,6);cout<<"쳐컴쩡컴컴컴컴컴컴�";
	gotoxy(50,7);cout<<"� 0 � Soltero     �";
	gotoxy(50,8);cout<<"쳐컴탠컴컴컴컴컴컴�";
	gotoxy(50,9);cout<<"� 1 � Casado      �";
	gotoxy(50,10);cout<<"쳐컴탠컴컴컴컴컴컴�";
	gotoxy(50,11);cout<<"� 2 � Divorciado  �";
	gotoxy(50,12);cout<<"읕컴좔컴컴컴컴컴컴�";
    break;

case 1:
    gotoxy(50,4);cout<<"旼컴컴컴컴컴컴컴컴�";
	gotoxy(50,5);cout<<"�     C줰igos     �";
	gotoxy(50,6);cout<<"쳐컴쩡컴컴컴컴컴컴�";
	gotoxy(50,7);cout<<"� 0 � Abogado     �";
	gotoxy(50,8);cout<<"쳐컴탠컴컴컴컴컴컴�";
	gotoxy(50,9);cout<<"� 1 � Ingeniero   �";
	gotoxy(50,10);cout<<"쳐컴탠컴컴컴컴컴컴�";
	gotoxy(50,11);cout<<"� 2 � Veterinario �";
	gotoxy(50,12);cout<<"쳐컴탠컴컴컴컴컴컴�";
	gotoxy(50,13);cout<<"� 3 � Estudiante  �";
    gotoxy(50,14);cout<<"쳐컴탠컴컴컴컴컴컴�";
	gotoxy(50,15);cout<<"� 4 � Otro        �";
	gotoxy(50,16);cout<<"읕컴좔컴컴컴컴컴컴�";
    break;

case 2:
    gotoxy(50,4);cout<<"旼컴컴컴컴컴컴컴컴�";
	gotoxy(50,5);cout<<"�     C줰igos     �";
	gotoxy(50,6);cout<<"쳐컴쩡컴컴컴컴컴컴�";
	gotoxy(50,7);cout<<"� 0 � Vip         �";
	gotoxy(50,8);cout<<"쳐컴탠컴컴컴컴컴컴�";
	gotoxy(50,9);cout<<"� 1 � Estandar    �";
	gotoxy(50,10);cout<<"쳐컴탠컴컴컴컴컴컴�";
	gotoxy(50,11);cout<<"� 2 � Econ줺ica   �";
	gotoxy(50,12);cout<<"읕컴좔컴컴컴컴컴컴�";
    break;

case 3:
    gotoxy(50,4);cout<<"旼컴컴컴컴컴컴컴컴컴커";
	gotoxy(50,5);cout<<"�       C줰igos      �";
	gotoxy(50,6);cout<<"쳐컴쩡컴컴컴컴컴컴컴캑";
	gotoxy(50,7);cout<<"� 0 � Puerto Rico    �";
	gotoxy(50,8);cout<<"쳐컴탠컴컴컴컴컴컴컴캑";
	gotoxy(50,9);cout<<"� 1 � Rep. Dominicana�";
	gotoxy(50,10);cout<<"쳐컴탠컴컴컴컴컴컴컴캑";
	gotoxy(50,11);cout<<"� 2 � Hait�          �";
	gotoxy(50,12);cout<<"쳐컴탠컴컴컴컴컴컴컴캑";
	gotoxy(50,13);cout<<"� 3 � Otro           �";
	gotoxy(50,14);cout<<"읕컴좔컴컴컴컴컴컴컴켸";
    break;
}
}

void Prof (int xr)
{
switch(xr)
{
case 0:
    cout<<"Abogado";break;
case 1:
	cout<<"Ingeniero";break;
case 2:
	cout<<"Veterinario";break;
case 3:
	cout<<"Estudiante";break;
case 4:
    cout<<"Otro";break;
}
}

void Viaje (int xr)
{
switch(xr)
{
case 0:
    cout<<"Vip";break;
case 1:
	cout<<"Est쟮dar";break;
case 2:
	cout<<"Econ줺ica";break;

}
}

void Destino (int xr)
{
switch(xr)
{
case 0:
    cout<<"Puerto Rico";break;
case 1:
	cout<<"Rep. Dominicana";break;
case 2:
	cout<<"Hait�";break;
case 3:
    cout<<"Cuba";break;
}
}

