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
	int fgr;
}stype;

typedef struct cell{
	stype item;
	struct cell * next;
}node;

typedef struct{
	node* head;
	node* tail;
	int size;
}list;

void initList(list*);
void enrol(list*, stype);
void drop(list*, int);
void edit(list*, int);
int chkStnum(list*, char[]);
void viewYr(list, int);
void viewCrs(list, char[]);
void dispStud(stype);
void dispAll(list);

int main(void) {
	list srec;
	stype s;
	int ch;
	int pos;
	int yrl;
	char gstn[10];
	char gcrs[15];
	initList(&srec);
	do {
		system("CLS");
		printf("MENU\n\n1 - Enrol a student\n2 - Drop a student\n3 - Edit a student record\n4 - Display all students\n5 - View students by year level\n6 - View students by course\n7 - Exit");
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
							scanf("%d", &s.fgr);
							enrol(&srec, s);
					 		break;
			case 2: printf("\nStudent Number: ");
					 		gets(gstn);
		 					fflush(stdin);
							pos = chkStnum(&srec, s.stnum);
					 		drop(&srec, pos);
					 		break;
			case 3: printf("\nStudent Number: ");
					 		gets(gstn);
		 					fflush(stdin);
							pos = chkStnum(&srec, s.stnum);
					 		edit(&srec, pos);
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
		fflush(stdin);
	}while(ch > 0 && ch < 7);

	return 0;
}

void initList(list* s) {
	s->head = s->tail = NULL;
	s->size = 0;
}

int chkStnum(list* s, char r[]) {
	int p = 0;
	node* temp = s->head;
	for(; p < s->size ; p++) {
		if(strcmp(temp->item.stnum, r) == 0) {
			return p + 1;
		}
	}
	//printf("%s ^ %s = %d\n", temp->item.stnum, r, strcmp(temp->item.stnum, r));
  //system("PAUSE");
	return 0;
}

void enrol(list* s, stype r) {
	node* n = malloc(sizeof(node));
	int pos;
	memcpy(&n->item, &r, sizeof(node));
	n->next = NULL;
	pos = chkStnum(s, r.stnum);
	if(pos > 0) {
		printf("\n\n\nStudent number already exists");
	}else {
		if(s->size==0){
			s->head = s->tail = n;
		}else{
			s->tail->next = n;
			s->tail = n;
		}
		s->size++;
	}
	printf("\n\n\n");
	system("PAUSE");
}

void drop(list* s, int pos) {
	node* temp;
	node* del;
	int p = 1;
	if(pos == 0) {
		printf("\n\n\nStudent number cannot be found");
	}else if(pos == 1) {
	  system("CLS");
		del = s->head;
    s->head = del->next;
		if(pos > 1){
			temp = s->head;
			for(; p < pos - 1; p++){
				temp = temp->next;
			}
			del = temp->next;
			temp->next = del->next;
			if(del == s->tail)
				s->tail = temp;
		}
		dispStud(del->item);
		printf("\n\n\nDrop successful");
	}
	del->next = NULL;
	free(del);
	s->size--;
	printf("\n\n\n");
	system("PAUSE");
}

void edit(list* s, int pos) {
	node* temp;
	int p = 0;
	int j = 0;
	int ch;
	if(pos < 1) {
		printf("\n\n\nStudent number cannot be found");
	}
	else{
		temp = s->head;
		for(; p < pos - 1; p++) {
			temp = temp->next;
		}
		do {
      system("CLS");
      printf("EDIT STUDENT RECORD\n\n\n");
      dispStud(temp->item);
      printf("\n\n\n1 - Last Name\t4 - Course\t7 - Gender\n2 - First Name\t5 - Year\t8 - Final Grade\n3 - Middle Name\t6 - Age\t\t9 - Exit");
      printf("\n\nChoice: ");
      scanf("%d", &ch);
			fflush(stdin);
      switch(ch) {
        case 1: printf("\n\nFamily Name: ");
                gets(temp->item.lname);
                break;
        case 2: printf("\n\nFirst Name: ");
                gets(temp->item.fname);
                break;
        case 3: printf("\n\nMiddle Name: ");
                gets(temp->item.mname);
                break;
        case 4: printf("\n\nCourse: ");
                gets(temp->item.crs);
                break;
        case 5: printf("\n\nYear Level: ");
                scanf("%d", &temp->item.yr);
                break;
        case 6: printf("\n\nAge: ");
                scanf("%d", &temp->item.age);
                break;
        case 7: printf("\n\nGender: ");
                scanf("%c", &temp->item.gen);
                break;
        case 8: printf("\n\nFinal Grade: ");
                scanf("%d", &temp->item.fgr);
                break;
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
	}
	printf("\n\n\n");
	system("PAUSE");
}

void dispStud(stype s) {
  printf("Student Number: %s", s.stnum);
  printf("\n\nName: %s, %s %s", s.lname, s.fname, s.mname);
  printf("\n\nCourse & Year level: %s %d", s.crs, s.yr);
  printf("\n\nAge: %d", s.age);
  printf("\n\nGender: %c", s.gen);
  printf("\n\nFinal Grade: %d%", s.fgr);
}

void dispAll(list sr) {
	int p = 0;
	node* temp = sr.head;
	printf("STUDENT RECORD\n\n\n");
	for(; p < sr.size; p++) {
		dispStud(temp->item);
    temp = temp->next;
		printf("\n\n");
	}
	if(p == 0) {
    printf("No students found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void viewYr(list sr, int s) {
	int p = 0;
	int fl = 1;
	node* temp = sr.head;
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
	for(; p < sr.size; p++) {
		if(temp->item.yr == s) {
			fl = 0;
			dispStud(temp->item);
			printf("\n\n");
		}
	}
	if(fl) {
    printf("No students found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void viewCrs(list sr, char s[]) {
	int p = 0;
	int fl = 1;
	node* temp = sr.head;
	system("CLS");
	puts(s);
	printf("\n\n\n");
	for(; p < sr.size; p++) {
		if(strcmp(temp->item.crs, s) == 0) {
			fl = 0;
			dispStud(temp->item);
			printf("\n\n");
		}
	}
	if(fl) {
    printf("No students found");
	}
	printf("\n\n\n");
	system("PAUSE");
}
