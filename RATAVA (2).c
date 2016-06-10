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

		// weapon: wooden spear w/ diff. shields
		if (ply1weapon == 1 && ply2shield == 1)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply1Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 2 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 2 Successfully counter the spell!\n\n");
						ply1Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply2Life -= 2;
						ply1Manna -= 6;
					}
				}
				else
					printf
						("\n\nUnable to cast a spell. Required of 6 manna points.");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("\n\n\nFrom 1-3, enter a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf("You repelled the attack of player 1!\n\n");
				else
				{
					printf("You were hit! One damage point reduced.\n\n");
					ply2Life--;
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
		else if (ply1weapon == 1 && ply2shield == 2)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1.");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply1Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 2 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 2 Successfully counter the spell!.\n\n");
						ply1Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply2Life -= 2;
						ply1Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("\n\n\nFrom 1-3, enter a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf("You've successfully repelled the attacked!\n\n");
				else
				{
					printf("You got hit! One damage point deducted.\n\n");
					ply2Life--;
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
			printf("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply1weapon == 1 && ply2shield == 3)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply1Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 2 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 2 Successfully counter the spell!.\n\n");
						ply1Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply2Life -= 2;
						ply1Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("\n\n\nFrom 1-3, enter a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf("You successfully shield the attacked!\n\n");
				else
				{
					printf("You were hit! One damage point lose.\n\n");
					ply2Life--;
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
			
			printf("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}

		// weapon: silver ax w/ diff. shields

		else if (ply1weapon == 2 && ply2shield == 1)
		{

			// casting a spell
			printf("\n\n\nWant to cast a spell? If yes, press 1.");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply1Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 2 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 2 Successfully counter the spell!.\n\n");
						ply1Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply2Life -= 2;
						ply1Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, pick a number: ");
				scanf("%i", &input);
				if (input == rr)
				{
					printf
						("You have repelled the attack but.. 1 point damage.\n\n");
					ply2Life--;
				}
				else
				{
					printf
						("Oh no! You failed to counter the attack. 2 damage points happened.\n\n");
					ply2Life -= 2;
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
			
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf("\n\nCurrent status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply1weapon == 2 && ply2shield == 2)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1.");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply1Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 2 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 2 Successfully counter the spell!.\n\n");
						ply1Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply2Life -= 2;
						ply1Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, pick a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf
						("No damage points happened. You have succesfully countered the attack.\n\n");
				else
				{
					printf
						("Oh man. You failed to shield.\n2 damage points deducted and RIP grammar.\n\n");
					ply2Life -= 2;
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
			printf("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply1weapon == 2 && ply2shield == 3)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply1Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 2 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 2 Successfully counter the spell!.\n\n");
						ply1Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply2Life -= 2;
						ply1Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, pick a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf("Lucky! No damage points deducted.\n\n");
				else
				{
					printf
						("Boo. You failed to counter the attack. 2 damage points deducted from you.\n\n");
					ply2Life -= 2;
				}
			}

			// manna

			if (ply1Manna == 9)
				ply1Manna += 1;
			else if (ply2Manna < 9)
				ply1Manna += 2;

			printf("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}

		// weapon: diamond scythe w/ diff. shields

		else if (ply1weapon == 3 && ply2shield == 1)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply1Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 2 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 2 Successfully counter the spell!.\n\n");
						ply1Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply2Life -= 2;
						ply1Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, choose a number: ");
				scanf("%i", &input);
				if (input == rr)
				{
					printf
						("Good shield! But.. not good enough. 2 damage points happened.\n\n");
					ply2Life -= 2;
				}
				else
				{
					printf
						("Ha! You have failed to counter the attack. I feel sorry for you.\n\n");
					ply2Life -= 3;
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
			printf("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply1weapon == 3 && ply2shield == 2)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply1Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 2 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 2 Successfully counter the spell!.\n\n");
						ply1Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply2Life -= 2;
						ply1Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, choose a number: ");
				scanf("%i", &input);
				if (input == rr)
				{
					printf("Hmm, almost! But nah. 1 damage point.\n\n");
					ply2Life--;
				}
				else
				{
					printf("Whoa! So good. 3 damage points for you!\n\n");
					ply2Life -= 3;
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
				("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply1weapon == 3 && ply2shield == 3)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply1Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 2 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 2 Successfully counter the spell!.\n\n");
						ply1Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply2Life -= 2;
						ply1Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, choose a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf("Nice! No damage point for you nigga.\n\n");
				else
				{
					printf
						("Awh. Better luck nikstym! 3 damage points deducted.\n\n");
					ply2Life -= 3;
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
			printf("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}

		// player 2 attacking player 1

		printf("\nPlayer 2 now attacks Player 1.\n");

		// weapon: wooden spear w/ diff. shields
		if (ply2weapon == 1 && ply1shield == 1)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply2Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 1 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 1 Successfully counter the spell!.\n\n");
						ply2Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply1Life -= 2;
						ply2Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, enter a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf("Boom. You repelled the attack of player 2!\n\n");
				else
				{
					printf("Uh oh. You were hit! One damage point reduced.\n\n");
					ply1Life--;
				}
			}

			// manna

			if (ply2Manna == 9)
				ply2Manna += 1;
			else if (ply2Manna < 9)
				ply2Manna += 2;
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf
				("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply2weapon == 1 && ply1shield == 2)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply2Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 1 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 1 Successfully counter the spell!.\n\n");
						ply2Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply1Life -= 2;
						ply2Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, enter a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf
						("Con-grat-ula-tions! You've successfully repelled the attack!\n\n");
				else
				{
					printf
						("Naaaah. You got hit! One damage point deducted.\n\n");
					ply1Life--;
				}
			}

			// manna

			if (ply2Manna == 9)
				ply2Manna += 1;
			else if (ply2Manna < 9)
				ply2Manna += 2;
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf
				("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply2weapon == 1 && ply1shield == 3)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply2Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 1 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 1 Successfully counter the spell!\n\n");
						ply2Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply1Life -= 2;
						ply2Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, enter a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf
						("You go girl! Uh.. boy? Uhh. Yeah. No damage point deducted.\n\n");
				else
				{
					printf
						("Mississippi! You were hit! One damage point lose.\n\n");
					ply1Life--;
				}
			}

			// manna

			if (ply2Manna == 9)
				ply2Manna += 1;
			else if (ply2Manna < 9)
				ply2Manna += 2;
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}

		// weapon: silver ax w/ diff. shields

		else if (ply2weapon == 2 && ply1shield == 1)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply2Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 1 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 1 Successfully counter the spell!.\n\n");
						ply2Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply1Life -= 2;
						ply2Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, pick a number: ");
				scanf("%i", &input);
				if (input == rr)
				{
					printf
						("You have repelled the attack but.. the force is not with you.\n1 damage point happened.\n\n");
					ply1Life--;
				}
				else
				{
					printf
						("Oh no! I've wished that May the force be with you..\nBut no. You failed to counter the attack. 2 damage points happened.\n\n");
					ply1Life -= 2;
				}
			}

			// manna

			if (ply2Manna == 9)
				ply2Manna += 1;
			else if (ply2Manna < 9)
				ply2Manna += 2;
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf
				("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply2weapon == 2 && ply1shield == 2)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply2Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 1 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 1 Successfully counter the spell!.\n\n");
						ply2Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply1Life -= 2;
						ply2Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, pick a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf
						("I told you not to fall in love with me. No damage point! hashtag veegah.\n\n");
				else
				{
					printf
						("Oh man. You still failed to shield. 2 damage points deducted and RIP grammar.\n\n");
					ply1Life -= 2;
				}
			}

			// manna

			if (ply2Manna == 9)
				ply2Manna += 1;
			else if (ply2Manna < 9)
				ply2Manna += 2;
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf
				("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply2weapon == 2 && ply1shield == 3)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply2Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 1 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 1 Successfully counter the spell!\n\n");
						ply2Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply1Life -= 2;
						ply2Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, pick a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf("Ba-nana! No damage points deducted.\n\n");
				else
				{
					printf
						("Oops! I did it again. 2 damage points deducted from you.\n\n");
					ply1Life -= 2;
				}
			}

			if (ply2Manna == 9)
				ply2Manna += 1;
			else if (ply2Manna < 9)
				ply2Manna += 2;
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf
				("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}

		// weapon: diamond scythe w/ diff. shields

		else if (ply2weapon == 3 && ply1shield == 1)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1." );
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply2Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 1 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 1 Successfully counter the spell!.\n\n");
						ply2Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply1Life -= 2;
						ply2Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, choose a number: ");
				scanf("%i", &input);
				if (input == rr)
				{
					printf
						("Good shield! But.. not good enough. 2 damage points happened.\n\n");
					ply1Life -= 2;
				}
				else
				{
					printf
						("Ha! You have failed to counter the attack. Pa-pizza ka naman!\n\n");
					ply1Life -= 3;
				}
			}

			// manna

			if (ply2Manna == 9)
				ply2Manna += 1;
			else if (ply2Manna < 9)
				ply2Manna += 2;
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf
				("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply2weapon == 3 && ply1shield == 2)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply2Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 1 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 1 Successfully counter the spell!\n\n");
						ply2Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply1Life -= 2;
						ply2Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, choose a number: ");
				scanf("%i", &input);
				if (input == rr)
				{
					printf("1 damage point.\n\n");
					ply1Life--;
				}
				else
				{
					printf("Ikot-ikot lang. 3 damage points for you!\n\n");
					ply1Life -= 3;
				}
			}

			// manna

			if (ply2Manna == 9)
				ply2Manna += 1;
			else if (ply2Manna < 9)
				ply2Manna += 2;
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf
				("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}
		else if (ply2weapon == 3 && ply1shield == 3)
		{

			// casting a spell
			printf("Want to cast a spell? If yes, press 1. ");
			scanf("%c", &ch);
			if (ch == '1')
			{
				if (ply2Manna >= 6)
				{
					printf("\n\n\nKiss of the Jade smoke activated. . .\n\n");
					printf("Player 1 countering the spell. . .\n\n");
					rg = rand() % 20 + 1;
					if (rg > 10)
					{
						printf("Player 1 Successfully counter the spell!\n\n");
						ply2Manna -= 6;
					}
					else if (rg < 10)
					{
						printf("Failed to counter the spell.\n\n");
						ply1Life -= 2;
						ply2Manna -= 6;
					}
				}
				else
					printf
						("Unable to cast a spell. Required of 6 manna points.\n\n");
			}
			else if (ch != '1')
			{
				rr = rand() % 3 + 1;
				printf("From 1-3, choose a number: ");
				scanf("%i", &input);
				if (input == rr)
					printf
						("Roses are red, Violets are blue. Luckily, No damage point for you.\n\n");
				else
				{
					printf
						("I think that I shall never see, a grade that is lovely as a three.\n3 damage points deducted!\n\n");
					ply1Life -= 3;
				}
			}

			// manna

			if (ply2Manna == 9)
				ply2Manna += 1;
			else if (ply2Manna < 9)
				ply2Manna += 2;
			printf("\n\n\n");
			system("pause");
			system("cls");
			printf
				("Current status for Player 1: Life = %i\nManna = %i\nCurrent status for Player 2: Life = %i\nManna = %i\n\n\n",
				 ply1Life, ply1Manna, ply2Life, ply2Manna);

		}

	}

	return 0;
}
