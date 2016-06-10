#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void intToWords(int);
void intToRom(int);
void romToInt(char[]);

int main(void) {
	int ch, num;
	char rom[10];
	do{
	  system("CLS");
		printf("MENU\n\n1 - Integer to Words\n2 - Integer to Roman\n3 - Roman to Integer\n4 - Exit\n\nChoice: ");
		scanf("%d", &ch); fflush(stdin);
		system("CLS");
		switch(ch) {
			case 1: printf("\nEnter number: ");
              scanf("%d", &num);  fflush(stdin);
              intToWords(num);
              break;
			case 2: do {
                system("CLS");
                printf("\nEnter number: ");
                scanf("%d", &num);  fflush(stdin);
                if(num < 0 || num > 3000) {
                  printf("\n\n%d is an invalid input\n\n\n", num);
                  system("PAUSE");
                }
              }while(num < 0 || num > 3000);
              intToRom(num);
              break;
			case 3: printf("Enter roman: ");
              gets(rom);	fflush(stdin);
              romToInt(rom);
              break;
			default: exit(0);
		}
	}while(ch> 0 && ch < 4);
}

void intToWords(int n) {
	/*char ones[][] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char twos[][] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  char tens[][] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  char more[][] = {"hundred", "thousand", "million", "billion"};
  char words[10][];

  if(n/1000000000)
		billions(n, more, &words);
	if(n/100000000)
		hmillions(n, ones, more, &words);
	if(n/10000000)
		tmillions(n, ones, twos, more &words);
	else if(n/1000000)
		millions(n, ones, &words);
	if(n/100000)
		hthousands(n, ones, twos, more, &words);
	else if(n/10000)
		tthousands(n, twos, more, &words);
	else if(n/1000) {
    words[6] = ones[n/1000]
	}*/

}

void intToRom(int n) {
  int a, b, c;
  printf("\n\nInteger: %d\nRoman Numeral: ", n);
  while(n/1000 > 0) {
    n-=1000;
    printf("M");
  }
  a=b=c=1;
  while(n/100 > 0) {
    if(n/100==5 && a) {
      printf("D");
      n-=500;
      break;
    }else a=0;
    printf("C");
    if(n/100==9 && b) {
      printf("M");
      n-=900;
      break;
    }else b=0;
    if(n/100==4 && c){
      printf("D");
      n-=400;
      break;
    }else c=0;
    n-=100;
  }
  a=b=c=1;
  while(n/10 > 0) {
    if(n/10==5 && a) {
      printf("L");
      n-=50;
      break;
    }else a=0;
    printf("X");
    if(n/10==9 && b) {
      printf("C");
      n-=90;
      break;
    }else b=0;
    if(n/10==4 && c){
      printf("L");
      n-=40;
      break;
    }else c=0;
    n-=10;
  }
  a=b=c=1;
  while(n > 0) {
    if(n==5 && a) {
      printf("V");
      n-=5;
      break;
    }else a=0;
    printf("I");
    if(n==9 && b) {
      printf("X");
      n-=9;
      break;
    }else b=0;
    if(n==4 && c){
      printf("V");
      n-=4;
      break;
    }else c=0;
    n-=1;
  }
  printf("\n\n\n");
  system("PAUSE");
}

void romToInt(char r[]) {
  int i=0, num=0;
  while(r[i]=='M') {
    num+=1000;
    i++;
  }
  if(r[i]=='D') {
    num+=500;
    i++;
  }
  while(r[i]=='C') {
    num+=100;
    if(r[++i]=='M') {
      num+=800; i++;
      break;
    }
    if(r[++i]=='M') {
      num+=300; i++;
      break;
    }
    i++;
  }
  if(r[i]=='L') {
    num+=50;
    i++;
  }
  while(r[i]=='X') {
    num+=10;
    if(r[++i]=='C') {
      num+=80;  i++;
      break;
    }
    if(r[i]=='L') {
      num+=30;  i++;
      break;
    }
    i++;
  }
  if(r[i]=='V') {
    num+=5;
    i++;
  }
  while(r[i]=='I') {
    num+=1;
    if(r[++i]=='X') {
      num+=8; i++;
      break;
    }
    if(r[i]=='V') {
      num+=3; i++;
      break;
    }
    i++;
  }
  printf("\n\nRoman Numeral: %s\nInteger: %d\n\n\n", r, num);
  system("PAUSE");
}
