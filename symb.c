#include<stdio.h>
#include<conio.h>
#include<time.h>

int main(void)
{
 	char ch=4, i;
 	system("color 0c");
 	/*printf("\n\t    ************");
 	printf("\n\t   ************** RATAVA RPG");
 	printf("\n\t  *********      *");
 	printf("\n\t *********        *");
 	printf("\n\t********************");
 	printf("\n\t ******************");
 	printf("\n\t  *****	  **     *");
 	printf("\n\t   ***	   **   *");
 	printf("\n\t    ************");
 	printf("\n");
 	
	printf("\n\t      *****************");
	printf("\n\t     *******************");
  	printf("\n\t    ***************    ***");
 	printf("\n\t   **************       **");
 	printf("\n\t  **************         **");
 	printf("\n\t **************           **");
 	printf("\n\t*****************************");
 	printf("\n\t ***************************");
 	printf("\n\t  **********  ***        **");
 	printf("\n\t   ********    ***      **");
 	printf("\n\t    ******      ***    **");
 	printf("\n\t     ****        ***  **");
 	printf("\n\t      *****************");*/
 	printf("\n");
 	
 	printf("\n\n\n\n\t\t\t        ");
 	for(i=0; i<12; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	printf("\n\t\t\t       ");
 	for(i=0; i<14; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
 	printf("\n\t\t\t      ");
 	for(i=0; i<9; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	printf("     %c%c", ch,ch);
 	printf("\n\t\t\t     ");
 	for(i=0; i<9; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	printf("       %c%c\n\t\t\t    ", ch,ch);
 	for(i=0; i<20; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	printf("\n\t\t\t     ");
	for(i=0; i<18; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
 	printf("\n\t\t\t      ");
	for(i=0; i<5; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	printf("   %c%c     %c", ch,ch,ch);
 	printf("\n\t\t\t       %c%c%c	%c%c  %c", ch,ch,ch,ch,ch,ch);
 	printf("\n\t\t\t        ");
 	for(i=0; i<12; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	//1
	printf("\n\n\n\n\t\t\t      ");
 	for(i=0; i<17; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	//2
	printf("\n\t\t\t     ");
 	for(i=0; i<19; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	//3
	printf("\n\t\t\t    ");
 	for(i=0; i<21; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	//4
	printf("\n\t\t\t   ");
 	for(i=0; i<16; i++){
 		sleep(30);
 		if(i==14)
 			printf("       ");
	 	printf("%c", ch);
	}
	// 5
 	printf("\n\t\t\t  ");
 	for(i=0; i<16; i++){
 		sleep(30);
 		if(i==14)
 			printf("         ");
	 	printf("%c", ch);
	}
	// 6
 	printf("\n\t\t\t ");
 	for(i=0; i<16; i++){
 		sleep(30);
 		if(i==14)
 			printf("           ");
	 	printf("%c", ch);
	}
	// 7
	printf("\n\t\t\t");
 	for(i=0; i<29; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	// 8
	printf("\n\t\t\t ");
	for(i=0; i<27; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	//9
 	printf("\n\t\t\t  ");
	for(i=0; i<15; i++){
 		sleep(30);
 		if(i==10)
	 		printf("  ");
 		else if(i==13)
 			printf("        ");
 		printf("%c", ch);
	}
	// 10
 	printf("\n\t\t\t   ");
 	for(i=0; i<13; i++){
 		sleep(30);
 		if(i==8)
			printf("    ");
		if(i==11)
			printf("      ");
		printf("%c", ch);
	}
	// 11
 	printf("\n\t\t\t    ");
 	for(i=0; i<11; i++){
 		sleep(30);
 		if(i==6)
			printf("      ");
		if(i==9)
			printf("    ");
		printf("%c", ch);
	}
	// 12
 	printf("\n\t\t\t     ");
 	for(i=0; i<9; i++){
 		sleep(30);
 		if(i==4)
			printf("        ");
		if(i==7)
			printf("  ");
		printf("%c", ch);
	}
 	// 13
 	printf("\n\t\t\t      ");
 	for(i=0; i<17; i++){
 		sleep(30);
	 	printf("%c", ch);
	}
	system("color f4");
	sleep(100);
	printf("\n\n\t\t\t    R   A");
	system("color 0f");
	sleep(100);
	printf("   T   A");
	system("color fc");
	sleep(100);
	system("color 0c");
	printf("   V   A");
	

	
 	getch();
 	return 0;
}
