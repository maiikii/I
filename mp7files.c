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
	struct cell* next;
}node;

typedef struct{
	node* head;
	node* tail;
	int size;
}list;

void initList(list*);
int enrol(list*, stype);
void drop(list*, int);
void edit(list*, int);
int chkStnum(list*, char[]);
void viewYr(list, int);
void viewCrs(list, char[]);
void dispStud(stype);
void dispAll(list);
void saveFile(list);
list* loadFile();

int main(void) {
	list srec;
	list* temp;
	stype s;
	int ch;
	int pos;
	int yrl;
	int ret;
	char gstn[11];
	char gcrs[15];
	initList(&srec);
	do {
		system("CLS");
		printf("MENU\n\n1 - Enrol a student\n2 - Drop a student\n3 - Edit a student record\n4 - Display all students\n5 - View students by year level\n6 - View students by course\n7 - Save to File\n8 - Load from File\n9 - Exit");
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
							ret = enrol(&srec, s);
							if(ret) {
                printf("\n\n\nEnrollment successful");
							}else {
                printf("\n\n\nStudent number already exists");
							}
							printf("\n\n\n");
              system("PAUSE");
					 		break;
			case 2: printf("\nStudent Number: ");
					 		gets(gstn);
		 					fflush(stdin);
							pos = chkStnum(&srec, gstn);
					 		drop(&srec, pos);
					 		break;
			case 3: printf("\nStudent Number: ");
					 		gets(gstn);
		 					fflush(stdin);
							pos = chkStnum(&srec, gstn);
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
      case 7: saveFile(srec);
              break;
      case 8: srec.head = loadFile();
              if(srec.head != NULL) {
                dispAll(srec);
              }
              break;
      default: exit(0);
		}
		fflush(stdin);
	}while(ch > 0 && ch < 9);
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
		temp = temp->next;
	}
	return 0;
}

int enrol(list* s, stype r) {
	node* n;
	int pos;
	pos = chkStnum(s, r.stnum);
	if(pos > 0) {
    return 0;
	}else {
	  do {
      n = malloc(sizeof(node));
	  }while(n == NULL);
		memcpy(&n->item, &r, sizeof(node));
    n->next = NULL;
		if(s->size==0){
			s->head = s->tail = n;
		}else{
			s->tail->next = n;
			s->tail = n;
		}
		s->size++;
	}
  return 1;
}

void drop(list* s, int pos) {
	node* temp;
	node* del;
	int p = 1;
	if(pos == 0) {
		printf("\n\n\nStudent number cannot be found");
	}else {
    system("CLS");
	}
	if(pos == 1) {
		del = s->head;
    s->head = del->next;
	}
  if(pos > 1){
    temp = s->head;
    for(; p < pos - 1; p++){
      temp = temp->next;
    }
    del = temp->next;
    temp->next = del->next;
    if(del == s->tail) {
      s->tail = temp;
    }
  }
  if(pos > 0) {
		dispStud(del->item);
		printf("\n\n\nDrop successful");
    s->size--;
    printf("\ncheck");
	}
	free(del);
	printf("\ncheck");
	printf("\n\n\n");
	system("PAUSE");
}

void edit(list* s, int pos) {
	node* temp;
	int p = 0;
	int j = 0;
	int ch;
	if(pos == 0) {
		printf("\n\n\nStudent number cannot be found");
	}else{
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
        dispStud(temp->item);
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
  printf("\nStudent Number: %s", s.stnum);
  printf("\n\nName: %s, %s %s", s.lname, s.fname, s.mname);
  printf("\n\nCourse & Year level: %s %d", s.crs, s.yr);
  printf("\n\nAge: %d", s.age);
  printf("\n\nGender: %c", s.gen);
  printf("\n\nFinal Grade: %d%", s.fgr);
}

void dispAll(list sr) {
	node* temp = sr.head;
	printf("STUDENT RECORD\n\n\n");
	if(temp == NULL) {
    printf("\n\n\nNo students found");
	}
	while(temp != NULL) {
		dispStud(temp->item);
    temp = temp->next;
		printf("\n\n\n");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void viewYr(list sr, int s) {
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
	while(temp != NULL) {
		if(temp->item.yr == s) {
			fl = 0;
			dispStud(temp->item);
			printf("\n\n\n");
		}
		temp = temp->next;
	}
	if(fl) {
    printf("No students found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void viewCrs(list sr, char s[]) {
	int fl = 1;
	node* temp = sr.head;
	system("CLS");
	puts(s);
	printf("\n\n");
	while(temp != NULL) {
		if(strcmp(temp->item.crs, s) == 0) {
			fl = 0;
			dispStud(temp->item);
			printf("\n\n\n");
		}
		temp = temp->next;
	}
	if(fl) {
    printf("No students found");
	}
	printf("\n\n\n");
	system("PAUSE");
}

void saveFile(list l) {
  FILE* fp;
  node* temp = l.head;
  fp = fopen("database.dat", "wb");
  if(fp != NULL) {
    while(temp != NULL) {
      fwrite(&temp->item, sizeof(stype), 1, fp);
      temp = temp->next;
    }
  }
  fclose(fp);
  printf("\n\nFile saved successfully\n\n\n");
	system("PAUSE");
}

list* loadFile() {
  FILE* fp;
  list* l;
  stype j;
  int i;
  initList(l);
  fp = fopen("database.dat", "rb");
  if(fp != NULL) {
    while(fread(&j, sizeof(stype), 1, fp) != 0) {
      i = enrol(l, j);
    }
  }else {
    return NULL;
  }
  return l;
}
