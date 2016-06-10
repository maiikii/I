#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct {
  char st1[10];
  char st2[10];
  int bs;
}stype;

typedef struct {
  int num1[10];
  int num2[10];
}ntype;

ntype strExt(stype);
void addStr(stype);
void subStr(stype);

int main() {
  int ch;
  stype inp;
  
  printf("Enter 1st string: ");
  gets(inp.st1);
  printf("\nEnter 2nd string: ");
  gets(inp.st2);
  printf("\nEnter base: ");
  scanf("%d", &inp.bs);
  printf("\n\n\n(1) Addition\t(0) Subtraction\n\nChoice: ");
  scanf("%d", &ch);
  fflush(stdin);
  
  if(ch) {
    addStr(inp);
  }else {
    subStr(inp);
  }
  printf(" base %d\n\n", inp.bs);
  return 0;
}

void addStr(stype inp) {
  int ans[10];
  int temp;
  int rem = 0;
  int i = 0;
  int num1;
  int num2;
  int len1 = strlen(inp.st1) - 1;
  int len2 = strlen(inp.st2) - 1;
  ntype x = strExt(inp);
  
  while(len1 >= 0 || len2 >= 0) {
    num1 = len1 < 0 ? 0 : x.num1[len1];
    num2 = len2 < 0 ? 0 : x.num2[len2];
    
    temp = ( num1 + num2 + rem ) % inp.bs;
    rem = ( num1 + num2 + rem ) / inp.bs;
    
    //printf("\n%d + %d = %d r %d", num1, num2, temp, rem);
    
    if(temp > 9) {
      ans[i] = (temp - 10) + '0' + ('A' - '0');
    }else {
      ans[i] = temp + '0';
    }
    i++;
    len1--;
    len2--;
  }
  
  if(rem) {
    ans[i++] = 1 + '0';
  }
  printf("\n\n\n%s + %s = ", inp.st1, inp.st2);
  i--;
  while(i >= 0) {
    printf("%c", ans[i]);
    i--;
  }
}

void subStr(stype inp) {
  int ans[10];
  int temp;
  int i = 0;
  int ctr;
  int num2;
  int len1 = strlen(inp.st1) - 1;
  int len2 = strlen(inp.st2) - 1;
  ntype x = strExt(inp);
  
  while(len1 >= 0 || len2 >= 0) {
    num2 = len2 < 0 ? 0 : x.num2[len2];
    
    if(x.num1[len1] < num2){
      ctr = len1 - 1;
      while(x.num1[ctr] < 1) {
        ctr--;
      }
      temp = ( (x.num1[len1] + inp.bs) - num2 ) % inp.bs;
      x.num1[ctr] -= 1;
      ctr += 1;
      while(ctr < len1) {
        x.num1[ctr] = x.num1[ctr] + inp.bs - 1;
        ctr++;
      }
    }else{
      temp = ( (x.num1[len1] ) - num2 ) % inp.bs;
    }
    
    //printf("\n%d - %d = %d\t", x.num1[len1], num2, temp);     
    
    if(temp > 9) {
      ans[i] = (temp - 10) + '0' + ('A' - '0');
    }else {
      ans[i] = temp + '0';
    }
    i++;
    len1--;
    len2--;
  }
  printf("\n\n\n%s - %s = ", inp.st1, inp.st2);
  i--;
  while(i >= 0) {
    printf("%c", ans[i]);
    i--;
  }
}

ntype strExt(stype inp) {
  int i;
  ntype ret;
  for(i = 0; inp.st1[i] != 0; i++) {
      if(inp.st1[i] >= 'A') {
         ret.num1[i] = inp.st1[i] - ('A' - 10);
      }else {
        ret.num1[i] = inp.st1[i] - '0';
      }
  }
  for(i = 0; inp.st2[i] != 0; i++) {
      if(inp.st2[i] >= 'A') {
         ret.num2[i] = inp.st2[i] - ('A' - 10);
      }else {
        ret.num2[i] = inp.st2[i] - '0';
      }
  }
  
  return ret;
}
