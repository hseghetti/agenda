#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

struct agenda
{
char nom[20];
int tel;
};

struct index
{
char nom[20];
long prox;
};

void inicial();

void main()
{
clrscr();
int l;
cout<<"opcion";
cin>>l;

switch(l)
{
case 0:
inicial();
break;

case 1:
agenda a,a2;
index m;
int dis=0;
int can;
long posagenda=1;
char nom[20];
FILE *f=fopen("c:\\agenda.dat","a+b");
FILE *I=fopen("c:\\indice.dat","a+b");

cout<<"ingresar nombre";
gets(nom);
while(strcmp(nom,"exit")!=0)
{
dis=0;
can=strlen(nom);
for (int i=0;i<=can;i++)    dis+=(nom[i]%103);
dis=dis%103;
cout<<endl<<"VALOR DE DISPERSION"  <<dis<<endl;

fseek(I,dis*sizeof(m),SEEK_SET);
fread(&m,sizeof(m),1,I);
   //ingreso de datos
   cout<<"\n ingrese telefono";cin>>a.tel;   cout<<endl;
   strcpy(a.nom,nom);

   //verifica posicion vacia
   cout<<"contenido de nom " <<m.nom;getch(); cout<<endl;

   cout<<"antes del if";  cout<<endl;

   cout<<strcmp(m.nom,"null");
   if(strcmp(m.nom,"null")==0)
   {
   cout<<endl<<"lugar de dispersion NULL"<<endl;
   getch();
   while(feof(f)==0)
   {
   fread(&a2,sizeof(a2),1,f);
   posagenda=ftell(f);
   cout<<posagenda;getch();
   }
   //COPIAR CAMPOS DE M (REGISTRO PARA GRABAR EN LA AGENDA)
   cout<<endl<<"posagenda"  <<posagenda;getch();
   strcpy(m.nom,nom);
   if(posagenda==0) posagenda=1;
   m.prox=posagenda;cout<<"verificacion de prox"  <<m.prox;
   fseek(f,m.prox*sizeof(a),SEEK_SET);
   fwrite(&a,sizeof(a),1,f);
   fseek(I,dis*sizeof(m),SEEK_SET);
   fwrite(&m,sizeof(m),1,I);

   }
   else
   {
   cout<<"no anda";
   getch();
   }
cout<<"ingresar nombre";
gets(nom);
}

clrscr();  long salto;
cout<<"INGRESE NOMBRE A BUSCAR";
gets(nom);
dis=0;
can=strlen(nom);
for (int i=0;i<=can;i++)    dis+=(nom[i]%103);
dis=dis%103;
cout<<"dispercion buscada"  <<dis;
rewind(I);
fseek(I,dis*sizeof(m),SEEK_SET);
fread(&m,sizeof(m),1,I);
salto=m.prox;cout<<"direccion"  <<m.prox<<endl;
cout<<"verificacion de nombre"  <<m.nom<<endl;
fseek(f,salto*sizeof(a),SEEK_SET);
fread(&a,sizeof(a),1,f);
cout<<"nombre de agenda"  <<a.nom<<endl;
cout<<"telefono de agenda"  <<a.tel;
getch();
clrscr();
fclose(I);
fclose(f);
}

}

void inicial()
{
index r;
FILE *f=fopen("c:\\indice.dat","wb");
for (int i=1;i<103;i++)
{
fseek(f,i* sizeof(r),SEEK_SET);
strcpy(r.nom,"null");
fwrite(&r,sizeof(r),1,f);
}
fseek(f,100* sizeof(r),SEEK_SET);
fread(&r,sizeof(r),1,f);
cout<<r.nom;
getch();
FILE *j=fopen("c:\\agenda.dat","w+b");
fclose(j);
fclose(f);
clrscr;
}
