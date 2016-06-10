#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char stnum[11];
	char lname[15];
	char fname[20];
	char mname[20];
	char crs[15];
	int yr;
	int age;
	char gen;
	char fgr[4];
}stype;

typedef struct {
	stype stud[5];
	int size;
}ltype;

void enroll(ltype *, stype);
void drop(ltype *, char[]);
void edit(ltype *, char[]);
void dispStud(stype *);
void dispAll(ltype);
void viewYr(ltype, int);
void viewCrs(ltype, char[]);
int chkStnum(ltype *, char[]);

int main() {
	ltype srec;
	stype s;
	int ch;
	int yrl;
	char gstn[10];
	char gcrs[15];
	srec.size = 0;
	do {
		system("CLS");
		printf("MENU\n\n1 - Enroll a student\n2 - Drop a student\n3 - Edit a student record\n4 - Display all students\n5 - View students by year level\n6 - View students by course\n7 - Exit");
		printf("\n\nChoice: ");
		scanf("%d", &ch);
		fflush(stdin);
		printf("\n\n\n");
		system("PAUSE");
		system("CLS");
		switch(ch) {
			case 1: printf("ENROLLMENT FORM\n\n\n");
              printf("Student Number: ");
              gets(s.stnum);
              fflush(stdin);
              printf("\nFamily Name: ");
              gets(s.lname);
              fflush(stdin);
              printf("\nFirst Name: ");
              gets(s.fname);
              fflush(stdin);
              printf("\nMiddle Name: ");
              gets(s.mname);
              fflush(stdin);
              printf("\nCourse: ");
              gets(s.crs);
              fflush(stdin);
              printf("\nYear Level: ");
              scanf("%d", &s.yr);
              printf("\nAge: ");
              scanf("%d", &s.age);
              fflush(stdin);
              printf("\nGender: ");
              scanf("%c", &s.gen);
              fflush(stdin);
              printf("\nFinal Grade: ");
              gets(s.fgr);
              fflush(stdin);
              enroll(&srec, s);
					 		break;
			case 2: printf("\nStudent Number: ");
					 		gets(gstn);
		 					fflush(stdin);
					 		drop(&srec, gstn);
					 		break;
			case 3: printf("\nStudent Number: ");
					 		gets(gstn);
		 					fflush(stdin);
					 		edit(&srec, gstn);
              break;
			case 4: dispAll(srec);
					 		break;
			case 5: printf("\n\nEnter year level: ");
              scanf("%d", &yrl);
              viewYr(srec, yrl);
              break;
      case 6: printf("Enter course: ");
              gets(gcrs); fflush(stdin);
              viewCrs(srec, gcrs);
              break;
      default: exit(0);
		}
	}while(ch > 0 && ch < 7);

	return 0;
}

int chkStnum(ltype * sr, char s[]) {
  int i = 0;
  for(; i < sr->size; i++) {
    if(strcmp(sr->stud[i].stnum, s) == 0) {
      return 1;
    }
  }
  return 0;
}

void enroll(ltype * sr, stype s) {
	int i = 0;
	int f1 = 0;
  if(sr->size == 5) {
    printf("\n\n\nMax number of students reached\nEnrollment unsuccessful");
  }else {
    f1 = chkStnum(sr, s.stnum);
    if(f1) {
      printf("\n\n\nStudent already exists\nEnrollment unsuccessful");
    }else{
      sr->stud[i] = s;
      sr->size++;
      printf("\n\n\nEnrollment successful");
    }
  }
	printf("\n\n\n");
	system("PAUSE");
}

void drop(ltype * sr, char s[]) {
	int i = 0;
	int fl = 0;
	fl = chkStnum(sr, s);
	if(fl) {
		system("CLS");
		dispStud(&sr->stud[i]);
		for(; i < sr->size - 1; i++) {
			sr->stud[i] = sr->stud[i+1];
		}
		sr->size--;
		printf("\n\n\nDrop successful");
	}else {
		printf("\n\n\nStudent number cannot be found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void edit(ltype * sr, char s[]) {
	int i = 0;
	int j = 0;
	int fl = 0;
	int ch;
	fl = chkStnum(sr, s);
	if(fl) {
		do {
      system("CLS");
      printf("EDIT STUDENT RECORD\n\n\n");
      dispStud(&sr->stud[i]);
      printf("\n\n\n1 - Last Name\t4 - Course\t7 - Gender\n2 - First Name\t5 - Year\t8 - Final Grade\n3 - Middle Name\t6 - Age\t\t9 - Exit");
      printf("\n\nChoice: ");
      scanf("%d", &ch);
			fflush(stdin);
      switch(ch) {
        case 1: printf("\n\nFamily Name: ");
                gets(sr->stud[i].lname);
                break;
        case 2: printf("\n\nFirst Name: ");
                gets(sr->stud[i].fname);
                break;
        case 3: printf("\n\nMiddle Name: ");
                gets(sr->stud[i].mname);
                break;
        case 4: printf("\n\nCourse: ");
                gets(sr->stud[i].crs);
                break;
        case 5: printf("\n\nYear Level: ");
                scanf("%d", &sr->stud[i].yr);
                break;
        case 6: printf("\n\nAge: ");
                scanf("%d", &sr->stud[i].age);
                break;
        case 7: printf("\n\nGender: ");
                scanf("%c", &sr->stud[i].gen);
                break;
        case 8:printf("\n\nFinal Grade: ");
                gets(sr->stud[i].fgr);
        default: j = 2;
      }
      if(j == 2) {
        break;
      }else {
        fflush(stdin);
        system("CLS");
        printf("\n\n\nEdit successful. Continue to edit? 1 - Yes / 0 - No\n\nChoice: ");
        scanf("%d", &j);
        fflush(stdin);
      }
		}while(j);
	}else {
		printf("\n\n\nStudent number cannot be found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void dispStud(stype * s) {
  printf("Student Number: %s", s->stnum);
  printf("\n\nName: %s, %s %s", s->lname, s->fname, s->mname);
  printf("\n\nCourse & Year level: %s %d", s->crs, s->yr);
  printf("\n\nAge: %d", s->age);
  printf("\n\nGender: %c", s->gen);
  printf("\n\nFinal Grade: %s", s->fgr);
}

void dispAll(ltype sr) {
	int i = 0;
	printf("STUDENT RECORD\n\n\n");
	for(; i < sr.size; i++) {
		printf("Student %d\n\n", i+1);
		dispStud(&sr.stud[i]);
		printf("\n\n\n");
	}
	if(i == 0) {
    printf("No students found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void viewYr(ltype sr, int s) {
	int i = 0;
	int fl = 1;
	system("CLS");
	switch(s) {
    case 1: printf("FIRST ");
            break;
    case 2: printf("SECOND ");
            break;
    case 3: printf("THIRD ");
            break;
    default: printf("FOURTH ");
             break;
	}
	printf("YEAR\n\n\n");
	for(; i < sr.size; i++) {
		if(sr.stud[i].yr == s) {
			fl = 0;
			dispStud(&sr.stud[i]);
			printf("\n\n");
		}
	}
	if(fl) {
    printf("No students found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void viewCrs(ltype sr, char s[]) {
	int i = 0;
	int fl = 1;
	system("CLS");
	puts(s);
	printf("\n\n\n");
	for(; i < sr.size; i++) {
		if(strcmp(sr.stud[i].crs, s) == 0) {
			fl = 0;
			dispStud(&sr.stud[i]);
			printf("\n\n");
		}
	}
	if(fl) {
    printf("No students found");
	}
	printf("\n\n\n");
	system("PAUSE");
}
