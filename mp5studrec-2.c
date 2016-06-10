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
void disp1(ltype *, int);
void disp2(ltype);
void viewYr(ltype, int);
void viewCrs(ltype, char[]);

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
			case 4: disp2(srec);
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

void enroll(ltype * sr, stype s) {
	int i = 0;
	int f1 = 0;
  if(sr->size == 5) {
    printf("\n\n\nMax number of students reached\nEnrollment unsuccessful");
  }else {
    for(; i < sr->size; i++) {
      if(strcmp(sr->stud[i].stnum, s.stnum) == 0) {
        f1 = 1;
        break;
      }
    }
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
	for(; i < sr->size; i++) {
    if(strcmp(sr->stud[i].stnum, s) == 0) {
      fl = 1;
      break;
    }
	}
	if(fl) {
		system("CLS");
		disp1(sr, i);
		for(; i < sr->size - 1; i++) {
			sr->stud[i] = sr->stud[i+1];
		}
		sr->size--;
		printf("\n\n\n\nDrop successful");
	}else {
		printf("\n\n\nStudent number cannot be found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void edit(ltype * sr, char s[]) {

	printf("\n\n\n");
	system("PAUSE");
}

void disp1(ltype * sr, int i) {
  printf("Student Number: %s", sr->stud[i].stnum);
  printf("\n\nName: %s, %s %s", sr->stud[i].lname, sr->stud[i].fname, sr->stud[i].mname);
  printf("\n\nCourse & Year level: %s %d", sr->stud[i].crs, sr->stud[i].yr);
  printf("\n\nAge: %d", sr->stud[i].age);
  printf("\n\nGender: %c", sr->stud[i].gen);
  printf("\n\nFinal Grade: %s", sr->stud[i].fgr);
}

void disp2(ltype sr) {
	int i = 0;
	printf("STUDENT RECORD", sr.size);
	for(; i < sr.size; i++) {
		printf("\n\n\nStudent %d\n\n", i+1);
		disp1(&sr, i);
		printf("\n\n");
	}
	if(i == 0) {
    printf("\n\n\nNo students found");
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
	printf("YEAR\n\n");
	for(; i < sr.size; i++) {
		if(sr.stud[i].yr == s) {
			fl = 0;
			disp1(&sr, i);
			printf("\n\n");
		}
	}
	if(fl) {
    printf("\n\nNo student/s found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void viewCrs(ltype sr, char s[]) {
	int i = 0;
	int fl = 1;
	system("CLS");
	puts(s);
	printf("\n\n");
	for(; i < sr.size; i++) {
		if(strcmp(sr.stud[i].crs, s) == 0) {
			fl = 0;
			disp1(&sr, i);
			printf("\n\n");
		}
	}
	if(fl) {
    printf("\n\n\nNo student/s found");
	}
	printf("\n\n\n");
	system("PAUSE");
}
