#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void intToWords(int);
void intToRom(int);
void romToInt(char[]);
int chkRom(char[]);
void t1(int);
void t2(int);
void t3(int);
void t4(int);
void t5(int);
void ones(int);
void twos(int);
void tens(int,int);

int main(void) {
	int ch, num, fl;
	char rom[10];
	do{
	  system("CLS");
		printf("MENU\n\n1 - Integer to Words\n2 - Integer to Roman\n3 - Roman to Integer\n4 - Exit\n\nChoice: ");
		scanf("%d", &ch); fflush(stdin);
		system("CLS");
		switch(ch) {
    case 1:   printf("\nEnter number: ");
              scanf("%d", &num);  fflush(stdin);
              intToWords(num);
              break;
			case 2: do {
                system("CLS");
                printf("\nEnter number: ");
                scanf("%d", &num);  fflush(stdin);
                if(num < 0 || num > 3000) {
                  printf("\n\nInvalid input. Press any key to reenter.");
                  getch();
                }
              }while(num < 0 || num > 3000);
              intToRom(num);
              break;
			case 3: do {
                system("CLS");
                printf("\nEnter roman: ");
                gets(rom);	fflush(stdin);
                fl = chkRom(rom);
                if(fl) {
                  printf("\n\nInvalid input. Press any key to reenter.");
                  getch();
                }
              }while(fl);
              romToInt(rom);
              break;
			default: exit(0);
		}
	}while(ch > 0 && ch < 4);
}

void intToRom(int n) {
  int a, b, c;
  printf("\n\nInteger: %d\n\nRoman Numeral: ", n);
  while(n/1000 > 0) {
    n-=1000;  printf("M");
  }
  a=b=c=1;
  while(n/100 > 0) {
    if(n/100==5 && a) {
      printf("D");  n-=500;
      break;
    }else a=0;
    if(n/100 > 5) {
      printf("D");  n-=500;
      while(n/100 > 1){
        printf("C");  n-=100;
      }
    }
    printf("C");
    if(n/100==9 && b) {
      printf("M");  n-=900;
      break;
    }else b=0;
    if(n/100==4 && c){
      printf("D");  n-=400;
      break;
    }else c=0;
    n-=100;
  }
  a=b=c=1;
  while(n/10 > 0) {
    if(n/10==5 && a) {
      printf("L"); n-=50;
      break;
    }else a=0;
    if(n/10>5) {
      printf("L");  n-=50;
      while(n/10>1) {
        printf("X");  n-=10;
      }
    }
    printf("X");
    if(n/10==9 && b) {
      printf("C"); n-=90;
      break;
    }else b=0;
    if(n/10==4 && c){
      printf("L"); n-=40;
      break;
    }else c=0;
    n-=10;
  }
  a=b=c=1;
  while(n > 0) {
    if(n==5 && a) {
      printf("V"); n-=5;
      break;
    }else a=0;
    if(n>5) {
      printf("V"); n-=5;
      while(n>1) {
        printf("I"); n-=1;
      }
    }
    printf("I");
    if(n==9 && b) {
      printf("X"); n-=9;
      break;
    }else b=0;
    if(n==4 && c){
      printf("V"); n-=4;
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
    num+=1000; i++;
  }
  if(r[i]=='D') {
    num+=500; i++;
  }
  while(r[i]=='C') {
    num+=100;
    if(r[i+1]=='M') {
      num+=800; i++;
      break;
    }
    if(r[i+1]=='D') {
      num+=300; i++;
      break;
    }
    i++;
  }
  if(r[i]=='L') {
    num+=50; i++;
  }
  while(r[i]=='X') {
    num+=10;
    if(r[i+1]=='C') {
      num+=80;  i++;
      break;
    }
    if(r[i+1]=='L') {
      num+=30;  i++;
      break;
    }
    i++;
  }
  if(r[i]=='V') {
    num+=5; i++;
  }
  while(r[i]=='I') {
    num+=1;
    if(r[i+1]=='X') {
      num+=8; i++;
      break;
    }
    if(r[i+1]=='V') {
      num+=3; i++;
      break;
    }
    i++;
  }
  printf("\n\nRoman Numeral: %s\n\nInteger: %d\n\n\n", r, num);
  system("PAUSE");
}

int chkRom(char r[]) {
  int m, d, c, l, x, v, i, j, len=strlen(r);
  m=d=c=l=x=v=i=j=0;
  for(; r[j]!=0; j++) {
    if(r[j]=='M') m++;
    else m=0;
    if(m >= 3 && len > 3)
      return 1;
  }
  for(j=0; r[j] != 0; j++)
    if(!(r[j]=='M'||r[j]=='D'||r[j]=='C'||r[j]=='L'||r[j]=='X'||r[j]=='V'||r[j]=='I'))
      return 1;
  for(j=0; r[j]!=0; j++) {
    if(r[j]=='D') d++;
    else  d=0;
    if(r[j]=='L') l++;
    else  l=0;
    if(r[j]=='V') v++;
    else  v=0;
    if(d>=2 || l>=2 || v>=2) return 1;
  }
  for(j=0; r[j]!=0; j++) {
    if(r[j]=='C') c++;
    else c=0;
    if(r[j]=='X') x++;
    else  x=0;
    if(r[j]=='I') i++;
    else  i=0;
    if(c>=4 || x>=4 || i>=4)  return 1;
  }
  return 0;
}

void intToWords(int n) {
	printf("\n\nInteger: %d\n\nWords: ", n);
	if(n == 0) printf("Zero");
	if(n < 0) {
    printf("Negative ");
    n*=-1;
	}
	if(n < 100 && n != 0)  t1(n);
  if(n >= 100 && n < 1000) t2(n);
  if(n >= 1000 && n < 1000000)  t3(n);
  if(n >= 1000000 && n < 1000000000)  t4(n);
  if(n >= 1000000000 && n <= 2147483647)  t5(n);
  printf("\n\n\n");
  system("PAUSE");
}

void t1(int n) {
  if(n <= 10) ones(n);
  if(n > 10 && n < 20) twos(n%10);
  if(n >= 20 && n < 100) tens(n/10, n%10);
}

void t2(int n) {
  ones(n/100);
  printf(" Hundred ");
  t1(n%100);
}

void t3(int n) {
  if(n >= 100000) {
    ones(n/100000);
    printf(" Hundred ");
    n%=100000;
  }
  if(n >= 20000) {
    tens(n/10000, n%10000);
    n%=10000;
  }
  if(n >= 10000) {
    twos(n/10000);
    n%=10000;
  }
  else if(n >= 1000) {
    ones(n/1000);
    n%=1000;
  }
  printf(" Thousand ");
  if(n < 1000) t2(n);
}

void t4(int n) {
  if(n >= 100000000) {
    ones(n/100000000);
    printf(" Hundred ");
    n%=100000000;
  }
  if(n >= 20000000) {
    tens(n/10000000, n%10000000);
    n%=10000000;
  }
  if(n >= 10000000) {
    twos(n/10000000);
    n%=10000000;
  }
  else if(n >= 1000000) {
    ones(n/1000000);
    n%=1000000;
  }
  printf(" Million ");
  if(n < 1000000) t3(n);
}

void t5(int n) {
  if(n/1000000000 == 1) printf("One");
  else  printf("Two");
  printf(" Billion ");
  n%=1000000000;
  if(n < 1000000000)
    t4(n);
}

void ones(int x) {
  switch(x) {
    case 1: printf("One"); break;
    case 2: printf("Two"); break;
    case 3: printf("Three"); break;
    case 4: printf("Four"); break;
    case 5: printf("Five"); break;
    case 6: printf("Six"); break;
    case 7: printf("Seven"); break;
    case 8: printf("Eight"); break;
    case 9: printf("Nine"); break;
    default: printf("");
  }
}

void twos(int x) {
  switch(x){
    case 1: printf("Eleven");break;
    case 2: printf("Twelve");break;
    case 3: printf("Thirteen");break;
    case 4: printf("Fourteen");break;
    case 5: printf("Fifteen");break;
    case 6: printf("Sixteen");break;
    case 7: printf("Seventeen");break;
    case 8: printf("Eighteen");break;
    case 9: printf("Nineteen");break;
    default: printf("");
  }
}

void tens(int x, int y) {
  switch(x){
    case 2: printf("Twenty ");break;
    case 3: printf("Thirty ");break;
    case 4: printf("Forty ");break;
    case 5: printf("Fifty ");break;
    case 6: printf("Sixty ");break;
    case 7: printf("Seventy ");break;
    case 8: printf("Eighty ");break;
    case 9: printf("Ninety ");break;
    case 10: printf("Hundred");break;
    default: printf("");
  }
  ones(y);
}
