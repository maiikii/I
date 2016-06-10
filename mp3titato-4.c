#include<stdio.h>
#include<conio.h>

void display(char A[][3]);
int chkLines(int ply[][3]);

int main() {
  char A[3][3] = { "   ", "   ", "   " };
  int plyinp[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
  int plyf = 1;
  int pt = 1;
  int i;
  int j;
  int line;
  
  while(plyf) {
    display(A);
    if(pt) {
      printf("\n\n\n\nPlayer X Turn\n\nEnter coordinates (R C): ");
      scanf("%d %d", &i, &j);
      A[i][j] = 'X';
      plyinp[i][j] = 1;
      pt = 0;
    }else {
      printf("\n\n\n\nPlayer O Turn\n\nEnter coordinates (R C): ");
      scanf("%d %d", &i, &j);
      A[i][j] = 'O';
      plyinp[i][j] = 2;
      pt = 1;
    }
    printf("\n\n");
    system("PAUSE");
    system("CLS");
    line = chkLines(plyinp);
    if(line) {
      plyf = 0;
    }
  }
  
  display(A);
  if(line == 1) {
    printf("\n\n\n\t  PLAYER X WINS!\n\n");
  }else if(line == 2) {
    printf("\n\n\n\t  PLAYER O WINS!\n\n");
  }else {
    printf("\n\n\n\t   GAME OVER!\n\n");
  }
  return 0;
}

void display(char table[3][3]) {
    //201 203 187 188 185 204 205 206 186
    printf("\t TIC - TAC - TOE");
    printf("\n\n\n");
    printf("\t    0   1   2\n");
    printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,203,205,205,205,203,205,205,205,187);
    printf("\t0 %c %c %c %c %c %c %c\n",186,table[0][0],186,table[0][1],186,table[0][2],186);
    printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\t1 %c %c %c %c %c %c %c\n",186,table[1][0],186,table[1][1],186,table[1][2],186);
    printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\t2 %c %c %c %c %c %c %c\n",186,table[2][0],186,table[2][1],186,table[2][2],186);
    printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,202,205,205,205,202,205,205,205,188);
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
