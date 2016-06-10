#include<stdio.h>
#include<conio.h>

int main(void)
{
	int dec, bin=0, rem, rev=0, temp;
	do{
		printf("Enter value in decimal: ");
		scanf("%d", &dec);
	}while(dec<1);
	temp=dec;
	while(temp>0){
		rem=temp%2;
		rev=rev*10+rem;
		temp/=2;
		printf("\n%d\t%d\t%d", rem, rev, temp);
	}
	printf("\n\n");
	temp=rev;
	while(temp>0){
		rem=temp%10;
		bin=bin*10+rem;
		temp/=10;
		printf("\n%d\t%d\t%d", rem, bin, temp);
	}
	printf("\n\n\n%d in decimal is equivalent to %d in binary.", dec, bin);
	getch();
	return 0;
}
