#include<stdio.h>

int sumDig(int);
int plndrm(int);

int main(void){
	int x=sumDig(1234), y=plndrm(12321);
	if(y)
		printf("Pal.\n");
	else
		printf("Not Pal.\n");
	return 0;
}

int sumDig(int n){
	if(n>0)
		return n%10 + sumDig(n/10);
	else
		return 0;
}

int plndrm(int n){
	int x=n, y=1;
	if(n>0){
		while(x>0){
			x=x/10;
			if(x<10)
				break;
			y=y*10;
		}
		if(n%10==x)
			return plndrm((n%y)%10);
		else
			return 0;
	}
	return 1;
}
