#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

struct comp
{
char nomar[8];
char cumple,date[3];
};


struct calen
{
comp  mes[35];
char nommes[15];
char anio[4];
};

void escribir(char nom[]);
void leer (char dia[]);

void main ()
{
clrscr();
FILE *m=fopen ("calendar","wb");
calen r;
char q,dia[2],arch [8];
int d;
q=getch();
while (q!='x')
{
cout<<"Sale con x....";
cout<<"ingresar el nombre del mes: \n";
gets(r.nommes);
cout<<"Ingresar dias del mes";
for (int i=0;i<35;i++)
  {
  cout<<"Dia "<<i<<" ";
  gets(dia);
  strcpy(r.mes[i].date,dia);
  r.mes[i].cumple='O';
  strcpy(r.mes[i].nomar,"bbbbbbbb");
  strcpy(r.anio,"2003");
  }
fwrite(&r,sizeof(r),1,m);
cout<<"sale con x";
q=getch();
}
fclose(m);

clrscr();
m=fopen ("calendar","r+b");
fread(&r,sizeof(r),1,m);
gotoxy(2,2);cout<<r.nommes;
gotoxy(2,4);cout<<"Domingo   Lunes    Martes   Miercoles  Jueves   Viernes    Sabado  ";
int p=0;
int h=4,t=6;
for (int i=0;i<35;i++)
  {
  if (strcmp(r.mes[i].date,"-1")!=0)
    {
    if (p==7)
      {
      p=0;
      t=t+2;
      h=4;
      }
    gotoxy(h,t);cout<<r.mes[i].date;
    h+=10;
    }
  p++;
  }
char w;long pos;
gotoxy(30,18); cout<<" <--- (a) anterior , siguiente (s) ---> ";
w=getch();
while (w!='x')
{
clrscr();
switch (w)
  {
  case 's':
           fread(&r,sizeof(r),1,m);
           break;
  case 'a':
           pos=ftell(m)-(2 *sizeof(r));
           if (pos>=0)
             {
             fseek(m,pos,SEEK_SET);
             fread(&r,sizeof(r),1,m);
             }
           break;
 case 'q':
           int j=0;
           cout<<"ingresar la fecha para escribir";
           gets(dia);
           for (int i=0;i<8;i++) arch[i]=r.nommes[i];
           for (i=3;i<5;i++) arch[i]=dia[i-3];
           for (i=5;i<8;i++) arch[i]=r.anio[i-4];
           cout<<arch;getch();
           rewind(m);
           fread (&r,sizeof(r),1,m);
           while (!(feof(m)))
             {
             int i=0;
             while (strcmp(r.mes[i].date,dia)!=0 && i<35) i++;
             j=i;
             fread (&r,sizeof(r),1,m);
             break;
             }
            pos=ftell(m)-(2*sizeof(r));
            if (strcmp(r.mes[j].date,dia)==0)
             {
               pos=ftell(m)-(sizeof(r));cout<<"pos: "<<pos;
               if (pos>=0)
               {cout<<"entro";getch();
               strcpy(r.mes[j].nomar,arch);
               fseek(m,pos,SEEK_SET);
               fwrite(&r,sizeof(r),1,m);}
             }
             cout<<j;getch();cout<<"pos: "<<pos;
            fseek(m,pos,SEEK_SET);
            fread(&r,sizeof(r),1,m);
            cout<<r.mes[j].nomar;getch();
           escribir(arch);
           break;
 case 'e':
           clrscr();cout<<"ingresar dia que queres leer";
          cin>>d;
          cout<<" "<<r.mes[d].nomar;getch();
          leer(r.mes[d].nomar);
  }

clrscr();
cout<<r.nommes;
gotoxy(2,4);cout<<"Domingo   Lunes    Martes   Miercoles  Jueves   Viernes    Sabado  ";
int p=0;
int h=4,t=6;
for (int i=0;i<35;i++)
  {
  if (strcmp(r.mes[i].date,"-1"))
    {
    if (p==7)
      {
      p=0;
      t=t+2;
      h=4;
      }
    gotoxy(h,t);cout<<r.mes[i].date;
    h+=10;
    }
  p++;
  }

gotoxy(20,18); cout<<" <--- (a) anterior , siguiente (s) ---> ";
w=getch();

}
fclose(m);
}





void escribir(char nom[])
{
char xnom[8];
for (int i=0;i<8;i++)
{xnom[i]=nom[i];}
cout<<xnom;getch();
FILE *t=fopen(nom,"r+t");
if (t==NULL) {gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
else
  {
  char p;char ap='z';
  cout<<"empeza a escribir";
  p=getche();
  while (p!='*'|| ap!='*')
    {
    ap=p;
    p=getche();
    fputc(p,t);
    }
  fclose(t);
  }
}

void leer (char dia[])
{
FILE *t=fopen(dia,"rt");
if (t==NULL) {gotoxy(1,1);cout<<"error al abrir el archivo";getch();exit(1);}
else
  {
  char car,cara='z';
  car=fgetc(t);cout<<car;getch();
  while (!(feof(t)))
  {cout<<car;
  car=fgetc(t);getch();}



  fclose;
  }
}