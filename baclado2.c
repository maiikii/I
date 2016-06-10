#include<stdio.h>

int main(void)
{
	int m, d;
	printf("Enter month in number: ");
	scanf("%d", &m);
	printf("\nEnter day in number: ");
	scanf("%d", &d);
	
	do{
	{
		printf("\nEnter month in number: ");
	    scanf("%d", &m);
        printf("\nEnter day in number: ");
	    scanf("%d", &d);
		
		if(m==2 && d>29){
		printf("\nInvalid day. Enter again: ");
		scanf("%d", &d);
		}
		
		if( (m==4 || m==6 || m==9 || m==11) && d>30){
		printf("\nInvalid day. Enter again: ");
		scanf("%d", &d);
		}
	
	}while( (m<0 || m>12) || (d<0 || d>31) );
	
	
	if(m==12 && d>21 || m==1 && d<20)
		printf("\nCapricorn\nCheer Up! Things are getting worse at a slower rate.");
	else if(m==1 && d>19 || m==2 && d<19)
		printf("\nAquarius\nDon't relax! It's only your tension that's holding you together.");
	else if(m==2 && d>18 || m==3 && d<21)
		printf("\nPisces\nExcellent day to have a rotten day.");
	else if(m==3 && d>20 || m==4 && d<20)
		printf("\nAries\nIf you learn one useless thing every day, in a single year you'll learn 365 useless things.");
	else if(m==4 && d>19 || m==5 && d<21)
		printf("\nTaurus\nIn the stairway of life, you'd best take the elevator.");
	else if(m==5 && d>20 || m==6 && d<21)
		printf("\nGemini\nWrite yourself a threatening letter and pen a defiant reply.");
	else if(m==6 && d>20 || m==7 && d<23)
		printf("\nCancer\nYou are not dead yet. But watch for further reports.");
	else if(m==7 && d>22 || m==8 && d<23)
		printf("\nLeo\nYou will be attacked by a beast who has the body of a wolf, the tail of a lion, and the face of Donald Duck.");
	else if(m==8 && d>22 || m==9 && d<23)
		printf("\nVirgo\nYour lucky number is 3552664958674928. Watch for it everywhere.");
	else if(m==9 && d>22 || m==10 && d<23)
		printf("\nLibra\nTonight you will pay the wages of sin; Don't forget to leave a tip.");
	else if(m==10 && d>22 || m==11 && d<22)
		printf("\nScorpio\nIt is so very hard to be an on-your-own-take-care-of-yourself-because-there-is-no-one-else-to-do-it-for-you-grown-up.");
	else
		printf("\nSagittarius\nCaution: breathing may be hazardous to your health.");
    return 0;
}
