#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
	srand((unsigned int)time(NULL));
	int bk=100000, p1=20000, p2=20000, p3=20000, p1g, p2g, p3g, p1b, p2b, p3b;
	int d1, d2, dsum, p1f=1, p2f=1, p3f=1, ctr=3, n=1, gf=1;
	char ch;
	
	printf("\nWELCOME TO 7-11\n\n\nPress any key to START.");
	getch();
	system("CLS");
	
    do{
	
	// pair of dice
		d1=rand()%6+1;
		d2=rand()%6+1;
		dsum=d1+d2;
	
	//player guesses and bets
		do{
			printf("\n\n\nGuess the sum.\n");
			if(p1f){
				printf("\n\nPlayer 1");
				do{
				printf("\n\nEnter your guess: ");		scanf("%d", &p1g);
				}while(p1g>12 || p1g<2);
				do{
					printf("\nEnter your bet: ");	scanf("%d", &p1b);
				}while(p1b>p1);
			}
	
			if(p2f){
				printf("\n\nPlayer 2");
				do{
				printf("\n\nEnter your guess: ");		scanf("%d", &p2g);
				}while(p2g>12 || p2g<2);
				do{
					printf("\nEnter your bet: ");	scanf("%d", &p2b);
				}while(p2b>p2);
			}
	
			if(p3f){
				printf("\n\nPlayer 3");
				do{
				printf("\n\nEnter your guess: ");		scanf("%d", &p3g);
				}while(p3g>12 || p3g<2);
				do{
					printf("\nEnter your bet: ");	scanf("%d", &p3b);
				}while(p3b>p3);
			}
			printf("\n\nPress any key to continue.");
			getch();
			system("CLS");
		}while((p1b+p2b+p3b)>bk);
	
	//check if guesses are correct
		if(p1g==dsum && p2g==dsum && p3g==dsum)
		{
			printf("\n\nAll players guessed it right!");
			p1+=p1b;	p2+=p2b;	p3+=p3b;
			bk-=(p1b+p2b+p3b);
		}
		else if(p1g==dsum && p2g==dsum)
		{
			printf("\n\nPlayer 1 and Player 2 guessed it right!");
			p1+=p1b;	p2+=p2b;	p3-=p3b;
			bk-=(p1b+p2b);
		}
		else if(p1g==dsum && p3g==dsum)
		{
			printf("\n\nPlayer 1 and Player 3 guessed it right!");
			p1+=p1b;	p2-=p2b;	p3+=p3b;
			bk-=(p1b+p3b);
		}
		else if(p2g==dsum && p3g==dsum)
		{
			printf("\n\nPlayer 2 and Player 3 guessed it right!");
			p1+=p1b;	p2+=p2b;	p3+=p3b;
			bk-=(p2b+p3b);
		}
		else if(p1g==dsum)
		{
			p1+=p1b;	bk-=p1b;
			printf("\n\nPlayer 1 guessed it right!");
			p2-=p2b;	p3-=p3b;
		}
		else if(p2g==dsum)
		{
			p2+=p2b;	bk-=p2b;
			printf("\n\nPlayer 2 guessed it right!");
			p1-=p1b;	p3-=p3b;
			
		}
		else if(p3g==dsum)
		{
			p3+=p3b;	bk-=p3b;
			printf("\n\nPlayer 3 guessed it right!");
			p1-=p1b;	p2-=p2b;
		}
		else
		{
			printf("\nWrong! The sum is %d.", dsum);
			p1-=p1b;	p2-=p2b;	p3-=p3b;
			//bk+=p1b+p2b+p3b;
		}
	
	//display of current amount
		printf("\n\n");
		if(p1f)
			printf("\n\nPlayer 1 has PhP %d", p1);
		if(p2f)
			printf("\n\nPlayer 2 has PhP %d", p2);
		if(p3f)
			printf("\n\nPlayer 3 has PhP %d", p3);
		printf("\n\nBanker has PhP %d", bk);

		printf("\n\n\n\nPress any key to continue.");
		getch();
		system("CLS");	
		
	//check for elimination
		if(p1f!=0 && p1<101){
			printf("\nPlayer 1 has only PhP %d left. You are eliminated.\n", p1);
			p1f=0;	ctr--;   p1g=0;
		}
	
		if(p2f!=0 && p2<101){
			printf("\nPlayer 2 has only PhP %d left. You are eliminated.\n", p2);
			p2f=0;	ctr--;   p2g=0;
		}
	
		if(p3f!=0 && p3<101){
			printf("\nPlayer 3 has only PhP %d left. You are eliminated.\n", p3);
			p3f=0;	ctr--;   p3g=0;
		}
		
		if(p1f==0 && p2f==0 && p3f==0)
		          gf=0;
		
		if(bk>10000 && gf==1)
			printf("\n\n\nPress any to advance to the next round.");
		getch();
		system("CLS");
	
	//if 1 player left
		if(ctr==1){
			do{
				printf("\n\nOnly one player remaining. Do you wish to continue (Y/N)? ");
				scanf("%c", &ch);
				if( (ch=='Y' || ch=='y') || (ch=='N' || ch=='n') ){
                    ctr--;
					break;
				}
				else{
					system("CLS");
				}
			}while( (ch!='Y' || ch!='y') && (ch!='N' || ch!='n') );
		}
		
		system("CLS");
		if(ch=='N' || ch=='n')
			break;
			
	}while(bk>10000 && gf==1);
	
	//game has ended
	system("CLS");
	if(ch!='N' || ch!='n'){
		if(bk<10000)
			printf("\n\nThe Banker has less than or equal to PhP 10000.00 left.", bk);
		if(gf==0)
			printf("\n\nThe player/s has/ve less than or equal to PhP 100.00 left.", bk);
	}
			
	printf("\n\n\nThe game has ended. Thank you for playing.");
	
	getch();
	return 0;
}
