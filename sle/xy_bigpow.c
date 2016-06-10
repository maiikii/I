#include<stdio.h>

int main()
{
	int x, y, ans=1, c;
	scanf("%d%d", &x, &y);
	if(x<y)
		ans=0;
	else
		do{
			ans*=y;
			printf("%d ", ans);
		}while(ans<=x);
	printf("\n\n%d\n\n\n\n\n", ans/y);
}
