#include<stdio.h>
#include<conio.h>

void main(void)
{
     int x, y;
     printf("Enter two numbers: ");
     scanf("%d %d", &x, &y);
     for(y=y-1;y>0; y--)
         x+=x;
     printf("%d", x);
     getch();
}
