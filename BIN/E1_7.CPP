#include <iostream.h>
#include <conio.h>
#include <string.h>
void newprecio ();
float a,b,c,d,ap,bp,cp,dp,aportea,aporteb,aportec,aported,mayaporte,mayprecio,aportetotal,porcentaje;
char may[20];
void main ()
{
cout<<"cantidad de 1 producto"<<endl;
cin>>a;
cout<<"precio de 1 producto"<<endl;
cin>>ap;
cout<<"cantidad de 2 producto"<<endl;
cin>>b;
cout<<"precio de 2 producto"<<endl;
cin>>bp;
cout<<"cantidad de 3 producto"<<endl;
cin>>c;
cout<<"precio de 3 producto"<<endl;
cin>>cp;
cout<<"cantidad de 4 producto"<<endl;
cin>>d;
cout<<"precio de 4 producto"<<endl;
cin>>dp;
aportea=a*ap;aporteb=b*bp;aportec=c*cp;aported=d*dp;
if (aportea>aporteb &&aportea>aportec && aportea>aported)
          {
           mayaporte=aportea;strcpy(may,"el_primer_producto"); mayprecio=ap;
          }
          else
          {
           if (aporteb>aportec&&aporteb>aported)
                            {
                            mayaporte=aporteb;strcpy(may,"el_segundo_producto");mayprecio=bp;
                            }
                            else
                            {
                            if(aportec>aported)
                                   {
                                   mayaporte=aportec;strcpy(may,"el_tercer_producto");mayprecio=cp;
                                   }
                                   else
                                   {
                                   mayaporte=aported;strcpy(may,"el_cuarto_producto");mayprecio=dp;
                                   }
                            }

          }

aportetotal=aportea+aporteb+aportec+aported;
porcentaje=mayaporte*100/aportetotal;
if (porcentaje>40) mayprecio=mayprecio+(mayprecio*0.5/100);

cout<<"el_producto_que_realizo_mayor_aporte_es:"<<may<<endl;
cout<<"su_aporte_fue_de:"<<mayaporte<<endl;
cout<<"porcentaje_que_representa_dicho_aporte:"<<porcentaje<<endl;
if (porcentaje>40) cout<<"nuevo_precio_unitario_del_producto:"<<mayprecio;
getch();
}
