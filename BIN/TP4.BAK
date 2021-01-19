#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#define N 5

void carga(int a[N],char b[N][30],float c[N]);
void encontrar (float c[N],char b[N] [30]);
void punto3 (int a[N],float c[N]);
int punto4 (float c[N]);
void ordenar (int a[N],char b[N][30],float c[N]);
int binary_search (int a[N],int pro);

void main()
{
textcolor(2);
int a[N];
char b[N] [30];
float c[N];
int pro,i,p4;

carga (a,b,c);
encontrar(c,b);
punto3(a,c);
p4=punto4(c);
gotoxy(2,10);cout<<"ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
gotoxy(2,12);cout<<"บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ";
gotoxy(2,13);cout<<"บ cantidad de productos que superan el promedio de ventas บ                 บ";
gotoxy(2,14);cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
gotoxy(65,13);cout<<p4;
ordenar(a,b,c);
gotoxy(20,25);cout<<"presione una tecla para buscar producto";
getch();
clrscr();
gotoxy(20,5);cout<<"ingrese el numero de identificacion que desea buscar";
gotoxy(25,6);cout<<"la busqueda finaliza ingresando -1";
gotoxy(30,8);cin>>pro;

while (pro!=-1)
{
i=binary_search(a,pro);
if (i!=-1)
{
gotoxy(20,10);cout<<"numero de identificacion encontrado";
gotoxy(25,12);cout<<"identificacion del producto  "<<b[i];
gotoxy(25,13);cout<<"importe de venta realizada   "<<c[i];
}
else
{
gotoxy(20,10);cout<<"no se encontro el numero de identificacion";
}
gotoxy(20,15);cout<<"presione una tecla para una nueva busqueda";
getch();
clrscr();
gotoxy(20,5);cout<<"ingrese el numero de identificacion que desea buscar";
gotoxy(25,6);cout<<"la busqueda finaliza ingresando -1";
gotoxy(30,8);cin>>pro;

}
clrscr();
}

void carga(int a[N],char b[N][30],float c[N])
{

for (int i=0;i<N;i++)
{
gotoxy(16,4);cout<<"ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป";
gotoxy(16,5);cout<<"บ  Ingrese numero de identificacion del producto :          บ";
gotoxy(16,6);cout<<"บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ";
gotoxy(16,7);cout<<"บ                               Importe de venta :          บ";
gotoxy(16,8);cout<<"บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ";
gotoxy(16,9);cout<<"บ                 Descripcion del producto                  บ";
gotoxy(16,10);cout<<"บ                                                           บ";
gotoxy(16,11);cout<<"บ                                                           บ";
gotoxy(16,12);cout<<"ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
gotoxy(66,5);cin>>a[i];
gotoxy(66,7);cin>>c[i];
gotoxy(20,11);gets(b[i]);
clrscr();
}
}

void encontrar (float c[N],char b[N] [30])
{
float may=0;int p;
for(int i=0; i<N;i++)
{
if (c[i]>may)
{
may=c[i];
p=i;
}
}
gotoxy(20,4);cout<<"ษออออออออออออออออออออออออออออออออออออออออป";
gotoxy(20,5);cout<<"บ producto de mayor venta บ              บ";
gotoxy(20,6);cout<<"บออออออออออออออออออออออออออออออออออออออออบ";
gotoxy(20,7);cout<<"บ monto de la venta       บ              บ";
gotoxy(20,8);cout<<"ศออออออออออออออออออออออออออออออออออออออออผ";
gotoxy(48,5);cout<<b[p];
gotoxy(48,7);cout<<may;
}


void punto3 (int a[N],float c[N])
{
int m=0;
for(int i=0;i<N;i++)
{
if ((c[i]-350)==500)
{
m++;
gotoxy(18,17);cout<<"N๘de indent. de prod. que representan $500 de ganancia";
gotoxy(22,(17+m));cout<<a[i];
}
}
}
int punto4 (float c[N])
{
float ac=0,pro;int cont=0;
for(int i=0;i<N;i++)
ac+=c[i];
pro=ac/N;
gotoxy(2,11);cout<<"บ promedio de ventas                                      บ                 บ";
gotoxy(65,11);cout<<pro;
for(i=0;i<N;i++)
{
if (c[i]>pro)
cont++;
}
return cont;
}

void ordenar (int a[N],char b[N][30],float c[N])
{
int aux1;
char aux2[30];
float aux3;
for(int i=0; i<N-1;i++)
{
for (int j=i+1;j<N;j++)
    {
    if(a[i]>a[j])
       {
       aux1=a[i];
       a[i]=a[j];
       a[j]=aux1;
       strcpy(aux2,b[i]);
       strcpy(b[i],b[j]);
       strcpy(b[j],aux2);
       aux3=c[i];
       c[i]=c[j];
       c[j]=aux3;
       }
     }
    }
 }

int binary_search (int a[N],int pro)
{
int izq, der,k,band=0;
izq=0; der=N-1;
while(izq<=der &&band==0)
  {
  k=(der+izq)/2;
  if(a[k]==pro)
  band=1;
  else
  {
  if (pro> a[k])
  izq=k+1;
  else
  der=k-1;
  }
  }
if(izq>der)
return -1;
else
return k;
}


