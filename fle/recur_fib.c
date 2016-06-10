#include<stdio.h>

int fib(int);

int main()
{
	printf("%d \n", fib(8));
	return 0;
}

int fib(int n)
{
	if(n==1||n==2){
		printf("Base case Babeh!\n");
		return 1;
	}
	else{
		printf("%d\n", n);
		return fib(n-1)+fib(n-2);
	}
}
