#include<stdio.h>

int main()
{
	int n, ctr=0;
	do{
		scanf("%d", &n);
	}while(n<0);
	while(n>4){
		if(n%10==0 || n%5==0)
			ctr++;
		n--;
	}
	printf("\n\n%d", ctr);
	return 0;
}
