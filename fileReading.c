#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp;
    int x, y, c;

    fp = fopen("results.dat", "r");
    if (fp == NULL)
        printf("I couldn't open results.dat for writing.\n");

    while( fscanf(fp,"%d %d",&x,&y)==2)
        printf("x: %d y: %d\n", x, y);

    printf("\n");
    fclose(fp);
    return 0;
}