#include <stdio.h>
#include <conio.h>

int main()
{
	int x = 2147483647;
	if(x=5)
		printf("x is %d.\n",x);
	if(x=-3)
		printf("x is %d.\n",x);
	if(x=0)
		printf("x is %d.\n",x);
	if(x=2147483649)
		printf("x is %d.\n",x);
	if(4)
		printf("Huh?\n");
	if(97)
		printf("Again?\n");
	if(-107)
		printf("What now?\n");
	if(-2)
		printf("Unswa?!\n");
	if(0)
		printf("Pffft!\n");
    getch();
    return 0;
}
