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

void enroll(studtype[], studtype, int);
void drop(studtype[], studtype);
void display(studtype[]);
void search(studtype[], char[]);

int main() {
  studtype studrec[5];
  studtype s;
  int ch;
	int i;
	char ln[15];
	
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
        				if(studrec[i].yr > 0 && studrec[i].yr < 5)
        					i++;
        				else
        					break;
      			  }
      			  printf("ENROLLMENT FORM\n\n\n");
						  printf("Student Number: ");
              gets(s.studnum);  fflush(stdin);
              printf("\nFamily Name: ");
						  gets(s.lname); fflush(stdin);
						  printf("\nFirst Name: ");
						  gets(s.fname); fflush(stdin);
						  printf("\nMiddle Name: ");
						  gets(s.mname); fflush(stdin);
						  printf("\nProgram: ");
						  gets(s.prg); fflush(stdin);
						  printf("\nYear Level: ");
						  scanf("%d", s.yr);
						  printf("\nAge: ");
						  scanf("%d", s.age); fflush(stdin);
						  printf("\nGender: ");
						  scanf("%c", s.gen); fflush(stdin);
						  printf("\nFinal grade: ");
              enroll(studrec, s, i);
							break;      
			case 2: printf("DROP FORM\n\n\n");
              printf("Student Number: ");
              gets(s.studnum);  fflush(stdin);
              printf("\nFamily Name: ");
						  gets(s.lname); fflush(stdin);
						  printf("\nFirst Name: ");
						  gets(s.fname); fflush(stdin);
						  printf("\nMiddle Name: ");
						  gets(s.mname); fflush(stdin);
						  printf("\nProgram: ");
						  gets(s.prg); fflush(stdin);
						  printf("\nYear Level: ");
						  printf("\nAge: ");
						  scanf("%d", s.age); fflush(stdin);
						  printf("\nGender: ");
						  scanf("%c", s.gen); fflush(stdin);
						  printf("\nFinal grade: ");
						  gets(s.fgr); fflush(stdin);
              drop(studrec, s);
							break;
		  case 3: display(studrec);
					 		break;     
		  case 4: printf("SEARCH STUDENT\n\n\n");
              printf("Family Name: ");
              gets(ln); fflush(stdin);
              search(studrec, ln);
							break;
		  default: exit(0);
    }
  }while(ch < 5);
  
  return 0;
}

void enroll(studtype sr[], studtype s, int  i) {
  if(i < 5) {
  	sr[i] = s;
  	printf("\n\n\nEnrollment successful.\n\n\n");
  }else {
  	printf("\n\n\nReached maximum number of enrollees.\nEnrollment unsuccessful.\n\n\n");
  }
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

void drop(studtype sr[], studtype s) {
	int i;
	for(; i < 5; i++) {
		if(strcmp(sr[i].studnum, s.studnum)) {
			break;
		}
	}
  if(i > 4) {
  	printf("\n\n\nStudent data not found. Drop unsuccessful.\n\n\n");
  } else {
  	sr[i].yr = 0;
		printf("\n\n\nDrop successful.\n\n\n");
  }
  system("PAUSE");
}

void search(studtype s[], char r[]){
  int i = 0, j;
  for(; i < 5; i++) {
    if(strcmp(s[i].lname, r)) {
    	break;
    }
  }
  if(i < 5) {
  	printf("Student Number: %s", s[i].studnum);
    printf("\n\nName: %s, %s %s", s[i].lname, s[i].fname, s[i].mname);
    printf("\n\nProgram & Year level: %s %d", s[i].prg, s[i].yr);
    printf("\n\nAge: %d", s[i].age);
    printf("\n\nGender: %c", s[i].gen);
    printf("\n\nFinal grade: %s\n\n\n", s[i].fgr);
  }else {
    printf("\n\n\nStudent not found.\n\n\n");
  }
  system("PAUSE");
}
