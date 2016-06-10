#include<stdio.h>
#include<conio.h>

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

void getData(studtype*);
void enroll(studtype*);
void drop(studtype*);
void display(studtype s[]);
void search(studtype*);

int main() {
  studtype stud[5];
  int ch, i;
  do {
    system("CLS");
    do {
      printf("MENU\n1 - Enroll a student\n2 - Drop a student\n3 - Display all students\n4 - Search by Family Name\n5 - Exit\n\nChoice: ");
      scanf("%d", &ch);
      fflush(stdin);
      if(ch > 5 || ch < 0) {
        system("CLS");
      }
    }while(ch > 5 || ch < 0);
  
    system("CLS");
    switch(ch) {
      case 1: enroll(stud);  break;
      case 2: drop(stud);    break;
      case 3: display(stud); break;
      case 4: search(stud);  break;
      default: exit(0);
    }
  }while(ch < 5);
  
  return 0;
}

void enroll(studtype * s) {
  printf("\nEnter student number: ");
  gets(s->studnum); fflush(stdin);
  printf("\nEnter first name: ");
  gets(s->fname); fflush(stdin);
  printf("\nEnter middle name: ");
  gets(s->mname); fflush(stdin);
  printf("\nEnter last name: ");
  gets(s->lname); fflush(stdin);
  printf("\nEnter program: ");
  gets(s->prg); fflush(stdin);
  printf("\nEnter year: ");
  scanf("%d", &s->yr);
  printf("\nEnter age: ");
  scanf("%d", &s->age); fflush(stdin);
  printf("\nEnter gender: ");
  scanf("%c", &s->gen); fflush(stdin);
  printf("\nEnter final grade: ");
  gets(s->fgr); fflush(stdin);
  system("CLS");
  printf("\n\nEnrollment successful.\n\n\n");
  system("PAUSE");
}

void display(studtype s[]) {
  int i = 0;
  printf("STUDENT RECORD\n\n\n");
  for(; i < 5; i++) {
    if(s[i].yr > 0 && s[i].yr < 6) {
      printf("\n\nStudent Number: %s", s[i].studnum);
      printf("\nName: %s, %s %s", s[i].lname, s[i].fname, s[i].mname);
      printf("\nProgram & Year level: %s %d", s[i].prg, s[i].yr);
      printf("\nAge: %d", s[i].age);
      printf("\nGender: %c", s[i].gen);
      printf("\nFinal grade: %s", s[i].fgr);
    }
  }
  printf("\n\n\n");
  system("PAUSE");
}

