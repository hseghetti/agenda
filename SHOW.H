
#ifndef SHOW.H
#define SHOW.H
#include <graphics.h>
#include <dos.h>
#include <stdio.h>


FILE *BMP;
char identificacion[118];
long int CUERPO,TAM_X,TAM_Y,BIT_PIXEL,PIXEL_byte,PALETA,PALETA_TAM;
int mask;

 void leecabecera(void)
  {  /* lee la cabecera */
     fseek(BMP,0,SEEK_SET);
     fread(&identificacion,sizeof(identificacion),1,BMP); /* LEE QUE SEA UN ARCHIVO BMP */
     fseek(BMP,10,SEEK_SET);
     fread(&CUERPO,sizeof(CUERPO),1,BMP); /* LUGAR DONDE EMPIEZA EL CUERPO */
     fseek(BMP,18,SEEK_SET);
     fread(&TAM_X,sizeof(TAM_X),1,BMP); /* TAMA¥O HORIZONTAL */
     fseek(BMP,22,SEEK_SET);
     fread(&TAM_Y,sizeof(TAM_Y),1,BMP);/* TAMA¥O VERTICAL */
     fseek(BMP,28,SEEK_SET);
     fread(&BIT_PIXEL,sizeof(BIT_PIXEL),1,BMP); /* BITS POR PIXEL */
     PIXEL_byte=8/BIT_PIXEL; /* NUMERO DE PIXELES POR BYTE */
     mask=(1<<BIT_PIXEL)-1;
  }

  void escrcolordac16(char color,char r,char g,char b)
  { /* cambia de color paleta llamando directamente a los puertos
       del convertidor anal¢gico digital de la tarjeta de video
       utiliza initgraph y maneja paleta rgb de 16 colores
       b(lue), g(reen), r(ed) */
    char indcol[] = {0,1,2,3,4,5,20,7,56,57,58,59,60,61,62,63};
    outportb(0x3C8,indcol[color]);  /*inicializa el color */
    outportb(0x3C9,r);
    outportb(0x3C9,g);
    outportb(0x3C9,b);
  }

   void leepaleta(void)
   { /* lee del archivo la paleta de colores y la carga en la tarjeta de video */
     typedef struct
     {
       unsigned char b,g,r,a;
     }
     Color;  /* estructura para el color */
     Color col;
     int k;
     PALETA_TAM = 1<<BIT_PIXEL;
     PALETA=CUERPO-4*PALETA_TAM;  /* Principio de la paleta de colores */
     fseek(BMP,PALETA,SEEK_SET);
     for(k=0;k<PALETA_TAM;k++) /* cargando la paleta de colores */
     {
     fread(&col,sizeof(col),1,BMP);
     } /* escrcolordac16(k,(col.r)>>2,(col.g)>>2,(col.b)>>2); */
   }

  void leecuerpo(int x0,int y0)
  { /* funci¢n que regresa el color de los pixeles de acuerdo a sus compo- */
    /* nentes RGB y lo pone en la pantalla */
    int xi=0,n=0,k,Xpal,Ypal;
    long int col[4];
    unsigned char b,b1[4];
    fseek(BMP,CUERPO,SEEK_SET);
    for(Ypal=TAM_Y-1;Ypal>=0;Ypal--)  /* despliega la imagen en el monitor */
    {
      xi=0; n=0;
       for(Xpal=0;Xpal<TAM_X;Xpal++)
	 {
	  if(xi%PIXEL_byte==0) /* desempaca los pixeles empacados en un byte */
	   {
	    fread(&b,sizeof(b),1,BMP);  /* TRAE UN BYTE DEL ARCHIVO */
	    k=PIXEL_byte-1;
	    col[k]=b&mask; /* desempaca cada pixel y lo almacena en un arreglo */ while(k--)   col[k]=(b>>BIT_PIXEL)&mask;  /* regresa el indice del color del siguiente pixel */
	    n++; /* cuenta cuantos bytes ha desempacado */
	   }
	   putpixel(x0+Xpal,y0+Ypal,col[xi++%PIXEL_byte]); /* despliega el siguiente pixel */
	 }
      fread(&b1,1,(4-n%4)%4,BMP);  /*IGNORA BYTES PARA QUEDAR EN MULTIPLOS DE 4 */
    }
   }

int ShowBMP(char *fname,int x0,int y0)
{

 BMP=fopen(fname,"rb");
 if(BMP==NULL) return -1;
 leecabecera();
 leepaleta();
 leecuerpo(x0,y0);
 fclose(BMP);
 return 0;
};
#endif

