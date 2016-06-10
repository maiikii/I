#include<stdio.h>
#include<conio.h>

void dispTwoD(char A[][3]);
int chkLines(char p1[][3], char p2[][3]);

int main() {
  char A[3][3] = { "---", "---", "---" };
  char p1a[3][3];
  char p2a[3][3];
  char p1c;
  char p2c;
  int plyf = 1;
  int pt = 1;
  int i;
  int j;
  int line;
  
  while(plyf) {
    dispTwoD(A);
    if(pt) {
      printf("\n\n\n\nPlayer 1's Turn\n\nEnter row: ");
      scanf("%d", &i);
      printf("\nEnter column: ");
      scanf("%d", &j);
      fflush(stdin);
      printf("\nEnter move: ");
      scanf("%c", &p1c);
      A[i][j] = p1c;
      p1a[i][j] = p1c;
      pt = 0;
    }else {
      printf("\n\n\n\nPlayer 2's Turn\n\nEnter row: ");
      scanf("%d", &i);
      printf("\nEnter column: ");
      scanf("%d", &j);
      fflush(stdin);
      printf("\nEnter move: ");
      scanf("%c", &p2c);
      A[i][j] = p2c;
      p2a[i][j] = p2c;
      pt = 1;
    }
    printf("\n\n");
    system("PAUSE");
    system("CLS");
    line = chkLines(p1a, p2a);
    if(line) {
      plyf = 0;
    }
  }
  dispTwoD(A);
  if(line == 1) {
    printf("\n\n\n\t    PLAYER 1 WINS!");
  }else if(line == 2) {
    printf("\n\n\n\t    PLAYER 2 WINS!");
  }else {
    printf("\n\n\nGAME OVER!");
  }
  
  return 0;
}

void dispTwoD(char A[][3]) {
  int m = 0;
  int n;
  printf("\t  T I C - T A C - T O E\n\n\n\t");
  while(m < 3) {
    printf("\t%d", m);
    m++;
  }
  for(m = 0; m < 3; m++) {
    printf("\n\n\n\t%d\t", m);
    for(n = 0; n < 3; n++) {
      printf("%c\t", A[m][n]);
    }
  }
}

int chkLines(char p1[][3], char p2[][3]){
  int i = 0;
  int j;
  int p1f;
  int p2f;
  
  for(; i < 3; i++) {
    //horizontal
    j = 0;
    if(p1[i][j] == p1[i][++j] && p1[i][j] == p1[i][++j]) {
      p1f = 1;
    }else {
      p1f = 0;
    }
    if(p2[i][j] == p2[i][++j] && p2[i][j] == p2[i][++j]) {
      p2f = 1;
    }else {
      p2f = 0;
    }
    //vertical
    j = 0;
    if(p1[j][i] == 'X' && p1[j+1][i] == 'X' && p1[j+2][i] == 'X') {
      p1f = 1;
    }else {
      p1f = 0;
    }
    if(p2[j][i] == 'O' && p2[j+1][i] == 'O' && p2[j+2][i] == 'O') {
      p2f = 1;
    }else {
      p2f = 0;
    }
    //diagonal
    if(p1[i][i] == 'X' && p1[i+1][i+1] == 'X' && p1[i+2][i+2] == 'X') {
      p1f = 1;
    }else {
      p1f = 0;
    }
    
    if(p1f || p2f) {
      break;
    }
  }
   if(p1f) {
     return 1;
   }else if(p2f) {
     return 2;
   }else {
     return 0;
   }
}
