#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp;
    char line[80];

    fp = fopen("test.txt", "r");
    if (fp == NULL)
        printf("I couldn't open results.dat for writing.\n");

    while (fgets(line, 80, fp) != NULL){
        printf("Line read: %s\n", line);
    }
    fclose(fp);
    return 0;
}