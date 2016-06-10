#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
	srand((unsigned int)time(NULL));
	int bk=100000, p1=20000, p2=20000, p3=20000, p1g, p2g, p3g, p1b, p2b, p3b, ef;
	int d1, d2, dsum, p1f=1, p2f=1, p3f=1, ctr=3, n=1, ch, ctrc=3, nrf, bkf=1;
	char cc, x=4;
	system("color fc");

	printf("\n************** W E L C O M E  T O  7 - 1 1 **************");
	printf("\n*\t\t\t\t\t\t\t*");
	printf("\n* MECHANICS:\t\t\t\t\t\t*");
	printf("\n*\t\t\t\t\t\t\t*");
	printf("\n* %cFour players including the banker.\t\t\t*", x);
	printf("\n* %cThe banker rolls a pair of dice and each player\t*",x);
	printf("\n* \tguesses the sum of the dices.\t\t\t*");
	printf("\n* %cEach player has PhP 20,000.00.\t\t\t*",x);
	printf("\n* %cEvery time a player guesses the resulting sum, a\t*",x); 
	printf("\n* \tcorresponding bet is placed.\t\t\t*");
	printf("\n* %cIf the player guesses the right sum, the banker pays\t*",x); 
	printf("\n* him/her with an amount equivalent to his/her bet.\t*");
	printf("\n* %cA player will be eliminated if his/her money has\t*",x);
	printf("\n* \tdwindled down to PhP 100.00.\t\t\t*");
	printf("\n* %cThe game will end if the banker's money has dwindled\t*",x);
	printf("\n* \tdown from PhP 100,000.00 to PhP 10,000.00.\t*");
	printf("\n* %cThe game will end if there's only one player left\t*",x);
	printf("\n*\t\tagainst the banker.\t\t\t*");
	printf("\n*\t\t\t\t\t\t\t*");
	printf("\n*********************************************************");
	
	printf("\n\n\n\n\n**Press any key to continue.");
	getch();
	system("CLS");
	
	printf("\n************************ N O T E ************************");
	printf("\n*\t\t\t\t\t\t\t*");
	printf("\n* %cIf the sum of all three players' bets entered\t*", x);
    printf("\n*\texceeds the capital of the Banker.\t\t*");
    printf("\n* %cIf the bet entered exceeds the current PhP of a\t*", x);
    printf("\n*\t\tplayer.\t\t\t\t\t*");
    printf("\n* %cIf the guess of the sum is more than 12 and less\t*", x);
    printf("\n*\t\tthan two.\t\t\t\t*");
    printf("\n*\t\t\t\t\t\t\t*");
    printf("\n* Under these conditions, the player/s must RE-ENTER\t*");
    printf("\n*\tthe value of the bet/s or guess/es.\t\t*");
    printf("\n*\t\t\t\t\t\t\t*");
	printf("\n*********************************************************");
	printf("\n\n\n\n\n**Press any key to START.");
	getch();	system("CLS");
	
	do{
	
	// pair of dice
		d1=rand()%60+1;
		d2=rand()%60+1;
		system("color f9");
		
		printf("********************* R O U N D %d *********************", n);
		printf("\n\n\nThe Banker has rolled the pair of dice.\n");
		printf("\n\n\n\tDice 1 + Dice 2 = ? %d", dsum);
		printf("\n\n\n\n\n**Press any key to guess the sum.");
		getch();
		system("CLS");
	
	//player guesses and bets
		do{
			printf("********************* R O U N D %d *********************", n);
			if(p1f){
				printf("\n\n%cPlayer 1", x);
				do{
					printf("\n\t\tEnter your guess: ");		scanf("%d", &p1g);
					if(p1g>12 || p1g<2)
						printf("\t\t(Invalid input. Retry.)\n");
				}while(p1g>12 || p1g<2);
				do{
					printf("\n\t\tEnter your bet: ");			scanf("%d", &p1b);
					if(p1b>p1)
						printf("\t\t(Invalid input. Retry.)\n");
				}while(p1b>p1);
			}
	
			if(p2f){
				printf("\n\n%cPlayer 2", x);
				do{
					printf("\n\t\tEnter your guess: ");		scanf("%d", &p2g);
					if(p2g>12 || p2g<2)
						printf("\t\t(Invalid input. Retry.)\n");
				}while(p2g>12 || p2g<2);
				do{
					printf("\n\t\tEnter your bet: ");			scanf("%d", &p2b);
					if(p2b>p2)
						printf("\t\t(Invalid input. Retry.)\n");
				}while(p2b>p2);
			}
	
			if(p3f){
				printf("\n\n%cPlayer 3", x);
				do{
					printf("\n\t\tEnter your guess: ");		scanf("%d", &p3g);
					if(p3g>12 || p3g<2)
						printf("\t\t(Invalid input. Retry.)\n");
				}while(p3g>12 || p3g<2);
				do{
					printf("\n\t\tEnter your bet: ");			scanf("%d", &p3b);
					if(p3b>p3)
						printf("\t\t(Invalid input. Retry.)\n");
				}while(p3b>p3);
			}
			if( (p1b+p2b+p3b) > bk ){
				printf("\n\nThe sum of bets entered exceeds the PhP %d.00 capital of the banker.", bk);
				printf("\n\n\n\n\n**Press any key to re-enter.");
				getch();	system("CLS");
			}
			else{
				printf("\n\n\n\n\n**Press any key to reveal the sum.");
				getch();	system("CLS");
			}
		}while((p1b+p2b+p3b)>bk);
		n++;
	
	//check if guesses are correct
		system("color f6");
		printf("************* S U M  O F  T H E  D I C E S *************");
		if(p1g==dsum && p2g==dsum && p3g==dsum)
		{
			printf("\n\nAll players guessed it right! The sum is %d.", dsum);
			printf("\n\n\nBanker has made transactions to transfer money.");
			p1+=p1b;	p2+=p2b;	p3+=p3b;	bk-=(p1b+p2b+p3b);
		}
		else if(p1g==dsum && p2g==dsum)
		{
			printf("\n\nPlayer 1 and Player 2 guessed it right! The sum is %d.", dsum);
			printf("\n\n\nBanker has made transactions to transfer money.");
			p1+=p1b;	p2+=p2b;	p3-=p3b;	bk=(bk+p3b)-(p1b+p2b);
		}
		else if(p1g==dsum && p3g==dsum)
		{
			printf("\n\nPlayer 1 and Player 3 guessed it right! The sum is %d.", dsum);
			printf("\n\n\nBanker has made transactions to transfer money.");
			p1+=p1b;	p2-=p2b;	p3+=p3b;	bk=(bk+p2b)-(p1b+p3b);
		}
		else if(p2g==dsum && p3g==dsum)
		{
			printf("\n\nPlayer 2 and Player 3 guessed it right! The sum is %d.", dsum);
			printf("\n\n\nBanker has made transactions to transfer money.");
			p1-=p1b;	p2+=p2b;	p3+=p3b;	bk=(bk+p1b)-(p2b+p3b);
		}
		else if(p1g==dsum)
		{
			p1+=p1b;	bk-=p1b;	p2-=p2b;	p3-=p3b;	bk+=p2b+p3b;
			printf("\n\nPlayer 1 guessed it right! The sum is %d.", dsum);
			printf("\n\n\nBanker has made transaction to transfer money.");
		}
		else if(p2g==dsum)
		{
			p2+=p2b;	bk-=p2b;	p1-=p1b;	p3-=p3b;	bk+=p1b+p3b;
			printf("\n\nPlayer 2 guessed it right! The sum is %d.", dsum);
            printf("\n\n\nBanker has made transaction to transfer money.");		
		}
		else if(p3g==dsum)
		{
			p3+=p3b;	bk-=p3b;	p1-=p1b;	p2-=p2b;	bk+=p1b+p2b;
			printf("\n\nPlayer 3 guessed it right! The sum is %d.", dsum);
			printf("\n\n\nBanker has made transaction to transfer money.");
		}
		else
		{
			printf("\n\nWrong! The sum is %d.", dsum);
			p1-=p1b;	p2-=p2b;	p3-=p3b;	bk+=p1b+p2b+p3b;
			printf("\n\n\nBanker has made transactions to transfer money.");
		}
		printf("\n\n\n\n\n**Press any key to view the money of players.");
		getch();	system("CLS");
		
		if(ctr>1)
			nrf=1;
	
	//display of current amount
		printf("************* M O N E Y  O F  P L A Y E R S **************");
		printf("\n\n\n\tBanker has PhP %d capital", bk);
		if(p1f)
			printf("\n\n\n\tPlayer 1 has PhP %d", p1);
		if(p2f)
			printf("\n\n\tPlayer 2 has PhP %d", p2);
		if(p3f)
			printf("\n\n\tPlayer 3 has PhP %d", p3);
		printf("\n\n\n\n\n**Press any key to proceed.");
		getch();	system("CLS");	
		
		
	//check for elimination
		system("color f3");
		ef=1;
		printf("***************** E L I M I N A T I O N *****************", n);
		if(p1f!=0 && p1<101){
			printf("\n\nPlayer 1 has less than or equal to PhP 100.00 left.\n", p1);
			p1f=0;	ctr--;	p1g=0;  p1b=0;	ef=0;
		}
		if(p2f!=0 && p2<101){
			printf("\n\nPlayer 2 has less than or equal to PhP 100.00 left.\n", p2);
			p2f=0;	ctr--;  p2g=0;  p2b=0;	ef=0;
		}
	    if(p3f!=0 && p3<101){
			printf("\n\nPlayer 3 has less than or equal to PhP 100.00 left.\n", p3);
			p3f=0;	ctr--;  p3g=0;  p3b=0;	ef=0;
		}
		if(bk<10001){
		    bk=0;    break;
           }
		if(ef)
			printf("\n\n\tNone is valid for elimination.");
		printf("\n\n\n\n\nPress any key to proceed.");
		getch();	system("CLS");
		
		//continue or not
		while(ctr>1 && nrf==1){
			system("color f3");
			printf("************** P L A Y  N E X T  R O U N D **************", n);
			do{
				if(p1f){
					printf("\n\nPlayer 1, continue to next round (0-YES/1-NO)? ");
					scanf("%d", &ch);
					if(ch==1){
						printf("\n\tPlayer 1 withdraws from the game.\n");	p1f=0;	ctr--;
						p1=0;	ctrc--;		nrf=0;
					}
					else if(ch==0){
						printf("\n\tPlayer 1 advances to the next round.\n");	nrf=0;
					}
					else
						printf("(Invalid input. Retry)\n");
				}
			}while(ch!=1 && ch!=0);
			do{
				if(p2f){
					printf("\n\nPlayer 2, continue to next round (0-YES/1-NO)? ");
					scanf("%d", &ch);
					if(ch==1){
						printf("\n\tPlayer 2 withdraws from the game.\n");	p2f=0;	ctr--;
						p2=0;	ctrc--;		nrf=0;
					}
					else if(ch==0){
						printf("\n\tPlayer 2 advances to the next round.\n");	nrf=0;
					}
					else
						printf("(Invalid input. Retry)\n");
				}
			}while( ch!=1 && ch!=0 );
			do{
				if(p3f){
					printf("\n\nPlayer 3, continue to next round (0-YES/1-NO)? ");
					scanf("%d", &ch);
					if(ch==1){
						printf("\n\tPlayer 3 withdraws from the game.");	p3f=0;	ctr--;
						p3=0;	ctrc--;		nrf=0;
					}
					else if(ch==0){
						printf("\n\tPlayer 3 advances to the next round.\n");	nrf=0;
					}
					else
						printf("(Invalid input. Retry)\n");
				}
			}while( ch!=1 && ch!=0 );
		}
		
		if(bk>10000 && ctr>1){
			printf("\n\n\n\n\n**Press any key to advance to the next round.");
			getch();	system("CLS");
		}
		else{
			/*printf("\n\n\n\n**Press any key continue.");
			getch();        system("CLS");*/     break;
		}
		
	}while(bk>10000 && ctr>1);
	
	//game has ended
	system("CLS");	system("color f5");
	printf("************************ G A M E  O V E R ************************");
	if(ch!='N' || ch!='n'){
		if(bk<10000)
			printf("\n\nThe Banker has less than or equal to PhP 10000.00 left.");
		else if(ctr==1)
			printf("\n\nOnly one player remaining, the game has stopped.");
		else if(ctrc==0)
			printf("\n\nThe player/s has/ve withdrawn.", bk);
		else if(ctr==0)
			printf("\n\nThe player/s has/ve less than or equal to PhP 100.00 left");
	}
			
	printf("\n\n\n\nThank you for playing.");
	
	getch();
	return 0;
}
