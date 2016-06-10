#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int ply1Life, ply2Life, ply1Manna, ply2Manna, ply1weapon, ply1shield,
		ply2weapon, ply2shield, r1, r2, r3, r4, rr, rg, a, b, c, d, input;
	int str[15], str2[15];
	char ch;

	srand((unsigned int)time(NULL));

	// 

	printf("\n\n\n\n\nRATAVA\n\n\n\n\n");

	// initialization

	ply1Life = 10;
	ply2Life = 10;
	ply1Manna = 10;
	ply2Manna = 10;

	// First weapon and shield of players will be randomized.

	r1 = rand() % 3 + 1;
	r2 = rand() % 3 + 1;
	r3 = rand() % 3 + 1;
	r4 = rand() % 3 + 1;


	printf("\nPlayer 1 --\nWEAPON: \n");


	switch (r1)
	{

	case 1:
		{
			printf("Wooden Spear.\n");
			a = 1;
			ply1weapon = a;
		}
		break;

	case 2:
		{
			printf("Silver Ax.\n");
			a = 2;
			ply1weapon = a;
		}
		break;

	case 3:
		{
			printf("Diamond Scythe.\n");
			a = 3;
			ply1weapon = a;
		}
		break;

	}

	printf("\nSHIELD: \n");

	switch (r2)
	{

	case 1:
		{
			printf("Wooden Shield.\n");
			b = 1;
			ply1shield = b;
		}
		break;

	case 2:
		{
			printf("Silver Shield.\n");
			b = 2;
			ply1shield = b;
		}
		break;

	case 3:
		{
			printf("Diamond Shield.\n");
			b = 3;
			ply1shield = b;
		}
		break;

	}

	printf("\n\nPlayer 2 --\nWEAPON: \n");

	switch (r3)
	{

	case 1:
		{
			printf("Wooden Spear.\n");
			c = 1;
			ply2weapon = c;
		}
		break;

	case 2:
		{
			printf("Silver ax.\n");
			c = 2;
			ply2weapon = c;
		}
		break;

	case 3:
		{
			printf("Diamond Scythe.\n");
			c = 3;
			ply2weapon = c;
		}
		break;

	}

	printf("\nSHIELD:\n");

	switch (r4)
	{

	case 1:
		{
			printf("Wooden Shield.\n");
			d = 1;
			ply2shield = d;
		}
		break;

	case 2:
		{
			printf("Silver Shield.\n");
			d = 2;
			ply2shield = d;
		}
		break;

	case 3:
		{
			printf("Diamond Shield.\n");
			d = 3;
			ply2shield = d;
		}
		break;

	}

	printf("\n\n\n");
	system("pause");
	system("cls");
	// Player 1 will attack Player 2

	while (ply1Life > 0 || ply2Life > 0)
	{
		printf("\n\n\nPlayer 1 attacking Player 2.\n\n");

		// casting a spell
		printf("Want to cast a spell? If yes, press 1. ");
		scanf("%c", &ch);
		if (ch == '1')
		{
			if (ply1Manna >= 6)
			{
				printf("\n\n\nKiss of the Jade smoke activated. . .");
				printf("\n\nPlayer 2 countering the spell. . .");
				rg = rand() % 20 + 1;
				if (rg > 10)
				{
					printf("\n\nPlayer 2 Successfully counter the spell!.");
					ply1Manna -= 6;
				}
				else if (rg < 10)
				{
					printf("\n\nFailed to counter the spell.");
					ply2Life -= 2;
					ply1Manna -= 6;
				}
			}
			else
				printf
					("\n\nUnable to cast a spell. Required of 6 manna points.");
		}
		else
		{
			rr = rand() % 3 + 1;
			printf("\n\n\nFrom 1-3, enter a number: ");
			scanf("%i", &input);
			if (input == rr){
				printf("Player 2 uses the shield!\n\n");
				if((ply1weapon==1 && ply2shield==1) || (ply1weapon==2 && ply2shield==2) || (ply1weapon==3 && ply2shield==3) )
					printf("The attack is neutralized.");
				else if((ply1weapon==1 && ply2shield==2) || (ply1weapon==1 && ply2shield==3)){
					printf("Attack repelled!");
					ply2Life=-1;
				}
				else if(/*conditions*/){
					printf("love or rose churva haha");
					ply2Life=-2;
				}
				else if(/*conditions*/){
					printf("love or rose churva haha");
					ply2Life=-3;
				}
			}
			else
			{
				if((ply1weapon==1 && ply2weapon==1) || (ply1weapon==2 && ply2weapon==2) || (ply1weapon==3 && ply2weapon==3) )
					printf("The attack is neutralized.");
				else if(ply1weapon==1){
					printf("love or rose churva haha");
					ply2Life=-1;
				}
				else if(ply1weapon==2){
					printf("love or rose churva haha");
					ply2Life=-2;
				}
				else{
					printf("love or rose churva haha");
					ply2Life=-3;
				}
				printf("You were hit!.\n\n");
			}
		}

		// manna

		if (ply1Manna == 9)
			ply1Manna += 1;
		else if (ply2Manna < 9)
			ply1Manna += 2;
		
		printf("\n\n\n");
		system("pause");
		system("cls");
		printf
			("\n\nCurrent status for Player 1: Life = %i\nManna = %i\n\n\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
			 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		// player 2 attacking player 1

		printf("\nPlayer 2 now attacks Player 1.\n");

		// casting a spell
		printf("Want to cast a spell? If yes, press 1. ");
		scanf("%c", &ch);
		if (ch == '1')
		{
			if (ply2Manna >= 6)
			{
				printf("Kiss of the Jade smoke activated. . .");
				printf("Player 1 countering the spell. . .");
				rg = rand() % 20 + 1;
				if (rg > 10)
				{
					printf("Player 1 Successfully counter the spell!.");
					ply2Manna -= 6;
				}
				else if (rg < 10)
				{
					printf("Failed to counter the spell.");
					ply1Life -= 2;
					ply2Manna -= 6;
				}
			}
			else
				printf
					("Unable to cast a spell. Required of 6 manna points.");
		}
		else if (ch != '1')
		{
			rr = rand() % 3 + 1;
			printf("From 1-3, enter a number: \n");
			scanf("%i", &input);
			if (input == rr)
				if((ply2weapon==1 && ply1shield==1) || (ply1weapon==2 && ply2shield==2) || (ply1weapon==3 && ply2shield==3) )
					printf("The attack is neutralized.");
				else if((ply1weapon==1 && ply2shield==2) || (ply1weapon==1 && ply2shield==3)){
					printf("Attack repelled!");
					ply1Life=-1;
				}
				else if(/*conditions*/){
					printf("love or rose churva haha");
					ply1Life=-2;
				}
				else if(/*conditions*/){
					printf("love or rose churva haha");
					ply1Life=-3;
				}
			else
			{	
				if((ply1weapon==1 && ply2weapon==1) || (ply1weapon==2 && ply2weapon==2) || (ply1weapon==3 && ply2weapon==3) )
					printf("The attack is neutralized.");
				else if(ply1weapon==1){
					printf("love or rose churva haha");
					ply1Life=-1;
				}
				else if(ply1weapon==2){
					printf("love or rose churva haha");
					ply1Life=-2;
				}
				else{
					printf("love or rose churva haha");
					ply1Life=-3;
				}
				printf("You were hit!.\n\n");
			}
		}

		// manna

		if (ply2Manna == 9)
			ply2Manna += 1;
		else if (ply2Manna < 9)
			ply2Manna += 2;

		printf
			("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n",
			 ply1Life, ply1Manna, ply2Life, ply2Manna);

		
	}

	return 0;
}
