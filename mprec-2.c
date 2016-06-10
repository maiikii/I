#include <stdio.h>
#include <conio.h>

int sumdig(int);
int checkPlndrm(int);

int main() {

  int x = sumdig(1234);
  int y;
  int z;

  printf("Enter number: ");
  scanf("%d", &y);
  z = checkPlndrm(y);
  
  //printf("\n%d", x);
  
  if (z) {
    printf("\n\nPalindrome\n\n\n");
  }else {
    printf("\n\nNot Palindrome\n\n\n");
  }

  return 0;
}

int sumdig (int n) {
  if (n > 0) {
    return n % 10 + sumdig(n / 10);
  }else {
    return 0;
  }
}

int checkPlndrm (int n) {
  int mod = 1;
  int temp = n;
  int ctr = 1;

  if (n < 10) {
    return 1;
  }else if (n < 100) {
    if (n % 10 == n / 10){
      return 1;
    }else {
      return 0;
    }
  }
  
  if (n > 0) {
    while ( temp > 1) {
      temp = temp / 10;
      mod = mod * 10;
      ctr ++;
      if ( temp / 10 == 0) {
        break;
      }
    }
    if (n % 10 == temp) {
      printf("%d = %d\t%d\t%d\n", n%10, temp, n%mod/10);
      if(ctr % 2 == 0){
        if((n % mod / 10) == 0){
          return 1;
        }
        else if((n % mod / 10) < 10){
          return 0;
        }
      }else if(ctr % 2 > 0 && (n % mod / 10) < 100){
        return 1;
      }
      return checkPlndrm( (n % mod) / 10);
    }else {
      return 0;
    }
  }else{
    return 1;
  }
}

