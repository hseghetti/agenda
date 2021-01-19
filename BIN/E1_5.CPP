#include <iostream.h>
#include <conio.h>
void menor();
void calculos();
float men,cubo,cuad,a,b,c;

void main()
{
cin>>a;cin>>b;cin>>c;
menor();
calculos();
cout<< "el menor es"<<men<<endl<<"el cubo es"<<cubo<<endl<<"el cuadrado es"<<cuad;
getch();
}

void menor()
{
if (a<b&&a<c)men=a;
 else
 {if(b<c)men=b;else men=c;}
}
void calculos()
{
cubo= men*men*men;
cuad= men*men;
}


