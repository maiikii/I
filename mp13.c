#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int ch, i, n1c, n2c, c, ncs, ssf, stp;
	char str[100], nm1[50], nm2[50], chk, t1[50], t2[50];
	do{
		do{
		printf("\n\tMENU\n\n\t1 - Flames\n\t2 - Substring\n\t3 - Exit");
		printf("\n\nEnter choice: ");
		scanf("%d", &ch);	fflush(stdin);
		switch(ch){
			case 1: printf("\n\n\nGive two names and test their love fortune.");
					break;
			case 2: printf("\n\n\nGive two strings and it'll check if the second one is a substring of the first.");
					break;
			case 3: exit(0);
					break;
			default: system("CLS");
					 printf("Invalid input. Retry");
					 break;
		}
		}while(ch<1 || ch>3);
		
		printf("\n\n\n\n\n");
		system("PAUSE");
		system("CLS");
		
		if(ch==1){
			printf("\nEnter first name: ");		gets(nm1);	fflush(stdin);
			printf("\nEnter second name: ");	gets(nm2);	fflush(stdin);
			strcpy(t1,nm1);		strcpy(t2, nm2);
			for(i=0, n1c=0; t1[i]!='\0'; i++){
				for(c=0; t2[c]!='\0'; c++){
					if(isupper(t1[i]))
						t1[i]+=32;
					if(isupper(t2[c]))
						t2[c]+=32;
					if(t1[i]==t2[c]){
						if(t2[c]!=' ')
							n1c+=1;
							t2[c]='0';
					}
				}
			}
			strcpy(t2, nm2);
			for(i=0, n2c=0; t2[i]!='\0'; i++){
				for(c=0; t1[c]!='\0'; c++){
					if(isupper(t2[i]))
						tolower(t2[i]);
					if(isupper(t2[c]))
						tolower(t2[c]);
					if(t2[i]==t1[c]){
						if(t1[c]!=' ')
							n2c+=1;
							t1[c]='0';
					}
				}
			}
			printf("\n\n%d %d", n1c, n2c);
			ncs=n1c+n2c;	n1c%=6;		n2c%=6;		ncs%=6;
			printf("\n\n\n%s wants ", nm1);
			switch(n1c){
				case 0: printf("to be Friends.");	
						break;
				case 1: printf("to be Lovers.");
						break;
				case 2: printf("wants Acceptance of Proposal.");
						break;
				case 3: printf("wants Marriage.");
						break;
				case 4: printf("wants Engagement.");
						break;
				default: printf("wants to be Sweethearts.");
						break;
			}
			printf("\n\n\n%s wants ", nm2);
			switch(n2c){
				case 0: printf("to be Friends.");	
						break;
				case 1: printf("to be Lovers.");
						break;
				case 2: printf("Acceptance of Proposal.");
						break;
				case 3: printf("Marriage.");
						break;
				case 4: printf("Engagement.");
						break;
				default: printf("to be Sweethearts.");
						break;
			}
			printf("\n\n\n%s and %s end up ", nm1, nm2);
			switch(n2c){
				case 0: printf("as Friends.");	
						break;
				case 1: printf("as Lovers.");
						break;
				case 2: printf("with Acceptance of Proposal.");
						break;
				case 3: printf("as a Married couple.");
						break;
				case 4: printf("Engaged.");
						break;
				default: printf("as Sweethearts.");
						break;
			}
		}			
		
		if(ch==2){
			printf("\nEnter first string: ");		gets(nm1);	fflush(stdin);
			printf("\nEnter second string: ");		gets(nm2);	fflush(stdin);
			strcpy(t1,nm1);		strcpy(t2, nm2);
			for(i=0; t2[i]!='\0'; i++){
		while(t1[c]!='\0'){
             printf("\n%c %c ", t2[i], t1[c]);
			if(isupper(t2[i])==1)
				t2[i]+=32;
			if(isupper(t1[c])==1)
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
				printf("\n\n\n%s is a substring of %s", nm2, nm1);
			else
				printf("\n\n\n%s is not a substring of %s", nm2, nm1);
		}
		printf("\n\n\n\n\n");
		system("PAUSE");
		system("CLS");
	}while(ch!=3);
	
	getch();
	return 0;
}
