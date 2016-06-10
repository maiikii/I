#include<stdio.h>

typedef struct{
	int nume, deno;
}fraction;

fraction extract(char[]);

int main(void){
	fraction x;
	char st[10];
	printf("Enter fraction: ");
	gets(st);
	x=extract(st);
	printf("\n\n%d / %d", x.nume, x.deno);
	return 0;
}

fraction extract(char input[]){
	int i, sc=0;
	fraction ret;
	ret.nume=0;	ret.deno=0;
	for(i=0; input[i]!=0; i++){
		if(input[i]=='/')
			sc++;
		if(input[i]>'9' || input[i]<'0'){
			if(input[i]!='/' || sc>1 || input[0]=='/'){
				printf("Invalid input.\n");
				return ret;
			}
		}
	}
	if(sc){
		for(i=0; input[i]!='/'; i++)
			ret.nume=ret.nume*10+(input[i]-'0');
		for(++i; input[i]!=0; i++)
			ret.deno=ret.deno*10+(input[i]-'0');
	}
	else{
		for(i=0; input[i]!=0; i++)
			ret.nume=ret.nume*10+(input[i]-'0');
		ret.deno=1;
	}
	return ret;
}
