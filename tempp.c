#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char t1[50], t2[50];
	int i, c=0, ssf, stp=1;
	gets(t1);
	printf("\n");
	gets(t2);
		for(i=0; t2[i]!='\0'; i++){
			while(t1[c]!='\0'){
				 printf("\n%c %c ", t2[i], t1[c]);
				if(isupper(t2[i]))
					t2[i]+=32;
				if(isupper(t1[c]))
					t1[c]+=32;
				if(t2[i]==t1[c]){
					ssf=1;
					printf("%d", ssf);
					break;
				}
				else{
					ssf=0;
					printf("%d", ssf);
				}
				if(ssf){
					if(t2[i+1]!=t1[c+1]){
						ssf=0; stp=1;
						printf("\n%c ", t2[i+1]);
						printf("%c %d ", t1[c+1], ssf);
					}
				}
				c++;
			}
			if(stp && t2[i]!='\0')
				if(t2[i+1]!=t1[c+1]){
					ssf=0;
					break;
				}
		}
	
	if(stp)
		printf("\n\nYes.");
	else
		printf("\n\nNo.");
	
	getch();
	return 0;
}
