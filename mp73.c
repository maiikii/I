#include<stdio.h>
#include<conio.h>

int main(void)
{
    int n1, d1, n2, d2, x, y, z;
    printf("Enter four positive integers: ");
    scanf("%d %d %d %d", &n1, &d1, &n2, &d2);
    if(d1==d2)
    {
        n1-=n2;
        printf("\nDifference is %d/%d", n1, d1);
    }
    else
    {
        x=d1;
        y=d2;
        while(z>0)
        {
            z=x%y;
            x=y;
            y=z;
        }
        
        printf("\nGCD: %d", x);
        
        if(d1>d2)
            y=d1/x*d2;
        else
            y=d2/x*d1;
        
        printf("\nLCM: %d", y);
    
        
        n1*=y/d1;
        n2*=y/d2;
        
        printf("\nDifference is %d/%d", n1-n2, y);
    }
    
    getch();
    return 0;
}
