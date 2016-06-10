#include<stdio.h>
#include<conio.h>

int * convert(int, int);

int main() {
  int dc;
  int bs;
  int ans[10];
  int * ptr = ans;
  
  printf("Enter number: ");
  scanf("%d", &dc);
  printf("\nEnter base: ");
  scanf("%d", &bs);
  
  ptr = convert(dc, bs);
  printf("\n\n%d base 10 to base %d is %s", dc, bs, *ptr);
  
  return 0;
}

int * convert(int n, int b) {
  int ans[10];
  int i;
  int temp = 0;
  int rem;
  int tms = 1;
  int * iptr = ans;
  
  if(b < 11) {
    while(n > 0) {
      rem = n % b;
      n /= b;
      temp = temp + (rem * tms);
      tms *= 10;
    }
    for(i = 9; i > 0; i++){
      ans[i] = temp % 10 + '0';
      temp /= 10;
    }
  }else{
    while(n > 0) {
      rem = n % b;
      n /= b;
      if(rem > 9) {
        ans[i] = (rem - 10) + '0' + ('A' - '0');
      }else {
        ans[i] = rem + '0';
      }
      i++;
    }
  }
  return iptr;

}
