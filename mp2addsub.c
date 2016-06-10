#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct {
  char st1[10];
  char st2[10];
  int bs;
}stype;

typedef struct {
  int num1;
  int num2;
}ntype;

ntype strExt(stype);
int addStr(stype);
int subStr(stype);

int main() {
  int ch;
  int ans;
  stype x;
  ntype y;
  
  printf("Enter 1st string: ");
  gets(x.st1);
  printf("\nEnter 2nd string: ");
  gets(x.st2);
  printf("\nEnter base: ");
  scanf("%d", &x.bs);
  printf("\n\n\t(1) Addition\n\t(0) Subtraction\n\nChoice: ");
  scanf("%d", &ch);
  fflush(stdin);
  printf("\n\n");
  if(ch) {
    ans = addStr(x);
  }else {
    ans = subStr(x);
  }
  printf("\n\n\n%d", ans);
  
  return 0;
}

int addStr(stype inp) {
  int ret = 0;
  int temp;
  int chk;
  int tms = 1;
  ntype x = strExt(inp);
  
  while(x.num1 > 0 || x.num2 > 0) {
    temp = (x.num1 % 10) + (x.num2 % 10);
    
    printf("%d + %d = %d\t", x.num1%10, x.num1%10, temp);
    
    if(temp >= inp.bs) {
      chk = temp - inp.bs;
      temp = 0;
      while(chk > 0) {
        temp = temp + 1;
        chk --;
      }
    }
    
    ret = ret * 10 + temp;
    x.num1 /= 10;
    x.num2 /= 10;
    
    printf("%d\n", ret);
  }
  
  temp = ret;
  ret = 0;
  while(temp > 0){
    ret = ret * 10 + (temp % 10);
    temp /= 10;
    printf("%d ", ret);
  }
  
  return ret;
}

int subStr(stype inp) {
  int ret = 0;
  int temp;
  int chk;
  ntype x = strExt(inp);
  
  while(x.num1 > 0 && x.num2 > 0) {
    temp = (x.num1 % 10) - (x.num2 % 10);
    
    printf("%d - %d = %d\t", x.num1%10, x.num1%10, temp);
    
    while(temp < (inp.bs * -1) + 1) {
      chk = temp + inp.bs;
      temp = 0;
      while(chk < 0) {
        temp = temp + 1;
        chk ++;
      }
    }
    
    ret = ret * 10 + temp;
    x.num1 /= 10;
    x.num2 /= 10;
    
    printf("%d\n", ret);
  }
  
  return ret;
}

ntype strExt(stype inp) {
  int i;
  ntype ret;
  ret.num1 = 0;
  ret.num2 = 0;
  
  for(i = 0; inp.st1[i] != 0; i ++) {
      ret.num1 = ret.num1 * 10 + (inp.st1[i] - '0');
  }
  for(i = 0; inp.st2[i] != 0; i ++) {
      ret.num2 = ret.num2 * 10 + (inp.st2[i] - '0');
  }
  
  //printf("%d %d\n", ret.num1, ret.num2);
  
  return ret;
}
