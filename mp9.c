#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
    srand((unsigned int)time(NULL));
    
	int r, num, ctr=5;
    
	do{
       r=rand();
    }while(r>101);
    
	do{
		printf("\nEnter number: ");
		scanf("%d", &num);
		
		if(num==r)
		{
			printf("\n\nCongratulations!");
			break;
		}
		else if(num>r)
			printf("\nLower!");	
		else
			printf("\nHigher!");
		ctr--;
		printf("\nTries left: %d", ctr);
		getch();
		system("CLS");
		
	}while(ctr>0);
	
	printf("The magic number is %d", r);
	
    getch();
    return 0;
}
