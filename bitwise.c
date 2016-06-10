#include<stdio.h>
#include<conio.h>

void main(void)
{
     int x, y, z=0, i=0;
     printf("Enter two numbers: ");
     scanf("%d %d", &x, &y);
     while(x>0){
         z=z + (y<<i);
         i++;
         x=(x<<1);
     } 
     //z = (x << 0) + (y << 1);
     printf("%d", z);
     getch();
}
