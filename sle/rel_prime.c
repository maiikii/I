#include<stdio.h>

int main()
{
	int x, y, cf=2, stp;
	scanf("%d%d", &x, &y);
	if(x%y==0 || y%x==0)
		printf("\n\nNot relatively prime\n\n\n.");
	else{
		if(x>y)
			stp=x;
		else
			stp=y;
		while(cf<stp){
			if(x%cf==0 && y%cf==0)
				break;
			cf++;
		}
		if(cf==stp)
			printf("\n\nRelatively prime\n\n\n.");
		else
			printf("\n\nNot relatively prime\n\n\n.");
	}
	return 0;
}
