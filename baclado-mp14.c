#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void)
{
	int ch, cmp[60], i, c, x, y, z, inf, ans, oh;
	char inp[60], lch, otp[60];
	
	while(ch!=6){
		do{
			inf=0;
			printf("\n\n\n\tMENU\n\n\t1 - Binary to Decimal\n\t2 - Octal to Decimal\n\t3 - Hexadecimal to Decimal\n\t4 - Binary to Octal\n\t5 - Binary to Hexadecimal\n\t6 - Exit");
			printf("\n\n\tEnter choice: ");
			scanf("%d", &ch);	fflush(stdin);
			if(ch<1 || ch>6){
				system("CLS");
				printf("\tInvalid input. Retry");
				inf=1;
	 		}
		}while(inf);
		if(ch==6)
			exit(0);
		printf("\n\n\n\n\n\t");
		system("PAUSE");
		system("CLS");
		
		if(ch==1 || ch==4 || ch==5){
			do{
				inf=0;
				printf("\n\n\n\n\tEnter binary: ");
				gets(inp);	fflush(stdin);
				for(i=0; inp[i]!='\0'; i++){
					if( inp[i]<'0' || inp[i]>'1'){
						inf=1;
						break;
					}
				}
				if(inf){
					system("CLS");
					printf("\tInvalid input. Retry.");
				}
			}while(inf);
			for(i=0; inp[i]!='\0'; i++){
				if(inp[i]=='0')
					cmp[i]=0;
				else
					cmp[i]=1;
				}
		}
		if(ch==1){
			if(i<32){
				for(x=1, ans=0, c=i-1; c>=0; c--){
					y=cmp[c]*x;
	   				ans+=y;
					x*=2;
				}
			}
			printf("\n\n\n\t%s is %d in decimal.", inp, ans);
		}
		
		if(ch==2){
			do{
				inf=0;
				printf("\n\n\n\n\tEnter octal: ");
				gets(inp);	fflush(stdin);
				for(i=0; inp[i]!='\0'; i++){
					if( inp[i]<'0' || inp[i]>'7'){
						inf=1;
						break;
					}
				}
				if(inf){
					system("CLS");
					printf("\tInvalid input. Retry.");
				}
			}while(inf);
			for(i=0; inp[i]!='\0'; i++)
				 	cmp[i]=inp[i]-48;
			for(x=1, ans=0, c=i-1; c>=0; c--){
				y=cmp[c]*x;
				ans+=y;
				x*=8;
			}
			printf("\n\n\n\t%s is %d in decimal.", inp, ans);
		}
		
		if(ch==3){
			do{
				inf=0;
				printf("\n\n\n\n\tEnter hexadecimal: ");
				gets(inp);	fflush(stdin);
				for(i=0; inp[i]!='\0'; i++){
					if( (inp[i]<'0' || inp[i]>'9') && (inp[i]<'a' || inp[i]>'f') && (inp[i]<'A' || inp[i]>'F') ){
						inf=1;
						break;
					}
				}
				if(inf){
					system("CLS");
					printf("\tInvalid input. Retry.");
				}
			}while(inf);
			for(i=0; inp[i]!='\0'; i++){
				if(inp[i]>='a')
				 	cmp[i]=inp[i]-87;
				else if(inp[i]>='A')
					cmp[i]=inp[i]-55;
				else
					cmp[i]=inp[i]-48;
			}
			for(x=1, ans=0, c=i-1; c>=0; c--){
				y=cmp[c]*x;
				ans+=y;
				x*=16;
			}
			printf("\n\n\n\t%s is %d in decimal.", inp, ans);
		}
		
		if(ch==4){
			if(i%3==0)
				ans=i/3-1;
			else
				ans=i/3;
			otp[ans+1]=0;
			for(c=i-1; c>=0; c--, ans--){
				for(i=0, x=1, y=0; i<3 && c>=0; i++, c--){
					if(cmp[c]==1)
						y=y+cmp[c]*x;
					x*=2;
				}
				otp[ans]=y+48;
				c++;
			}
			printf("\n\n\n\t%s is %s in octal.", inp, otp);
		}
		
		if(ch==5){
			if(i%4==0)
				ans=i/4-1;
			else
				ans=i/4;
			otp[ans+1]=0;
			for(c=i-1; c>=0; c--, ans--){
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
		
		printf("\n\n\n\n\n\n\t");
		system("PAUSE");
		system("CLS");
		
	}	
	getch();
	return 0;
}
