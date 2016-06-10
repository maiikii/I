#include<stdio.h>
#include<conio.h>

int main(void)
{
	int n, sum=0, x=4;
	do{
	printf("Enter a number: ");
	scanf("%d", &n);
	}while(n<1);
	
	printf("\nMultiples of 4 or 6 less than %d: ", n);
	
	while(x<n){
		if( (x%4==0) || (x%6==0) ){
			sum+=x;
			printf("%d  ",x);
        }
		x++;
	}
	
	printf("\n\nSum is %d.", sum);
	getch();
	return 0;
}
