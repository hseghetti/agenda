#include <iostream.h>
#include <conio.h>
#include <ctype.h>

float promedio (int d,int s);
void inicializar (int v[10]);
void contar (int v[10],char n);
void mostrar (int v[10]);
int ispar (char n);

void main()
{
int v[10],flag=0,ci=0,cp=0,cd=0,cs=0,p1=0;
char n;
float p;

inicializar (v);

do
{
n=getche();
if (isdigit(n))
   {
   flag=1;
   if(ispar(n)==1)
   cp++;
   else
   ci++;
   contar(v,n);
   cd++;
   }
   else
   {
   if (flag==1)
      {
      if(ci==cp)
      p1++;
      ci=cp=0;
      cs++;
      flag=0;
      }
   }
   }
   while(n!='*');

p=promedio (cd,cs);
cout<<"punto uno "<<p1<<endl<<"promedio"<<p<<endl;
mostrar(v);
getch();

}

float promedio(int d, int s)
{
float p;
p=(float) d/s;
return p;
}

void inicializar (int v[10])
{
for(int i=0;i<10;i++)
v[i]=0;
}

int ispar(char n)
{
int p;
if (isdigit (n))
{
if (n%2==0)
p=1;
else
p=0;
}
else
p=1;
return p;
}

void mostrar(int v[10])
{
for(int i=0; i<10;i++)
cout<<"numero  "<<i<<"ingresado  "<<v[i]<<endl;
}

void contar (int v[10],char n)
{
switch (n)
{
case '0':v[0]++;
         break;
case '1':v[1]++;
         break;
case '2':v[2]++;
         break;
case '3':v[3]++;
         break;
case '4':v[4]++;
         break;
case '5':v[5]++;
         break;
case '6':v[6]++;
         break;
case '7':v[7]++;
         break;
case '8':v[8]++;
         break;
case '9':v[9]++;
         break;
}
}