#include<stdio.h>

int main()
{
	int n, day=0, hr=0, min=0;
	scanf("%d", &n);
	printf("In %d seconds, there are ", n);
	while(n>=86400){
		day++;
		n-=86400;
	}
	printf("%d days ", day);
	while(n>=3600){
		hr++;
		n-=3600;
	}
	printf("%d hours ", hr);
	while(n>=60){
		hr++;
		n-=60;
	}
	printf("%d mins and ", min);
	printf("%d secs.", n);
	
}
