#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
	int ch;
	do{
		int n, ctr=0, x=0, y=0, z=1, temp, pf=1, gpf=1;
		
		do{
			printf("\nMENU\n\n\n  1. Series\n  2. Germain Prime\n  3. Base 8 to Decimal\n  4. Exit");
			printf("\n\n\n\nEnter choice : ");
			scanf("%d", &ch);
			switch(ch)
			{
				case 1: printf("\n\n\nIt will display the first n elements of a series.");
						break;
				case 2: printf("\n\n\nIt will determine if a number is Germain Prime or not.");
						break;
				case 3: printf("\n\n\nIt will convert a number in base 8 (octal) to base 10 (decimal).");
						break;
				case 4:	exit(0);
						break;
				default: system("CLS"); printf("Invalid choice. Retry.\n\n");
			}
		}while(ch>4 || ch==0);
		
		if(ch!=4){
			printf("\n\n\n\n\n");
			system("PAUSE");
			system("CLS");
		}
		else
			break;

		if(ch==1)
		{
			do{
				printf("\n\n\nEnter a number: ");
				scanf("%d", &n);
				if(n<1){
					system("CLS");
					printf("Invalid input. Retry.");
				}				
			}while(n<1);
			printf("\n\nFirst %d elements of the series:", n);
			printf("\n\n   ");
			do{
				if(z%3==0){
					pf=0;
					z=1;
				}
				if(gpf%3==0){
					pf=1;
					gpf=1;
				}
				if(pf){
					x+=4;
					printf(" %d ", x);
					z++;
				}
				else{
					y+=7;
					printf(" %d ", y);
					gpf++;
				}
				ctr++;
			}while(ctr<n);
			
		}

		if(ch==2)
		{
			do{
				printf("\n\n\nEnter a number: ");
				scanf("%d", &n);
				if(n<1){
					system("CLS");
					printf("Invalid input. Retry.");
				}				
			}while(n<1);
			if(n==1 || n==2 || n==3){
				printf("\n\n\t%d is a Germain Prime.", n);
			}
			else{
				temp=n;
				do{
					x=2;
					while(x*x<=temp)
					{
						if(temp%x==0){
							if(ctr)
								printf("\n\n\t%d is not a Germain Prime although it is prime.", n);
							else
								printf("\n\n\t%d is not a Germain Prime.", n);
							ctr=0;
							break;
						}
						if((x+1)*(x+1)>temp){
							ctr++;
							break;
						}
						x++;
					}
					temp=temp*2+1;
					if(ctr==2){
						printf("\n\n\t%d is a Germain Prime.", n);
						pf=0;
					}
				}while(pf && ctr);
			}
		}
		
		if(ch==3)
		{
			do{
				printf("\n\n\nEnter a number: ");
				scanf("%d", &n);
				temp=n;
				ctr=0;
				while(temp>0){
					z=temp%10;
					if(z>7){
						ctr=1;
						break;
					}
					temp/=10;
				}
				if(n<1 || ctr==1){
					system("CLS");
					printf("Invalid input. Retry.");
				}				
			}while(n<1 || ctr==1);
			
			temp=n;
			while(temp>0){
				x=temp%10;
				y+=x*pf;
				pf*=8;
				temp/=10;
			}
			printf("\n\n\t%d in octal is equivalent to %d in decimal.", n, y);
			
		}
		
		printf("\n\n\n\n\n");
		system("PAUSE");
		system("CLS");
	}while(ch<4);
	
	getch();
	return 0;
}
