#include<stdio.h>
#include<conio.h>

int sumdig(int);
void plndrm(int n);

int main(void)
{
	int x;
	x=sumdig(2468);
	printf("%d\n", x);
	plndrm(24680);
	return 0;
}

int sumdig(int n)
{
	if(n>0)
		return n%10 + sumdig(n/10)%10;
	else
		return 0;
}

void plndrm(int n)
{
	if(n>0){
		printf("%d", n%10);
		plndrm(n/10);
	}
}
