#include<stdio.h>

void toOct(int);

int main(void)
{
	toOct(53);
	return 0;
}

void toOct(int n)
{
	if(n>0){
		toOct(n/8);
		printf("%d", n%8);
	}
}
