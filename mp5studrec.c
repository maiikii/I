#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct {
	char stnum[10];
	char lname[20];
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
	srec.size = 1;
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
			case 1: if(srec.size < 5) {
								printf("ENROLLMENT FORM\n\n\n");
						 		printf("Student Number: ");
						 		gets(s.stnum);	fflush(stdin);
						 		printf("\nFamily Name: ");
						 		gets(s.lname);	fflush(stdin);
						 		printf("\nFirst Name: ");
						 		gets(s.fname);	fflush(stdin);
						 		printf("\nMiddle Name: ");
						 		gets(s.mname);	fflush(stdin);
						 		printf("\nCourse: ");
						 		gets(s.crs);	fflush(stdin);
						 		printf("\nYear Level: ");
						 		scanf("%d", &s.yr);
						 		printf("\nAge: ");
						 		scanf("%d", &s.age);	fflush(stdin);
						 		printf("\nGender: ");
						 		scanf("%c", &s.gen);	fflush(stdin);
						 		printf("\nFinal Grade: ");
						 		gets(s.fgr);	fflush(stdin);
						 		enroll(&srec, s);
							}else {
								printf("\n\n\nMax number of students reached\nEnrollment unsuccessful");
								printf("\n\n\n");
							 	system("PAUSE");
							}
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
	int j;
	int fl = 0;
	/*for(;i < sr->size && sr->size != 1; i++) {
		for(j = 0, fl = 1; j < 10; j++) {
      if(sr->stud[i].stnum[j] != s.stnum[j]) {
        fl = 0;
        break;
      }
		}
		if(fl) {
      break;
		}
	}*/
	for(; i < sr->size && sr->size != 1; i++) {
    printf("\n%s[%d] - %s = %d\n", sr->stud[i].stnum, i, s.stnum, strcmp(sr->stud[i].stnum, s.stnum));
    system("PAUSE");
    if(strcmp(sr->stud[i].stnum, s.stnum) == 0) {
      fl = 1;
      break;
    }
	}
	if(fl) {
	  printf("\n\n\n\nStudent already exists\nEnrollment unsuccessful");
	}else {
		sr->stud[i] = s;
		strcpy(sr->stud[i].lname, s.lname);
		sr->stud[i].stnum[10] = 0;
		sr->size++;
		printf("\n\n\n\nEnrollment successful");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void drop(ltype * sr, char s[]) {
	int i = 0;
	int j;
	int k;
	int fl;
	for(; i < sr->size; i++) {
		for( k = 0, fl = 1; j < 10; j++) {
      if(sr->stud[i].stnum[k] != s[k]) {
        fl = 0;
        break;
      }
		}
		if(fl) {
      break;
		}
	}
	if(fl) {
		disp1(sr, i);
		for(j = i - 1; j < sr->size - 1; j++) {
			sr->stud[j] = sr->stud[j+1];
		}
		printf("\n\n\nDrop successful");
	}else {
		printf("\n\n\nStudent number cannot be found");
	}
	sr->size--;
	printf("\n\n\n");
	system("PAUSE");
}

void edit(ltype * sr, char s[]) {
	int i = 0;
	int j;
	int fl = 0;
	int ch;
	/*for(; i < sr->size; i++) {
		for(j = 0, fl = 1; j < 10; j++) {
      if(sr->stud[i].stnum[j] != s[j]) {
        fl = 0;
        break;
      }
		}
		if(fl) {
      break;
		}
	}*/
	for(; i < sr->size; i++) {
    printf("\n%s[%d] - %s = %d\n", sr->stud[i].stnum, i, s, strcmp(sr->stud[i].stnum, s));
    system("PAUSE");
    if(strcmp(sr->stud[i].stnum, s) == 0) {
      fl = 1;
      break;
    }
	}
	if(fl) {
		do {
      system("CLS");
      printf("EDIT STUDENT RECORD\n\n\n");
      disp1(sr, i);
      printf("\n\n\n1 - Family Name\t5 - Year Level\n2 - First Name\t6 - Age\n3 - Middle Name\t7 - Gender\n4 - Course\t8 - Final Grade");
      printf("\n\nChoice: ");
      scanf("%d", &ch);
			fflush(stdin);
      switch(ch) {
        case 1: printf("\n\nFamily Name: ");
                gets(sr->stud[i].lname);
                fflush(stdin);
                break;
        case 2: printf("\n\nFirst Name: ");
                gets(sr->stud[i].fname);
                fflush(stdin);
                break;
        case 3: printf("\n\nMiddle Name: ");
                gets(sr->stud[i].mname);
                fflush(stdin);
                break;
        case 4: printf("\n\nCourse: ");
                gets(sr->stud[i].crs);
                fflush(stdin);
                break;
        case 5: printf("\n\nYear Level: ");
                scanf("%d", sr->stud[i].yr);
                break;
        case 6: printf("\n\nAge: ");
                scanf("%d", sr->stud[i].age);
                break;
        case 7: printf("\n\nGender: ");
                scanf("%c", sr->stud[i].gen);
                break;
        default:printf("\n\nFinal Grade: ");
                gets(sr->stud[i].fgr);
                fflush(stdin);
      }
      system("CLS");
      printf("\n\n\nEdit successful. Continue to edit? 1 - Yes / 0 - No\n\nChoice: ");
      scanf("%d", &j);
		}while(j);
	}else {
		printf("\n\n\nStudent number cannot be found");
	}
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
	printf("STUDENT RECORD\n\n\n");
	for(; i < sr.size - 1; i++) {
		disp1(&sr, i);
		printf("\n\n\n");
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
