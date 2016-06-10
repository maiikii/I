#include<stdio.h>
#include<conio.h>

int main(void)
{
    int km, ctr, cm=0;
    do{
		printf("Enter measurement in kilometers: ");
		scanf("%d", &km);
	}while(km<1);

	ctr=km;
	
	while(ctr>0){
		cm+=100000;
		ctr--;
	}
	
	printf("\n\n%d km is equivalent to %d cm.", km, cm);
	getch();
	return 0;
}
