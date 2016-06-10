#include <stdio.h>
#include <conio.h>

int sumdig(int);
int checkPlndrm(int);

int main() {

  int x = sumdig(1234);
  int y;
  int z;

  //printf("%d\n", x);
  printf("Enter number: ");
  scanf("%d", &y);
  z = checkPlndrm(y);

  if (z) {
    printf("\n\nPalindrome");
  }else {
    printf("\n\nNot Palindrome");
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

  if (n < 10) {
    return 1;
  }else if (n < 100) {
    if (n % 10 == n / 10){
      return 1;
    }else {
      return 0;
    }
  }
  
  if (n > 0){
    while ( temp > 1) {
      temp = temp / 10;
      mod = mod * 10;
      if ( temp / 10 == 0) {
        break;
      }
    }
    if(n % 10 > -1 || temp > -1) {
      if (n % 10 == temp) {
        printf("%d %d %d %d %d %d\n", n%10, temp, mod, (n%mod)/10, ((n%mod)/10)/(mod/10), (n % (mod / 1000)) / 10);
        //if((n % mod) / 10) / (mod / 10) == (n % mod) / 10) % 10){
        //  return checkPlndrm( (n % mod/10) / 10);
        //}
        return checkPlndrm( (n % mod) / 10);
      }else {
        return 0;
      }
    }else {
      return 0;
    }
  }else{
    return 1;
  }
}

