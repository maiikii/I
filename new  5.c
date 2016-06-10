#include<stdio.h>
#include<conio.h>

int main(void)
{
	int oct, rem, temp, x, ans=0;
	printf("Enter octal number: ");
	scanf("%d", &oct);
	temp=oct;
	do{
		rem=temp%8;
		temp=temp/8;
		ans=ans*8+rem;
	}while(temp>0);
	
	
	
	
	
	