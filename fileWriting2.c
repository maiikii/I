#include <stdio.h>
#include <stdlib.h>

int main(void){
   FILE *fp;
   int i, i3;

   fp = fopen("writing.txt", "w"); //the 'w' here means write.
   if (fp == NULL)                 //try changing this 'a'
       printf("I couldn't open results.dat for writing.\n");

   fprintf(fp,"Hello World!\n");
   fprintf(fp,"Writing to files is the same as writing to the console!\n");
   fprintf(fp,"printf vs fprintf?? ");
   fprintf(fp,"see..same..\n");

   fclose(fp);
   return 0;
}