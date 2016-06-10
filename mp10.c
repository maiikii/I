#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
    int ch, n, ctr, cf=2, temp, p=0;
    do{
	printf("\n\t1. Series\n\t2. Germain Prime\n\t3. Base 8 to Decimal\n\t4. Exit");
	printf("\n\nEnter choice :");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("\n\nSeries.");
				break;
		case 2: printf("\n\nGermain Prime.");
				break;
		case 3: printf("\n\n8 to Decimal.");
				break;
		case 4:	printf("Exit.");
				break;
		default:
				printf("\nInvalid choice.");
				getch();	system("CLS");
				break;
	}
    }while(ch!=4);
	
	if(ch==2)
	{
		system("CLS");
		do{
			printf("Enter a number: ");
			scanf("%d", &n);
		}while(n<1);

		while(cf<n){
			if(n%cf==0){
				printf("Not Germain Prime.");
				break;}
			else{
				cf++;
				if(cf*cf>n){
					p=1;
					break;}
				}
		}
    
		if(p==1)
		{
			temp=2*n+1;
			while(cf<temp)
			{
				if(temp%cf==0)
				{
					printf("Not Germain Prime.");
					break;
				}
				else{
					cf++;
					if(cf*cf>temp)
					{
					printf("Germain Prime.");
					break;
					}
				}
			}
		}
    }
	
    getch();
    return 0;
}
	
	
