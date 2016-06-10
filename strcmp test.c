#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct {
	char st1[11];
	int x;
}mai;

typedef struct {
  char snum[11];
  char LN[20];
}kii;

int main() {
	/*mai y;
	int i = 0, j;
	char st2[10] = "2014-91022";
	printf("%d", strcmp(y.st1, st2));
	printf("\n");
	gets(y.st1);
	for(; i < 10; i++) {
    if(y.st1[i] != st2[i])
      break;
	}
	if(i < 10)
    j = 0;
  else
    j = 1;
	printf("\n%d", j);*/

	kii s;
	scanf("%s", &s.snum); fflush(stdin);
	printf("\n");
	gets(s.LN); fflush(stdin);
	//.snum[10]=0;
	printf("\n\n%s\n%s\n%d %d", s.snum, s.LN, sizeof(s.snum), sizeof(s.LN));
}
