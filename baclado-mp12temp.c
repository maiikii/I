#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int ch, i, c, pf, x;
	char arr[100];
	do{
		pf=1;
		do{
			printf("\n\n\n\tMENU\n\n\t1 - Length\n\t2 - Palindrome\n\t3 - Count Words\n\t4 - Exit");
			printf("\n\n\n\n\nEnter choice: ");
			scanf("%d", &ch);	fflush(stdin);
			
			switch(ch){
				case 1: printf("\n\n\nIt will determine the length of the string.\n\n\n\n\n");
						break;
				case 2: printf("\n\n\nIt will determine if the string is equivalent to its reverse.\n\n\n\n\n");
						break;
				case 3: printf("\n\n\nIt will determine how many words in the string.\n\n\n\n\n");
						break;
				case 4: exit(0);
						break;
				default: system("CLS"); printf("Invalid choice. Retry.");
			}
		}while(ch<0 || ch>4);
		
		system("PAUSE");
		system("CLS");
		
		printf("\n\nEnter string: ");
		gets(arr);	fflush(stdin);
		
		if(ch==1){
			for(i=0; arr[i]!='\0'; i++);
			printf("\n\n\nThe string has the length of %d.\n\n\n\n\n", i);
		}
		
		if(ch==2){
			for(c=0; arr[c]!='\0'; c++);
			x=c/2;
			for(i=0,c-=1; i<=x; i++, c--){
				if(!(arr[i]==arr[c])){
					pf=0;
					break;
				}
			}
			if(pf)
				printf("\n\n\nThe string is a Palindrome.\n\n\n\n\n");
			else
				printf("\n\n\nThe string is not a Palindrome.\n\n\n\n\n");
		}
		
		if(ch==3){
			for(i=0, c=0; arr[i]!='\0'; i++){
				if(arr[i]==' '){
					for(x=i; arr[x]==' '; x++);
					if(arr[x]!=' ')
						c++;
					i=x;
				}
			}
			if(arr[i-1]!=' ' && c>1)
				c++;
			printf("\n\n\nThe string has %d word/s.\n\n\n\n\n", c);
		}
		
		system("PAUSE");
		system("CLS");
	
	}while(ch!=4);
	
	getch();
	return 0;
}
