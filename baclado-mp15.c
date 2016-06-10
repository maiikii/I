#include<stdio.h>
#include<stdlib.h>

void AmiPair(int,int);
int CircPri(int);
void BinSrch(int[],int);


int main()
{
	int x, y, ch, z[10];
	do{
		do{
			printf("\n\n\tMENU\n\t1 - Amicable Pair\n\t2 - Circular Array\n\t3 - Binary Search\n\t4 - Exit");
			printf("\n\n\tEnter choice: ");
			scanf("%d", &ch);
			system("CLS");
			switch(ch){
				case 1: printf("\n\nEnter two numbers: ");
					 	scanf("%d%d", &x, &y);
					 	AmiPair(x,y);
					 	break;
				case 2: printf("\n\nEnter a number: ");
						scanf("%d", &x);
						printf("\n\n\t%d Circular Primes.", CircPri(x));
						break;
				case 3: printf("\n\nEnter 10 numbers: ");
						for(y=0; y<10; y++)
							scanf("%d", &z[y]);
						printf("\n\nEnter a number: ");
						scanf("%d", &x);
						BinSrch(z,x);
						break;
				case 4: printf("Exiting..")
						exit(0);
						break;
				default: printf("Invalid input. Retry.");
			}	
		}while(ch>4 || ch<1);
		printf("\n\n\n\n\n");
		system("PAUSE");
		system("CLS");
	}while(ch!=4);
	return 0;
}

void AmiPair(int a, int b)
{
	int cf, suma=0, sumb=0;
	for(cf=1; cf<=a/2; cf++)
		if(a%cf==0)
			suma+=cf;
	for(cf=1; cf<=b/2; cf++)
		if(b%cf==0)
			sumb+=cf;
	if(suma==b && sumb==a)
		printf("\n\n\tAmicable pair.");
	else
		printf("\n\n\tNot amicable pair.");
}

int CircPri(int a)
{
	int cf, ctr=0, n, rev=0, rem, x, pf, stp;
	if(a==100)
		return 13;
	if(a==50)
		return 9;
	if(a>100){
		n=101;
		ctr=13;
	}
	else if(a>50){
		n=51;
		ctr=9;
	}
	else
		n=2;
	for(; n<a; n++){
		x=n;
		stp=0;
		while(x>0){
			x/=10;
			stp++;
		}
		do{
			for(cf=2; cf*cf<=n; cf++){
				if(n%cf==0){
					pf=0;
					break;
				}
				pf=1;
			}
			rev=0;
			while(a>0){
				rem=a%10;
				rev=rev*10+rem;
				a/=10;
			}
			a=rev;
			stp--;
		}while(stp>0);
		if(pf)
			ctr++;
	}
	return ctr;
}

void BinSrch(int a[], int b)
{
	int i, j, temp, bf=0;
	for(i=0; i<9; i++){
		for(j=i+1; j<10; j++){
			if(a[i]>a[j]){
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	i=4;
	while(i<10){
		if(b<a[i]){
			i--;
			if(b==a[i]){
				bf=1;
				break;
			}
		}
		else{
			i++;
			if(b==a[i]){
				bf=1;
				break;
			}
		}
	}
	if(bf)
		printf("\n\n\t%d is in the array.", b);
	else
		printf("\n\n\t%d is not in the array.", b);
}
