#include <iostream.h>
#include <conio.h>
#include <ctype.h>

int espar (int num);

void main ()
{
   int flag,flag8,flag4,flag2,cd,cdmen,c75,c842,ccomb,ccombprov,par,cpar;
   char n,nant,nanter;
   nant=nanter=' ';
   flag=flag8=flag4=flag2=cd=c75=c842=ccomb=ccombprov=cpar=0;
   cdmen=999;
   textattr (26);
   clrscr ();
   cout<<"ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n";
   cout<<"º DigitOperator v3.2 º\n";
   cout<<"ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n";
   cout<<"Ingrese d¡gitos en secuencias: ";
   do
   {
      n=getche ();
      if (isdigit(n))
      {
         cd++;
         flag=1;
         if (n=='5')
         {
            if (nant=='7')
            {
               if (!isdigit(nanter)) c75++;
            }
         }
         if (n=='8') flag8=1;
         if (n=='4') flag4=1;
         if (n=='2') flag2=1;
         if ((n=='4'&&nant=='5')||(n=='2'&&nant=='1')||(n=='5'&&nant=='4')) ccombprov++;
         par=espar(n);
         if (par==1) cpar++;
      }
      else
      {
         if (flag==1)
         {
            if (cd<cdmen) cdmen=cd;
            if (flag8==1&&flag4==1&&flag2==1) c842++;
            flag8=0;flag4=0;flag2=0;
            if (ccombprov>=1&&cd>5)
            {
               ccomb++;
               ccombprov=0;
            }
            cd=0;
         }
      }
   nanter=nant;
   nant=n;
   }
   while (n!='#');
   if (cdmen==999) cdmen=0;
   clrscr ();
   cout<<"Û²±° An lisis de Secuencias °±²ÛÝ\n\n";
   cout<<"Secuencias que comienzan con '75': "<<c75<<"\n";
   cout<<"Secuencias que contienen '4', '8' y '2': "<<c842<<"\n";
   cout<<"Cantidad de d¡gitos pares: "<<cpar<<"\n";
   cout<<"Secuencias que contienen '54', '12' y '45' (con m s de 5 d¡gitos): "<<ccomb<<"\n";
   cout<<"Longitud de la secuencia m s corta: "<<cdmen<<"\n";
   getch ();
}

int espar (int num)
{
   if (num=='0'||num=='2'||num=='4'||num=='6'||num=='8') return 1;
   else return 0;
}


