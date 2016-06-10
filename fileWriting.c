#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp;
    int i, i3;

    fp = fopen("results.dat", "w"); //the 'w' here means write.
    if (fp == NULL)                 //try changing this 'a'
        printf("I couldn't open results.dat for writing.\n");

    for (i=0; i<=10; ++i)
        fprintf(fp, "%d %d\n", i, i*i*i);

    fclose(fp);
    return 0;
}