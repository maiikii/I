#include<stdio.h>
#include<conio.h>

void convert(int, int);

int main() {
  int dc;
  int bs;
  
  printf("Enter number: ");
  scanf("%d", &dc);
  printf("\nEnter base: ");
  scanf("%d", &bs);
  
  printf("\n\n%d base 10 to base %d is ", dc, bs);
  convert(dc, bs);
  
  return 0;
}

void convert(int n, int b) {
  int ans1 = 0;
  int ans2[10];
  int i = 0;
  int rem;
  int tms = 1;
  
  if(b < 11) {
    while(n > 0) {
      rem = n % b;
      //printf("%d mod %d = %d ", n, b, n % b);
      n /= b;
      ans1 = ans1 + (rem * tms);
      tms *= 10;
    }
    printf("%d", ans1);
  }else{
    while(n > 0) {
      rem = n % b;
      n /= b;
      if(rem > 9) {
        ans2[i] = (rem - 10) + '0' + ('A' - '0');
      }else {
        ans2[i] = rem + '0';
      }
      i++;
    }
    for(i -= 1; i > -1; i--){
      printf("%c", ans2[i]);
    }
  }

}
