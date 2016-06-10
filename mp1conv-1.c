#include<stdio.h>
#include<conio.h>

int convert(int, int);

int main() {
  int dc;
  int bs;
  char cnv[10];
  
  printf("Enter number: ");
  scanf("%d", &dc);
  printf("\nEnter base: ");
  scanf("%d", &bs);

  printf("\n\n%d to base %d is ", dc, bs);
  convert(dc, bs);
  
  return 0;
}

int convert(int x, int y) {
  if(x > 0){
    return convert(x / y, y);
    if(x % y > 9) {
      printf("%c", (char)(x % y) + 55);
    }else {
      printf("%c", (char)(x % y));
    }
  }
}
