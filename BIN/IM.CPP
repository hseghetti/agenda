#include <stdio.h>
#include <conio.h>
#include <iostream.h>


int main(void)
{
   char a[10];
   int i = 0;
   for(int f=0;f<15;f++)
   {
   a[f]=getche();
   }
   char*msg=new char[f+1];
   msg=a;
   msg[f+1]='/n';

  while (msg[i])
  putc(msg[i++], stdprn);
   getch();
   return 0;
}
