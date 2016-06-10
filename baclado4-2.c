#include<stdio.h>
#include<conio.h>

int main(void)
{
	int x, y, val=1, ctr;
	printf("Enter x: ");
	scanf("%d", &x);
	printf("Enter y: ");
	scanf("%d", &y);
	ctr=y;
	
	while(ctr>0){
		val*=x;
		ctr-=1;
	}
	
	printf("\n%d raised to the power of %d is equals to %d.", x, y, val);
	getch();
	return 0;
}
