#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp;
    char ch;

    fp = fopen("test.txt", "r");
    if (fp == NULL)
        printf("I couldn't open results.dat for writing.\n");

    while ((ch=fgetc(fp))!=EOF){
        printf("ch: %c\n", ch);
    }
    fclose(fp);
    return 0;
}