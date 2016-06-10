#include<stdio.h>
#include<conio.h>

int main() {
  char A[3][3];
  char p1, p2;
  int p1f = 1;
  int p2f = 0;
  int df = 1;
  int i = 0;
  int j;
  int m;
  int n;
  
  for(; i < 3; i++) {
    
    if(i) {
      if(p1f) {
        printf("Player 1's Turn\n\n\t");
      }else{
        printf("Player 2's Turn\n\n\t");
      }
      for(m = 0; m < i; m++) {
        for(n = 0; n < 3; n++) {
          printf("%c\t", A[m][n]);
        }
        printf("\n\t");
      }
      df = 0;
    }
    
    for(j = 0; j < 3; j++){
      if(p1f && df) {
        printf("Player 1's Turn\n\n\t");
      }else{
        printf("Player 2's Turn\n\n\t");
      }
      
      if(p1f) {
        scanf("%c", A[i][j]);
        printf("%c\t", A[i][j]);
        p1f = 0;
        p2f = 1;
      }else {
        printf("Player 2's Turn\n\n\t");
        scanf("%c", A[i][j]);
        printf("%c\t", A[i][j]);
        p1f = 1;
        p2f = 0;
      }
      df = 1;
      system("CLS");
    }
  }
  
  return 0;
}
