#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void BintoOct(int[], int[]);

int main(void)
{
	int ch, cmp[60], i, c, x, y, z, inf, ans, ngf;
	char inp[60], lch, otp[60];
	
	while(ch!=6){
		do{
			inf=0;
			printf("\n\n\n\tMENU\n\n\t1 - Binary to Decimal\n\t2 - Octal to Decimal\n\t3 - Hexadecimal to Decimal\n\t4 - Binary to Octal\n\t5 - Binary to Hexadecimal\n\t6 - Exit");
			printf("\n\n\tEnter choice: ");
			scanf("%d", &ch);	fflush(stdin);
			if(ch<0 || ch>6){
				system("CLS");
				printf("\tInvalid input. Retry");
				inf=1;
	 		}
		}while(inf);
		if(ch==6)
			exit(0);
		printf("\n\n\n\n\n");
		system("PAUSE");
		system("CLS");
		
		if(ch==1 || ch==4 || ch==5){
			do{
				inf=0;
				ngf=0;
				printf("\n\n\nEnter binary: ");
				gets(inp);	fflush(stdin);
				for(i=0; inp[i]!='\0'; i++){
					if( inp[i]<'0' || inp[i]>'1'){
						inf=1;
						break;
					}
				}
				if(ch==1 && i>32)
					inf=1;
				if(inf){
					system("CLS");
					printf("Invalid input. Retry.");
				}
			}while(inf);
			if(ch!=1){
				for(i=0; inp[i]!='\0'; i++){
					if(inp[i]=='0')
						cmp[i]=0;
					else
						cmp[i]=1;
				}
			}
			for(c=0; inp[c]!='\0'; c++);
		}
		
		if(ch==1){
			if(inp[0]=='1')
				ngf=1;
			for(i=0; inp[i]!='\0'; i++){
				if(inp[i]=='0')
					if(ngf)
						cmp[i]=1;
					else
						cmp[i]=0;
				else
					if(ngf)
						cmp[i]=0;
					else
						cmp[i]=1;
				if(ngf && i==0)
					cmp[i]=1;
			}
			for(x=1, ans=0, c=c-1; c>0; c--){
				y=cmp[c]*x;
				ans+=y;
				x*=2;
			}
			if(ngf)
				ans*=-1;
			printf("\n\n\n\t%s is %d in decimal.", inp, ans);
		}
		
		if(ch==2){
			do{
				inf=0;
				printf("\n\n\nEnter octal: ");
				gets(inp);	fflush(stdin);
				for(i=0; inp[i]!='\0'; i++){
					if( inp[i]<'0' || inp[i]>'7'){
						inf=1;
						break;
					}
				}
				if(inf){
					system("CLS");
					printf("Invalid input. Retry.");
				}
			}while(inf);
			for(i=0; inp[i]!='\0'; i++)
				for(lch='0'; lch<'8'; lch++)
					if(inp[i]==lch)
					 	cmp[i]=inp[i]-48;
			for(c=0; inp[c]!='\0'; c++);
			for(x=1, ans=0, c=c-1; c>=0; c--){
				y=cmp[c]*x;
				ans+=y;
				x*=8;
			}
			printf("\n\n\n\t%s is %d in decimal.", inp, ans);
		}
		
		if(ch==3){
			do{
				inf=0;
				printf("\n\n\nEnter hexadecimal: ");
				gets(inp);	fflush(stdin);
				for(i=0; inp[i]!='\0'; i++){
					if( (inp[i]<'0' || inp[i]>'9') && (inp[i]<'a' || inp[i]>'f') && (inp[i]<'A' || inp[i]>'F') ){
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
				for(lch='0'; lch<58 ; lch++)
					if(inp[i]==lch)
					 	cmp[i]=inp[i]-48;
				for(lch='A'; lch<'G'; lch++)
					if(inp[i]==lch)
						cmp[i]=inp[i]-55;
					else if(inp[i]==lch+32)
						cmp[i]=inp[i]-87;
			}
			for(c=0; inp[c]!='\0'; c++);
			for(x=1, ans=0, c=c-1; c>=0; c--){
				y=cmp[c]*x;
				ans+=y;
				x*=16;
			}
			printf("\n\n\n\t%s is %d in decimal.", inp, ans);
		}
		
		if(ch==4)
			BintoOct(inp, cmp);
		
		if(ch==5){
			if(c%4==0)
				ans=c/4-1;
			else
				ans=c/4;
			for(c=c-1; c>=0; c--, ans--){
				for(i=0, x=1, y=0; i<4 && c>=0; i++, c--){
					if(cmp[c]==1)
						y=y+cmp[c]*x;
					x*=2;
				}
				if(y<10)
					otp[ans]=y+48;
				else{
					for(z=10, lch='A'; z<16; z++, lch++)
					 if(y==z)
					 	 otp[ans]=lch;
				 }
				c++;
			}
			printf("\n\n\n\t%s is %s in hexadecimal.", inp, otp);
		}
		
		printf("\n\n\n\n\n");
		system("PAUSE");
		system("CLS");
		
	}	
	getch();
	return 0;
}

void BintoOct(int inp[], int cmp[])
{
 	 int x, y, ans, i, c;
	 char otp[50];
	 
	 c=strlen(inp)-1;
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
}
