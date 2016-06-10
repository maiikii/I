#include<stdio.h>
#include<conio.h>

void dispTwoD(char A[][3]);
int chkLines(int ply[][3]);

int main() {
  char A[3][3] = { "---", "---", "---" };
  int plyinp[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
  int plyf = 1;
  int pt = 1;
  int i;
  int j;
  int line;
  
  while(plyf) {
    dispTwoD(A);
    if(pt) {
      printf("\n\n\n\n\tPlayer X Turn\n\n\tEnter coordinates: ");
      scanf("%d %d", &i, &j);
      A[i][j] = 'X';
      plyinp[i][j] = 1;
      pt = 0;
    }else {
      printf("\n\n\n\n\tPlayer O Turn\n\n\tEnter coordinates: ");
      scanf("%d %d", &i, &j);
      A[i][j] = 'O';
      plyinp[i][j] = 2;
      pt = 1;
    }
    printf("\n\n\t");
    system("PAUSE");
    system("CLS");
    line = chkLines(plyinp);
    if(line) {
      plyf = 0;
    }
  }
  dispTwoD(A);
  if(line == 1) {
    printf("\n\n\n\t    PLAYER X WINS!");
  }else if(line == 2) {
    printf("\n\n\n\t    PLAYER O WINS!");
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
  printf("\n");
  for(m = 0; m < 3; m++) {
    printf("\n\n\n\t%d\t", m);
    for(n = 0; n < 3; n++) {
      printf("%c\t", A[m][n]);
    }
  }
}

int chkLines(int ply[][3]){
  int i = 0;
  int j;
  int cf = 1;
  int p1f;
  int p2f;
  
  for(; i < 3; i++) {
    //horizontal
    p1f = 1;
    p2f = 1;
    for(j = 0; j < 3; j++) {
      if(ply[i][j] != 1) {
        p1f = 0;
      }
      if(ply[i][j] != 2) {
        p2f = 0;
      }
    }
    if(p1f || p2f) {
      break;
    }
    //vertical
    p1f = 1;
    p2f = 1;
    for(j = 0; j <3; j++) {
      if(ply[j][i] != 1) {
        p1f = 0;
      }
      if(ply[j][i] != 2) {
        p2f = 0;
      }
    }
    if(p1f || p2f) {
      break;
    }
    //diagonal
    p1f = 1;
    p2f = 1;
    for(j = 0; j <3; j++) {
      if(ply[j][j] != 1) {
        p1f = 0;
      }
      if(ply[j][j] != 2) {
        p2f = 0;
      }
    }
    if(p1f || p2f) {
      break;
    }
    //check game over
    for(j = 0; j < 3; j++) {
      if(ply[i][j] == 0) {
        cf = 0;
      }
    }
  }
  
  if(ply[0][2] == 1 && ply[1][1] == 1 && ply[2][0] == 1) {
    p1f = 1;
  }
  if(ply[0][2] == 2 && ply[1][1] == 2 && ply[2][0] == 2) {
    p2f = 1;
  }
  
  if(p1f) {
    return 1;
  }else if(p2f) {
    return 2;
  }else if(cf) {
    return 3;
  }else {
    return 0;
  }
}
