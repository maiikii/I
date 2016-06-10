#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    char ch1 = 4, ch2 = 3, ch3 = 2, ch4 = 5, ch5 = 6;
    system("color 0c");
    printf("ch1 is: %c\n",ch1);
    printf("ch2 is: %c\n",ch2);
    printf("ch3 is: %c\n",ch3);
    printf("ch4 is: %c\n",ch4);
    printf("ch5 is: %c\n",ch5);
    printf("Press any key to continue. Char!\n");
    getch();
    system("cls");
    system("color 70");
    ch1 = 48;
    while(ch1 <= 57){
        printf("ch1 is: %c\n",ch1);
        ch1 = ch1 + 1;
    }
    printf("Press any key to continue. Char!\n");
    getch();
    system("cls");
    system("color 9A");
    ch1 = 65;
    while(ch1<=90){
        printf("%c ",ch1);
        ch1 = ch1 + 1;
    }
    printf("\n");
    printf("Press any key to continue. Char!\n");
    getch();
    system("cls");
    system("color b6");
    ch1 = 97;
    while(ch1<=122){
        printf("%c ",ch1);
        ch1 = ch1 + 1;
    }
    printf("\n");
    printf("Press any key to continue. Char!\n");
    getch();
    system("cls");
    system("color dc");
    ch1 = 7;
    printf("ch1 is: %c\n",ch1);
    printf("Press any key to continue. Char!\n");
    getch();
    system("cls");
    system("color 40");
    int i = 0;
    while(i<=255){
        ch1 = i;
        printf("%c ",ch1);
        i++;
    }
    printf("\n");
    getch();
    return 0;
}
