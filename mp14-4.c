#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
	int cmp[50], x, y, ans, i, c, inf;
	char inp[50], lnf, otp[50];

	do{
		inf=0;
		printf("\n\n\nEnter binary: ");
		gets(inp);	fflush(stdin);
		for(i=0; inp[i]!='\0'; i++){
			if( inp[i]<'0' || inp[i]>'1'){
				inf=1;
				break;
			}
		}
		if(inf){
			system("CLS");
			printf("Invalid input. Retry.");
		}
	}while(inf);
	for(i=0; inp[i]!='\0'; i++){
		if(inp[i]=='0')
			cmp[i]=0;
		else
			cmp[i]=1;
	}
	for(c=0; inp[c]!='\0'; c++);
	if(c%3==0)
		ans=c/3-1;
	else
		ans=c/3;
	for(c=c-1; c>=0; c--, ans--){
		for(i=0, x=1, y=0; i<3 && c>=0; i++, c--){
			if(cmp[c]==1)
				y=y+cmp[c]*x;
			x*=2;
		}
		otp[ans]=y+48;
		c++;
	}
	otp[ans]='\0';
	printf("\n\n\t%s is %s in octal.", inp, otp);
	getch();
	return 0;
}
