#include<stdio.h>
#include<conio.h>

int toBin(int,int);

int main(){
  int x=5;
  //printf("%d\n",toBin(20,x));
  //printf("%c", x + '0' + ('A'-'0'));
  printf("%c", x + '0');
  return 0;
}
/*
int toBin(int x){
  if(x > 0){
    return toBin(x / 2);
    printf("%d", x % 2);
  }
}*/

int toBin(int n, int b){
  int rem, tms=1, ans=0;
  while(n>0){
    rem=n%b;
    n/=b;
    ans=ans+(rem*tms);
    tms*=10;
  }
  return ans;
}
