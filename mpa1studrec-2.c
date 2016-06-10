#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  char studnum[10];
  char lname[15];
  char fname[20];
  char mname[15];
  char prg[10];
  int yr;
  int age;
  char gen;
  char fgr[4];
}studtype;

void enroll(studtype s[], int);
void drop(studtype s[], char r[]);
void display(studtype s[]);
void search(studtype*);

int main() {
  studtype stud[5];
  studtype st;
  int ch;
	int i;
  char st[10];
  do {
    system("CLS");
    do {
      printf("M E N U\n\n\n1 - Enroll a student\n\n2 - Drop a student\n\n3 - Display all students\n\n4 - Search by Family Name\n\n5 - Exit\n\n\nChoice: ");
      scanf("%d", &ch);
      fflush(stdin);
      if(ch > 5 || ch < 0) {
        system("CLS");
      }
    }while(ch > 5 || ch < 0);
    system("CLS");
	  i = 0;
    switch(ch) {
      case 1: while(i < 5) {
        				if(stud[i].yr > 0 && stud[i].yr < 5)
        					i++;
        				else
        					break;
      			  }
      			  enroll(stud, i); break;
      case 2: printf("DROP FORM\n\n\n");
              printf("Student Number: ");
              gets(st);  fflush(stdin);
              drop(stud, st);    break;
      case 3: display(stud); break;
      case 4: search(stud);  break;
      default: exit(0);
    }
  }while(ch < 5);
  
  return 0;
}

void enroll(studtype s[], int i) {
  int j = 0;
  printf("ENROLLMENT FORM\n");
  printf("\n\nEnter student number: ");
  gets(s[i].studnum); fflush(stdin);
  printf("\nEnter first name: ");
  gets(s[i].fname); fflush(stdin);
  printf("\nEnter middle name: ");
  gets(s[i].mname); fflush(stdin);
  printf("\nEnter last name: ");
  gets(s[i].lname); fflush(stdin);
  printf("\nEnter program: ");
  gets(s[i].prg); fflush(stdin);
  printf("\nEnter year: ");
  scanf("%d", &s[i].yr);
  printf("\nEnter age: ");
  scanf("%d", &s[i].age); fflush(stdin);
  printf("\nEnter gender: ");
  scanf("%c", &s[i].gen); fflush(stdin);
  printf("\nEnter final grade: ");
  gets(s[i].fgr); fflush(stdin);
  system("CLS");
  printf("\n\n\nEnrollment successful.\n\n\n");
  system("PAUSE");
}

void display(studtype s[]) {
  int i = 0;
  printf("STUDENT RECORD");
  for(; i < 5; i++) {
    printf("\n\n\n");
    if(s[i].yr > 0 && s[i].yr < 6) {
      printf("Student Number: "); puts(s[i].studnum);
      printf("\n\nName: %s, %s %s", s[i].lname, s[i].fname, s[i].mname);
      printf("\n\nProgram & Year level: %s %d", s[i].prg, s[i].yr);
      printf("\n\nAge: %d", s[i].age);
      printf("\n\nGender: %c", s[i].gen);
      printf("\n\nFinal grade: %s", s[i].fgr);
    }else
      break;
  }
  if(!(i)) {
    printf("No students enrolled.");
  }
  printf("\n\n\n");
  system("PAUSE");
}

void drop(studtype s[], char r[]) {
  int i = 0;
  while(i < 5) {
    if(strcmpi(s[i].studnum, r)) {
      /*printf("\n\nName: %s, %s %s", s[i].lname, s[i].fname, s[i].mname);
      printf("\n\nProgram & Year level: %s %d", s[i].prg, s[i].yr);
      printf("\n\nAge: %d", s[i].age);
      printf("\n\nGender: %c", s[i].gen);
      printf("\n\nFinal grade: %s", s[i].fgr);*/
      printf("%d && %d = %d", s[i].studnum, r, strcmpi(s[i].studnum, r));
      break;
    }else
      i++;
  }
  if(i < 5) {
    s[i].yr = 0;
    printf("\n\n\nDrop successful.\n\n\n");
  }else
    printf("\n\n\nInvalid student number.\n\n\n");
  system("PAUSE");
}

void search(studtype * s){
  
}
