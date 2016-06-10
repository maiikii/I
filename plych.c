#include<stdio.h>
#include<conio.h>

int main(void)
{
    char cc, p3f=1, ctr=3;
    do{
       printf("How many players?\n\tA = 2 players\tB = 3 players\n\nChoice: ");
       scanf("%c", &cc);
       if(cc=='A' || cc=='a'){
           p3f=0; ctr=2;      break;
       }
    }while( (cc!='A' || cc!='a') && (cc!='B' || cc!='b') );
    printf("\n\n\n\nChoice=%c\tFlag=%d\tCounter=%d", cc, p3f, ctr);
    getch();
    return 0;
}
