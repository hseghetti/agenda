#include <iostream.h>
#include <conio.h>
#include <ctype.h>

int espar(char n);

void main()
{
textcolor(2);
char N,pro=0;
int a=0,con=0,flag8=0,flag4=0,flag2=0,b=0,c=0,flag54=0,flag12=0,flag45=0,d=0,men=32767;
do
{
gotoxy(18,5);cout<<"I N G R E S E   S E C U E N C I A   N U M E R I C A";
gotoxy(20,7);cout<<"La Carga Finaliza Con El Ingreso de # (numeral)";

N=getche();

if(isdigit(N))
{
    con++;
    if(N=='5' && pro=='7' && con==2 )
    a++;

    if(N=='4')flag4=1;
    if(N=='8')flag8=1;
    if(N=='2')flag2=1;

    if(espar(N))c++;

    if(pro=='5' && N=='4') flag54=1;
    if(pro=='1' && N=='2') flag12=1;
    if(pro=='4' && N=='5') flag45=1;


    pro=N;
}
else
{
if(flag4==1&&flag8==1&&flag2==1)b++;
if(flag54==1&&flag12==1&&flag45==1&&con>5)d++;
if(con<men)men=con;
con=flag8=flag4=flag2=flag54=flag12=flag45=0;
}

}
while(N!='#');
clrscr();
gotoxy(20,3);cout<<"Cantidad de Secuencias que empiezan con 75";gotoxy(30,5);cout<<a;
gotoxy(13,8);cout<<"Cantidad de secuancias que contienen los digitos 4,8 y 2";gotoxy(30,10);cout<<b;
gotoxy(27,13);cout<<"Cantidad de digitos pares";gotoxy(30,15);cout<<c;
gotoxy(3,18);cout<<"Cantidad de secuencias que tienen los n� 54,12,45;mayores a 5 digitos";gotoxy(30,20);cout<<d;
gotoxy(19,23);cout<<"Cantidad de digitos de la secuencia mas corta";gotoxy(30,25);cout<<men;

getch();
clrscr();
}


int espar(char n)
{
if(n%2==0)
return 1;
else
return 0;
}
