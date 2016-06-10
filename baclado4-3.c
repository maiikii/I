#include<stdio.h>
#include<conio.h>

int main(void)
{
	int a=1, b=1, c, sum, ctr=0;
	
	printf("\nEven elements of the Fibonacci Sequence less than 40 million:");
	
	while(c<40000000 && ctr<12){
		c=a+b;
		a=b;
		b=c;
		
		if(c%2==0){
			sum+=c;
			printf("\n%d", c);
			ctr++;
        }
	}
	
	printf("\n\nSum is %d.", sum);
	getch();
	return 0;
}
