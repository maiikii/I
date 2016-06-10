#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int inf, i, c, cmp[50], x, y, ans;
	char inp[50];
	
	do{
		inf=0;
		i=0;
		printf("\n\n\nEnter binary: ");
		gets(inp);	fflush(stdin);
		for(i=0; inp[i]!='\0'; i++){
			if( inp[i]<'0' || inp[i]>'1'){
				inf=1;
				break;
			}
			if(i>32)
				inf=1;
		}
		if(inf){
			system("CLS");
			printf("Invalid input. Retry.");
		}
	}while(inf);
	c=strlen(inp);
	for(i=0; inp[i]!='\0'; i++){
		if(inp[i]=='0')
			cmp[i]=0;
		else
			cmp[i]=1;
	}
	for(x=1, ans=0, c=c-1; c>0; c--){
		y=cmp[c]*x;
		ans+=y;
		x*=2;
	}
	printf("\n\n\n\t%s is %d in decimal.", inp, ans);
	
	getch();
	return 0;
}
