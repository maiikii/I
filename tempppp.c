#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
 	int i, c, n1c, n2c, ncs, x;
 	char t1[50], t2[50];
 	gets(t1);
 	printf("\n");
 	gets(t2);
 	for(i=0, n1c=0; t1[i]!='\0'; i++)
	{
		for(c=0; t2[c]!='\0'; c++)
		{
			if(isupper(t1[i]))
				t1[i]+=32;
			if(isupper(t2[c]))
				t2[c]+=32;
			if(t1[i]==t2[c]){
				if(t2[c]!=' '){
					n1c++;
					printf("\n%c %c ", t1[i], t2[c]);
					printf("%d", n1c);
				}
			}
		}
	}
	for(i=0, n2c=0; t2[i]!='\0'; i++)
	{
		for(c=0; t1[c]!='\0'; c++)
		{
			if(isupper(t2[i]))
				t2[i]+=32;
			if(isupper(t1[c]))
				t1[c]+=32;
			if(t2[i]==t1[c]){
				if(t1[c]!=' '){
					n2c++;
					printf("\n%c %c ", t2[i], t1[c]);
					printf("%d", n2c);
				}
			}
		}
	}

	getch();
	return 0;
}
