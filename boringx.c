#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
	srand((unsigned int)time(NULL));
	int bk=100000, p1=20000, p2=20000, p3=20000, p1g, p2g, p3g, p1b, p2b, p3b;
	int d1, d2, dsum, p1f=1, p2f=1, p3f=1, ctr=3, n=1, gf=1, pm;
	char cc, ch, x=4;
//*
	printf("\n******************** WELCOME TO 7-11 ********************");
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
	printf("\n*     	dwindled down to PhP 100.00.\t\t\t*");
	printf("\n* %cThe game will end if the Banker's money has dwindled\t*",x);
	printf("\n* \tdown from PhP 100,000.00 to PhP 10,000.00.\t*");
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
	getch();
	system("CLS");
//*/
    //players
	do{
		printf("\n************** P L A Y E R S ***************");
		printf("\n*\t\t\t\t\t   *\n*\tA = Banker and 2 Players\t   *");
        printf("\n*\t\t\t\t\t   *\n*\tB = Banker and 3 Players\t   *");
        printf("\n*\t\t\t\t\t   *\n********************************************");
        printf("\n\n\n\nChoice: ");
		scanf("%c", &cc);
		if( (cc=='A' || cc=='a') || (cc=='B' || cc=='b') )
			break;
		else
		    system("CLS");
	}while( (cc!='A' || cc!='a') && (cc!='B' || cc!='b') );
	if(cc=='A' || cc=='a'){
		p3f=0;	ctr=2;
	}
	printf("\n\n\n\n\n**Press any key to PLAY.");
	getch();
	system("CLS");
	
	do{
	
	// pair of dice
		do{
			d1=rand();
		}while(d1>6 || d1==0);
		do{
			d2=rand();
		}while(d2>6 || d2==0);
		dsum=d1+d2;	pm=0;
	
		printf("*********************** ROUND %d ***********************", n);
		printf("\n\n\n\nBanker, press any key to roll the pair of dice.\n");
		getch();
		printf("\n\n\nThe pair of dice has been rolled.\n\n\n\tDice 1 + Dice 2 = %d", dsum);
        printf("\n\n\n\n\n**Press any key to guess the sum.");
		getch();
		system("CLS");
		
	//player guesses and bets
		do{
			printf("*********************** ROUND %d ***********************", n);
			if(p1f){
				printf("\n\n%cPlayer 1", x);
				do{
					printf("\n\t\tEnter your guess: ");		scanf("%d", &p1g);
					if(p1g>12 || p1g<2)
						printf("\n\t\t(Invalid input)\n");
				}while(p1g>12 || p1g<2);
				do{
					printf("\n\t\tEnter your bet: ");			scanf("%d", &p1b);
					if(p1b>p1)
						printf("\n\t(Invalid input)\n");
				}while(p1b>p1);
			}
	
			if(p2f){
				printf("\n\n%cPlayer 2", x);
				do{
					printf("\n\t\tEnter your guess: ");		scanf("%d", &p2g);
					if(p2g>12 || p2g<2)
						printf("\n\t\t(Invalid input)\n");
				}while(p2g>12 || p2g<2);
				do{
					printf("\n\t\tEnter your bet: ");			scanf("%d", &p2b);
					if(p2b>p2)
						printf("\n\t\t(Invalid input)\n");
				}while(p2b>p2);
			}
	
			if(p3f){
				printf("\n\n%cPlayer 3", x);
				do{
					printf("\n\t\tEnter your guess: ");		scanf("%d", &p3g);
					if(p3g>12 || p3g<2)
						printf("\n\t\t(Invalid input)\n");
				}while(p3g>12 || p3g<2);
				do{
					printf("\n\t\tEnter your bet: ");			scanf("%d", &p3b);
					if(p2b>p2)
						printf("\n\t\t(Invalid input)\n");
				}while(p3b>p3);
			}
			if( (p1b+p2b+p3b) > bk ){
				printf("\n\nThe sum of bets entered exceeds the capital of the banker.");
				printf("\n\n\n\n\n**Press any key to re-enter.");
				getch();
				system("CLS");
			}
			else{
				printf("\n\n\n\n\n**Press any key to reveal the sum.");
				getch();
				system("CLS");
			}
		}while((p1b+p2b+p3b)>bk);
		n++;
	
	//check if guesses are correct
		if(p1g==dsum && p2g==dsum && p3g==dsum)
		{
			printf("\n\nAll players guessed it right! The sum is %d.", dsum);
			p1+=p1b;	p2+=p2b;	p3+=p3b;
			bk-=(p1b+p2b+p3b); pm=1;
		}
		else if(p1g==dsum && p2g==dsum)
		{
			printf("\n\nPlayer 1 and Player 2 guessed it right! The sum is %d.", dsum);
			p1+=p1b;	p2+=p2b;	p3-=p3b;
			bk-=(p1b+p2b);	pm=1;
		}
		else if(p1g==dsum && p3g==dsum)
		{
			printf("\n\nPlayer 1 and Player 3 guessed it right! The sum is %d.", dsum);
			p1+=p1b;	p2-=p2b;	p3+=p3b;
			bk-=(p1b+p3b);	pm=1;
		}
		else if(p2g==dsum && p3g==dsum)
		{
			printf("\n\nPlayer 2 and Player 3 guessed it right! The sum is %d.", dsum);
			p1+=p1b;	p2+=p2b;	p3+=p3b;
			bk-=(p2b+p3b);	pm=1;
		}
		else if(p1g==dsum)
		{
			p1+=p1b;	bk-=p1b;
			printf("\n\nPlayer 1 guessed it right! The sum is %d.", dsum);
			p2-=p2b;	p3-=p3b;	pm=1;
		}
		else if(p2g==dsum)
		{
			p2+=p2b;	bk-=p2b;
			printf("\n\nPlayer 2 guessed it right! The sum is %d.", dsum);
			p1-=p1b;	p3-=p3b;	pm=1;
			
		}
		else if(p3g==dsum)
		{
			p3+=p3b;	bk-=p3b;
			printf("\n\nPlayer 3 guessed it right! The sum is %d.", dsum);
			p1-=p1b;	p2-=p2b;	pm=1;
		}
		else
		{
			printf("\n\nWrong! The sum is %d.", dsum);
			p1-=p1b;	p2-=p2b;	p3-=p3b;
			//bk+=p1b+p2b+p3b;
		}
		
		if(pm==1){
			printf("\n\n\nBanker, press any key to PAY.");
			getch();
			printf("\n\n\n\n\tTransaction successful.");
		}
		
		printf("\n\n\n\n\n**Press any key to view amount status.");
		getch();
		system("CLS");
	
	//display of current amount
		printf("\n");
		if(p1f)
			printf("\n\n\tPlayer 1 has PhP %d", p1);
		if(p2f)
			printf("\n\n\tPlayer 2 has PhP %d", p2);
		if(p3f)
			printf("\n\n\tPlayer 3 has PhP %d", p3);
		printf("\n\n\n\tBanker has PhP %d", bk);

		printf("\n\n\n\n\n**Press any key to continue.");
		getch();
		system("CLS");	
		
	//check for elimination
		if(p1f!=0 && p1<101){
			printf("\nPlayer 1 has less than or equal to PhP 100.00 left. Eliminated.\n", p1);
			p1f=0;	ctr--;	p1g=0;	p1b=0;
		}
	
		if(p2f!=0 && p2<101){
			printf("\nPlayer 2 has less than or equal to PhP 100.00 left. Eliminated.\n", p2);
			p2f=0;	ctr--;  p2g=0;	p2b=0;
		}
	
		if(p3f!=0 && p3<101){
			printf("\nPlayer 3 has less than or equal to PhP 100.00 left. Eliminated.\n", p3);
			p3f=0;	ctr--;  p3g=0;	p3b=0;
		}
		
		if(p1f==0 && p2f==0 && p3f==0)
		    gf=0;
		
		if(bk>10000 && gf==1)
			printf("\n\n\n\n\nPress any to advance to the next round.");
		else
		    printf("\n\n\n\n\nPress any key to continue.");
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
				else
					system("CLS");
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
			printf("\n\nThe player/s has less than or equal to PhP 100.00 left.", bk);
	}
			
	printf("\n\n\n\nThe game has ended. Thank you for playing.");
	
	getch();
	return 0;
}
