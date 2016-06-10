#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
    srand((unsigned int)time(NULL));
    int r;
    //do{
       r=rand()%3+1;
    //}while(r>101);
    printf("%d", r);
    getch();
    return 0;
}
