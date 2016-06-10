#include<stdio.h>

int main()
{
	int n, rev=0, rem, temp;
	do{
		scanf("%d", &n);
	}while(n<0);
	temp=n;
	while(temp>0){
		rem=temp%10;
		rev=rev*10+rem;
		temp/=10;
	}
	if(n==rev)
		printf("\n\nSame.");
	else
		printf("\n\nNot same.");
	return 0;
}
