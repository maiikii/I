#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void IntroOutro(int);
int CalcDmgSh(int x, int y);
int CalcDmgWe(int x, int y);
int AttCh(int x);


int main(void)
{
	srand((unsigned int)time(NULL));
	int lyf1, lyf2, mna1, mna2, weap1, shld1, weap2, shld2, mnbk, sp1, sp2, dmg;
	int wpf, shdf, mlf1, mlf2, suat, chatt, choi=1, tm;
	IntroOutro(1);
	do{
		mlf1=mlf2=1;
		lyf1=10; lyf2=10; mna1=10; mna2=10;
		weap1=rand()%3+1;	weap2=rand()%3+1;
		shld1=rand()%3+1;	shld2=rand()%3+1;
		system("CLS");
		system("color 09");
		printf("\n\t\t\t      *****************");
		printf("\n\t\t\t     *******************");
		printf("\n\t\t\t    ***************    ***");
		printf("\n\t\t\t   **************       **");
		printf("\n\t\t\t  **************         **");
	 	printf("\n\t\t\t **************           **");
	 	printf("\n\t\t\t*****************************");
	 	printf("\n\t\t\t ***************************");
	 	printf("\n\t\t\t  **********  ***        **");
	 	printf("\n\t\t\t   ********    ***      **");
	 	printf("\n\t\t\t    ******      ***    **");
	 	printf("\n\t\t\t     ****        ***  **");
	 	printf("\n\t\t\t      *****************");
	 	system("color 0f"); Sleep(100);
	 	printf("\n\t\t\t      S T A R T  G A M E");
		system("color f0"); Sleep(100);
		system("color 09");
		printf("\n\n\n\n\t\t    Player 1 acquiring weapon and shield.");
		Sleep(1500);
		printf("\n\n\t\t Equipped with ");
		switch(weap1){
			case 1: printf("Wooden Spear and");		break;
			case 2: printf("Silver Ax and"); 		break;
			case 3: printf("Diamond Scythe and");	break;
		}
		switch(shld1){
			case 1: printf(" Wooden Shield.");	break;
			case 2: printf(" Silver Shield."); 	break;
			case 3: printf(" Diamond Shield.");	break;
		}
		Sleep(3000);
		printf("\n\n\n\n\t\t    Player 2 acquiring weapon and shield.");
		Sleep(1500);
		printf("\n\n\t\t Equipped with ");
		switch(weap2){
			case 1: printf("Wooden Spear and");		break;
			case 2: printf("Silver Ax and"); 		break;
			case 3: printf("Diamond Scythe and");	break;
		}
		switch(shld2){
			case 1: printf(" Wooden Shield.");	break;
			case 2: printf(" Silver Shield."); 	break;
			case 3: printf(" Diamond Shield.");	break;
		}
		Sleep(3000);
		printf("\n\n\n\n\n\t   Players now equipped. Entering battlefield.");
		for(tm=0; tm<5; tm++){
			printf(" .");
			Sleep(1500);
		}
			do{
				system("CLS");
				system("color 0a");
				if(mna1<9)			mna1+=2;
				else if(mna1==9)	mna1+=1;
				printf("\t\t\t       ************");
			 	printf("\n\t\t\t      ************** RATAVA RPG");
			 	printf("\n\t\t\t     *********      *");
			 	printf("\n\t\t\t    *********        *");
			 	printf("\n\t\t\t   ********************");
			 	printf("\n\t\t\t    ******************");
			 	printf("\n\t\t\t     *****    **    *");
			 	printf("\n\t\t\t      ***      ** *");
			 	printf("\n\t\t\t       ************");
				printf("\n\t\t*********************************************");
				printf("\n\t\tPlayer 1\tLife %d / 10\tManna %d / 10", lyf1, mna1);
				printf("\n\t\t*********************************************");
				
				shdf=rand()%3+1;	suat=rand()%9;		chatt=0;
				if(mlf1)
					mnbk=rand()%20+1;
				if(mna1>5)
					chatt=AttCh(mna1);
				else{
					printf("\n\n\t\tNot enough manna to cast a spell\n");
					Sleep(1000);
				}
				if(mnbk==13){
					printf("\n\n\t\tPlayer 1 has found Mona Lisa's Blink!");
					mlf1=0;
					mnbk=0;
				}
				printf("\n\n\n\t\t\aPlayer 1 attacks!");
				if(chatt){
					mna1-=6;	dmg=2;
					printf("\n\n\t\tCasting the Kiss of the Jade Smoke spell!");
					Sleep(1000);
					system("color 47");	Sleep(150);
					system("color 74");	Sleep(150);
					system("color 47");	Sleep(150);
					system("color 74");
					system("color 0a");
					if(mlf2==1)
						printf("\n\n\t\tOpponent unsuccessfully counters the spell!");
					else{
						printf("\n\n\t\tOpponent Mona Lisa's Blink activated!");
						Sleep(1000);
						system("color 9f");	Sleep(150);
						system("color f9");	Sleep(150);
						system("color 0a");
						printf("\n\n\t\tOpponent successfully counters the spell");
						mlf2=1;		dmg=0;
					}
				}
				else{
					system("color 47");	Sleep(150);
					system("color 74");	Sleep(150);
					system("color 0a");
					if(suat){
						Sleep(1000);
						if(shdf==1){
							system("color 9f");	Sleep(150);
							system("color f9");	Sleep(150);
							system("color 0a");
							printf("\n\n\t\tOpponent uses shield!");
							dmg=CalcDmgSh(weap1, shld2);								
						}
						else
							dmg=CalcDmgWe(weap1, weap2);
					}
					else{
						Sleep(1000);
						printf("\n\n\t\tAttack missed!");
						dmg=0;
					}
				}
				Sleep(1000);
				if( shld2==3 && shdf==1 && dmg && !(chatt) ){
					lyf1-=dmg;
					printf("\n\n\n\n\n\t\t%d damage ", dmg);
					if(dmg>1)
						printf("points ");
					else
						printf("point ");
					printf("inflicted to self");
				}
				else if(dmg==0)
					printf("\n\n\n\n\n\t\tNo damage done");
				else{
					lyf2-=dmg;
					printf("\n\n\n\n\n\t\t%d damage ", dmg);
					if(dmg>1)
						printf("points ");
					else
						printf("point ");
					printf("inflicted to opponent");
				}
				
				if(lyf2<1)
					break;
				Sleep(4000);
				system("CLS");
				system("color 0b");
				if(mna2<9)			mna2+=2;
				else if(mna2==9)	mna2+=1;
				printf("\t\t\t       ************");
			 	printf("\n\t\t\t      ************** RATAVA RPG");
			 	printf("\n\t\t\t     *********      *");
			 	printf("\n\t\t\t    *********        *");
			 	printf("\n\t\t\t   ********************");
			 	printf("\n\t\t\t    ******************");
			 	printf("\n\t\t\t     *****    **    *");
			 	printf("\n\t\t\t      ***      ** *");
			 	printf("\n\t\t\t       ************");
				printf("\n\t\t*********************************************");
				printf("\n\t\tPlayer 2\tLife %d / 10\tManna %d / 10", lyf2, mna2);
				printf("\n\t\t*********************************************");

				shdf=rand()%3+1;	suat=rand()%11;		chatt=0;
				if(mlf2)
					mnbk=rand()%20+1;
				if(mna2>5)
					chatt=AttCh(mna2);
				else{
					printf("\n\n\t\tNot enough manna to cast a spell\n");
					Sleep(1000);
				}
				if(mnbk==13){
					printf("\n\n\t\tPlayer 2 has found Mona Lisa's Blink!");
					mlf2=0;
					mnbk=0;
				}
				printf("\n\n\n\t\t\aPlayer 2 attacks!");										
				if(chatt){
					printf("\n\n\t\tCasting the Kiss of the Jade Smoke!");
					Sleep(1000);
					system("color 47");	Sleep(150);
					system("color 74");	Sleep(150);
					system("color 47");	Sleep(150);
					system("color 74");
					system("color 0b");
					mna2-=6;	dmg=2;
					if(mlf1)
						printf("\n\n\t\tOpponent unsuccessfully counters the spell!");
					else{
						printf("\n\n\t\tOpponent Mona Lisa's Blink activated!");
						Sleep(1000);
						system("color 9f");	Sleep(150);
						system("color f9");	Sleep(150);
						system("color 0b");
						printf("\n\n\t\tOpponent successfully counters the spell");
						mlf1=1;		dmg=0;
					}
				}
				else{
					system("color 47");	Sleep(150);
					system("color 74");	Sleep(150);
					system("color 0b");
					if(suat){
						sleep(1000);
						if(shdf==1){
							system("color 9f");	Sleep(150);
							system("color f9");	Sleep(150);
							system("color 0b");
							printf("\n\n\t\tOpponent uses shield!");
							dmg=CalcDmgSh(weap2, shld1);
						}
						else
							dmg=CalcDmgWe(weap2, weap1);								
					}
					else{
						Sleep(1000);
						printf("\n\n\t\tAttack missed!");
						dmg=0;
					}
				}
				Sleep(1000);
				if(shld1==3 && shdf==1 && dmg && !(chatt)){
					lyf2-=dmg;
					printf("\n\n\n\n\n\t\t%d damage ", dmg);
					if(dmg>1)
						printf("points ");
					else
						printf("point ");
					printf("inflicted to self");
				}
				else if(dmg==0)
					printf("\n\n\n\n\n\t\tNo damage done");
				else{
					lyf1-=dmg;
					printf("\n\n\n\n\n\t\t%d damage ", dmg);
					if(dmg>1)
						printf("points ");
					else
						printf("point ");
					printf("inflicted to opponent");
				}
				Sleep(4000);
				
			}while(lyf1>0 && lyf2>0);
			
			system("CLS");
			system("color 09");
			printf("\n\n\t\t\t      *****************");
			printf("\n\t\t\t     *******************");
  			printf("\n\t\t\t    ***************    ***");
 			printf("\n\t\t\t   **************       **");
 			printf("\n\t\t\t  **************         **");
		 	printf("\n\t\t\t **************           **");
		 	printf("\n\t\t\t*****************************");
		 	printf("\n\t\t\t ***************************");
		 	printf("\n\t\t\t  **********  ***        **");
		 	printf("\n\t\t\t   ********    ***      **");
		 	printf("\n\t\t\t    ******      ***    **");
		 	printf("\n\t\t\t     ****        ***  **");
		 	printf("\n\t\t\t      *****************");
		 	system("color 0f"); Sleep(100);
		 	printf("\n\t\t\t      G A M E   O V E R");
			system("color f0"); Sleep(100);
			if(lyf1<=0){
				printf("\n\n\n\t\t\t   P L A Y E R  2  W I N S");
				printf("\n\n\t\t\t   Two is better than one");			
			}
			else{
				printf("\n\n\n\t\t\t   P L A Y E R  1  W I N S");
				printf("\n\n\t\t\t     One will always top");	
			}
			system("color 0f"); Sleep(100);
			system("color f0"); Sleep(100);
			system("color 09");
			do{
				printf("\n\n\n\n\n\t\t\t   New game (0-No/1-Yes)? ");
				scanf("%d", &choi);
				if(choi!=0 && choi!=1)
					printf("\n\t\t\t   Invalid input. Retry.");
			}while(choi!=0 && choi!=1);
			
			system("CLS");
			if(choi)
				IntroOutro(1);
			
	}while(choi);
	
	IntroOutro(0);
	exit(0);
	return 0;
}

int AttCh(int x)
{
	int ch;
	printf("\n\n\t\t0 - Use the weapon\t1 - Cast a spell");
	do{
		printf("\n\n\t\tEnter choice: ");
		scanf("%d", &ch);
	}while(ch!=0 && ch!=1);
	return ch;
}


int CalcDmgWe(int x, int y)
{
	int z;
	if( (x==1 && y==1) || (x==2 && y==2) || (x==3 && y==3) ){
		z=0;
		printf("\n\n\t\tAttack neutralized");
	}
	else{
		if(x==1)
			z=1;
		else if(x==2)
			z=2;
		else if(x==3)
			z=3;
		printf("\n\n\t\tAttack successful");
	}
	return z;
}

int CalcDmgSh(int x, int y)
{
	int z;
	if( (x==1 && y==1) || (x==2 && y==2) || (x==3 && y==3) )
		z=0;
	else if( (x==1 && y==2) || (x==1 && y==3) || (x==2 && y==1) )
		z=1;
	else if(  (x==3 && y==2) || (x==2 && y==3) )
		z=2;
	else
		z=3;
		
	if(z==0)
		printf("\n\n\t\tAttack neutralized");
	else if(z==3)
		printf("\n\n\t\tAttack successful");
	else
		printf("\n\n\t\tAttack repelled by one point");
	return z;
}
	
void IntroOutro(int x)
{
 	int i;
 	char ch=4, A[]="Duel to Death";
 	system("color 07");
 	//1
	printf("\n\n\n\n\t\t\t      ");
 	for(i=0; i<17; i++){
 		Sleep(30);
	 	printf("%c", ch);
	}
	//2
	printf("\n\t\t\t     ");
 	for(i=0; i<19; i++){
 		Sleep(30);
	 	printf("%c", ch);
	}
	//3
	printf("\n\t\t\t    ");
 	for(i=0; i<21; i++){
 		Sleep(30);
	 	printf("%c", ch);
	}
	//4
	printf("\n\t\t\t   ");
 	for(i=0; i<16; i++){
 		Sleep(30);
 		if(i==14)
 			printf("       ");
	 	printf("%c", ch);
	}
	// 5
 	printf("\n\t\t\t  ");
 	for(i=0; i<16; i++){
 		Sleep(30);
 		if(i==14)
 			printf("         ");
	 	printf("%c", ch);
	}
	// 6
 	printf("\n\t\t\t ");
 	for(i=0; i<16; i++){
 		Sleep(30);
 		if(i==14)
 			printf("           ");
	 	printf("%c", ch);
	}
	// 7
	printf("\n\t\t\t");
 	for(i=0; i<29; i++){
 		Sleep(30);
	 	printf("%c", ch);
	}
	// 8
	printf("\n\t\t\t ");
	for(i=0; i<27; i++){
 		Sleep(30);
	 	printf("%c", ch);
	}
	//9
 	printf("\n\t\t\t  ");
	for(i=0; i<15; i++){
 		Sleep(30);
 		if(i==10)
	 		printf("  ");
 		else if(i==13)
 			printf("        ");
 		printf("%c", ch);
	}
	// 10
 	printf("\n\t\t\t   ");
 	for(i=0; i<13; i++){
 		Sleep(30);
 		if(i==8)
			printf("    ");
		if(i==11)
			printf("      ");
		printf("%c", ch);
	}
	// 11
 	printf("\n\t\t\t    ");
 	for(i=0; i<11; i++){
 		Sleep(30);
 		if(i==6)
			printf("      ");
		if(i==9)
			printf("    ");
		printf("%c", ch);
	}
	// 12
 	printf("\n\t\t\t     ");
 	for(i=0; i<9; i++){
 		Sleep(30);
 		if(i==4)
			printf("        ");
		if(i==7)
			printf("  ");
		printf("%c", ch);
	}
 	// 13
 	printf("\n\t\t\t      ");
 	for(i=0; i<17; i++){
 		Sleep(30);
	 	printf("%c", ch);
	}
	system("color f4");
	Sleep(100);
	printf("\n\n\t\t\t    R   A");
	system("color 4f");
	Sleep(100);
	printf("   T   A");
	system("color f3");
	Sleep(100);
	system("color 0c");
	printf("   V   A\n\n\t\t\t\t");
	Sleep(2000);
	for(i=0; A[i]!='\0'; i++){
		printf("%c", A[i]);
		Sleep(200);
	}
	if(x)
		printf("\n\n\n\n\n\t\t\t   Loading game.");
	else
		printf("\n\n\n\n\n\t\t\t   Exiting game.");
	for(i=0; i<5; i++){
		Sleep(2000);
		printf(" .");
	}
}
