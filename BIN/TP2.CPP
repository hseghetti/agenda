#include <stdlib.h>
#include <iostream.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <stdio.h>
/* LOS INCLUDES */
#include <stdlib.h>
#include <dos.h>

void present ();
void ini_graficos();
/* LAS FUNCIONES */

int mtest(void);
void mver(void);
void mocultar(void);
int mxpos(int);
int mypos(int);
void msituar(int, int, int);
int mclick(void);
void mlimit(int, int, int, int, int);


/* LAS VARIABLES */

union REGS reg;


void main()
{
if(mtest==0) cout<<"no se detecto mouse";
else cout<<"hola";
mver;

mxpos(1);
mypos(1);

msituar(1,15,15);


int num,tamano;
char mod[42];
int flag; flag=0;

textcolor(2);
present();

do
  {
  gotoxy(25,5);cout<<"INGRESE  EL  NUMERO  DE  PIEZA";
  gotoxy(30,7);cin>>num;
  }
while (num<-1);

while (num !=-1)
  {
  flag=1;
  do
    {
    gotoxy(25,10);cout<<"INGRESE EL TAMA¥O DE LA PIEZA";
    gotoxy(30,12);cin>>tamano;
    }
  while (tamano<1);

  if(num>=200 && num <=300)
  {
  if (tamano==3)
      strcpy(mod,"A - C");
      else
      strcpy(mod,"A");
  }
  else
  {
  if(num>=500 && num<=1000)
     {
     if (tamano==1 || tamano==2)
           strcpy(mod,"A - B");
           else
           {
           if (num>=0 && num<=1000 && tamano >=1 && tamano <=3)
           strcpy(mod,"A");
           else
           strcpy(mod,"NO EXISTE PIEZA CON ESAS CARACTERISTICAS");
           }
     }
     else
     {
     if (num>=0 && num<=1000 && tamano >=1 && tamano <=3)
           strcpy(mod,"A");
           else
           strcpy(mod,"NO EXISTE PIEZA CON ESAS CARACTERISTICAS");
     }
  }

  clrscr();

  gotoxy(12,5);cout<<"LA PIEZA BUSCADA CORRESPONDE AL SIGUIENTE/TES MODELOS:";
  gotoxy(25,7);cout<<mod;
  gotoxy(12,15);cout<<"Presione una tecla para un nuevo ingreso de Datos";
  getch();
  clrscr();
  do
  {
  gotoxy(25,5);cout<<"INGRESE  EL  NUMERO  DE  PIEZA";
  gotoxy(30,7);cin>>num;
  }
  while(num<-1);


  }
  clrscr();
  if(flag==0)
  {
  gotoxy(25,10);cout<<"NO SE INGRESARON DATOS";
  getch();
  }



clrscr();

}

void ini_graficos()
{
int gd = DETECT, gm, errorcode;
initgraph( &gd , &gm , "C:\\BC\\BIN\\BGI");

errorcode = graphresult();
if (errorcode != grOk) /*Con error ocurrido*/
{
printf("Error en graficos: %s\n", grapherrormsg(errorcode));
printf("Presione cualquier tecla para salir:");
getch();
exit(1); /* terminacion con error de codigo */
}
}







void present ()
{
int i,t;
t=0;
textcolor(2);
gotoxy(19,5);cout<<"ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
gotoxy(19,6);cout<<"º                    º";
gotoxy(19,7);cout<<"ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";

for (i=34;i>20;i--)
{
gotoxy(i,3);cout<<"C ";
delay(50);
}

for (i=34;i>22;i--)
{
gotoxy(i,3);cout<<"A ";
delay(50);
}

for (i=34;i>24;i--)
{
gotoxy(i,3);cout<<"R ";
delay(50);
}

for (i=34;i>26;i--)
{
gotoxy(i,3);cout<<"G ";
delay(50);
}

for (i=34;i>28;i--)
{
gotoxy(i,3);cout<<"A ";
delay(50);
}

for (i=34;i>30;i--)
{
gotoxy(i,3);cout<<"N ";
delay(50);
}

for (i=34;i>32;i--)
{
gotoxy(i,3);cout<<"D ";
delay(50);
}

for (i=37;i>34;i--)
{
gotoxy(i,3);cout<<"O ";
delay(50);
}

for (i=20;i<40; i++)
{
t++;
gotoxy(i,6);cout<<"²";
gotoxy(29,8);cout<<  t*5 ;
delay(200);
}    clrscr();
gotoxy(10,10);cout<<"PRECIONE UNA TECLA PARA INCICIAR LA CARGA DE DATOS";
gotoxy(9,15);cout<<"La Carga Finaliza Ingresando Como Numero de pieza \" -1\" ";
getch();
clrscr();
}

/****************************************************************************

 Nombre: MOUSE.H
 Utilidad: Programaci¢n del rat¢n en aplicaciones D.O.S.
 Autor: Sergio Pacho
 Fecha: 14 de diciembre de 1997
 E-mail: webmaster@cworld.nu
 Web: http://www.cworld.nu

 Este c¢digo est  pensado para que cualquiera pueda incluirlo en sus aplica-
 ciones.

 Lo £nico que te pido es que no modifiques los créditos, y que se lo pases a
 todos tus amigos, colegas...
 Tambi‚n puedes decir que lo has conseguido en:
 http://www.cworld.nu

 Hay m s funciones de las que aparecen aqu¡, pero estas son las m s b sicas,
 y las que utilizar s el 99% de las veces.

****************************************************************************/




/*************************************************/
/* LA FUNCION mtest                              */
/* Esta funci¢n sirve para testear el rat¢n.     */
/* No es necesario enviar ning£n par metro.      */
/* Retorna: 0 => no hay rat¢n instalado.         */
/*          n => el n£mero de botones del rat¢n. */
/*************************************************/

int mtest(void)
{  
	reg.x.ax = 0x0;
	int86(0x33, &reg, &reg);
	if (reg.x.ax > 0) return reg.x.bx; /* n£mero de botones */
	else return 0;
}


/*************************************************/
/* LA FUNCION mver                               */
/* Muestra el puntero del rat¢n.                 */
/* No es necesario enviar ning£n par metro.      */
/* No retorna ning£n valor.                      */
/*************************************************/

void mver(void)
{
	reg.x.ax = 0x1;
	int86(0x33, &reg, &reg);
}


/*************************************************/
/* LA FUNCION mocultar                           */
/* Oculta el puntero del rat¢n.                  */
/* No es necesario enviar ning£n par metro.      */
/* No retorna ning£n valor.                      */
/*************************************************/

void mocultar(void)
{
	reg.x.ax = 0x2;
	int86(0x33, &reg, &reg);
}


/*************************************************/
/* LA FUNCION mxpos                              */
/* Nos dice la coordenada X del rat¢n.           */
/* Es necesario enviar un par metro.             */
/*    1 => modo gr fico.                         */
/*    8 => modo texto.                           */
/* Retorna la posici¢n horizontal del rat¢n.     */
/*************************************************/

int mxpos(int modo)
{
	reg.x.ax = 0x3;
	int86(0x33, &reg, &reg);
	return reg.x.cx/modo;
}


/*************************************************/
/* LA FUNCION mypos                              */
/* Nos dice la coordenada Y del rat¢n.           */
/* Es necesario enviar un par metro.             */
/*    1 => modo gr fico.                         */
/*    8 => modo texto.                           */
/* Retorna la posici¢n vertical del rat¢n.       */
/*************************************************/

int mypos(int modo)
{
	reg.x.ax = 0x3;
	int86(0x33, &reg, &reg);
	return reg.x.dx/modo;
}


/*************************************************/
/* LA FUNCION msituar                            */
/* Situamos el rat¢n en las coordenadas deseadas */
/* Es necesario enviar tres par metros.          */
/*    modo => 1 => modo gr fico.                 */
/*            8 => modo texto.                   */
/*    x => posici¢n horizontal.                  */
/*    y => posici¢n vertical.                    */
/* No retorna ning£n valor.                      */
/*************************************************/

void msituar(int modo, int x, int y)
{
	reg.x.ax = 0x4;
	reg.x.cx = x*modo;
	reg.x.dx = y*modo;
	int86(0x33, &reg, &reg);
}


/*************************************************/
/* LA FUNCION mclick                             */
/* Nos dice si hay alg£n bot¢n presionado.       */
/* No es necesario enviar ning£n par metro.      */
/* Retorna: 0 => ning£n bot¢n presionado.        */
/*          1 => bot¢n izquierdo presionado.     */
/*          2 => bot¢n derecho presionado.       */
/*************************************************/

int mclick(void)
{
	int r = 0;
	reg.x.ax = 0x5;
	reg.x.bx = 0;
	int86(0x33, &reg, &reg);
	if ((reg.x.ax) & 1) r = 1;
	else if ((reg.x.ax>>1) & 1) r = 2;
	return r;
}


/*************************************************/
/* LA FUNCION mlimit                             */
/* Limitamos el espacio de movilidad del rat¢n.  */
/* Es necesario enviar cinco par metros.         */
/*    modo => 1 => modo gr fico.                 */
/*            8 => modo texto.                   */
/*    x1 => l¡mite arriba.                       */
/*    y1 => l¡mite izquierda.                    */
/*    x2 => l¡mite abajo.                        */
/*    y2 => l¡mite derecha.                      */
/* No retorna ning£n valor.                      */
/*************************************************/

void mlimit(int modo, int x1, int y1, int x2, int y2)
{
	reg.x.ax = 0x7;
	reg.x.cx = x1*modo;
	reg.x.dx = x2*modo;
	int86(0x33, &reg, &reg);
	reg.x.ax = 0x8;
	reg.x.cx = y1*modo;
	reg.x.dx = y2*modo;
	int86(0x33, &reg, &reg);
}

