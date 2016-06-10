#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"

int chkStnum(list, char[]);
void drop(list*, int);
void IDsort(list*);
void nameSort(list*);
void dispStud(student);
void dispAll(list*);
void yearDisp(list);
void nameSearch(list, student);

int main() {
	list l;
	student s;
	int ch;
	int pos;
	char getNum[11];
	char ln[30];
	initList(&l);
	do{
		do{
      printf("\nMENU\n\n1 - Enroll a student\n2 - Drop a student\n3 - Sort by ID\n4 - Sort by Name\n5 - Display all students\n6 - Display all students by year\n7 - Search by Name\n8 - Exit");
      printf("\n\nChoice: ");
      scanf("%d", &ch);	fflush(stdin);
      printf("\n\n\n");
      if(ch < 0 || ch > 8) {
        printf("\nInvalid input\n\n\n");
        system("PAUSE");	system("CLS");
      }
		}while(ch < 0 || ch > 8);
		system("PAUSE");	system("CLS");
		switch(ch) {
			case 1: printf("\nENROLLMENT FORM\n\n\n");
							printf("Student Number: ");
							gets(s.number);	fflush(stdin);
							printf("\nLast Name: ");
							gets(s.lname);	fflush(stdin);
							printf("\nFirst Name: ");
							gets(s.fname);	fflush(stdin);
							printf("\nMiddle Name: ");
							gets(s.mname);	fflush(stdin);
							printf("\nProgram: ");
							gets(s.program);		fflush(stdin);
							printf("\nYear Level: ");
							scanf("%d", &s.yr); fflush(stdin);
							printf("\nGender: ");
							scanf("%c", &s.gender);
							pos = chkStnum(l, s.number);
							if(pos)
								printf("\n\n\nStudent number already exists");
							else {
								append(&l, s);
								printf("\n\n\nEnrollment successful");
							}
							break;
			case 2: printf("\nDROP STUDENT\n\n\nStudent Number: ");
					 		gets(getNum);	fflush(stdin);
					 		pos = chkStnum(l, getNum);
							drop(&l, pos);
							break;
			case 3: IDsort(&l);
							break;
			case 4: nameSort(&l);
							break;
			case 5: dispAll(&l);
							break;
			case 6: yearDisp(l);
							break;
			case 7: printf("SEARCH BY NAME\n\nLast Name: ");
              gets(s.lname);  fflush(stdin);
              printf("\nFirst Name: ");
							gets(s.fname);	fflush(stdin);
							printf("\nMiddle Name: ");
							gets(s.mname);	fflush(stdin);
							system("CLS");
              nameSearch(l, s);
							break;
			default: exit(0);
		}
		if(ch != 8) {
      printf("\n\n\n");
      system("PAUSE");
      system("CLS");
		}
	}while(ch > 0 && ch < 8);
	return 0;
}

int chkStnum(list l, char s[]) {
	int p = 0;
	node* temp = l.head;
	while(temp != NULL) {
		if(strcmp(temp->item.number, s) == 0) {
			return p + 1;
		}
		p++;
		temp = temp->next;
	}
	return 0;
}

void drop(list* l, int pos) {
  int p = 0;
  node* temp = l->head;
  if(pos) {
    system("CLS");
    printf("\nDROP STUDENT\n\n");
    for(; p < pos - 1; p++)
      temp = temp->next;
    dispStud(temp->item);
    deleteItem(l, pos);
    printf("\n\n\nDrop successful");
  }else
    printf("\n\nStudent number not found");
}

void IDsort(list* l){
	int fl = 0;
	node *ptr = l->head, *temp;
	student x;
	while(ptr != NULL) {
		temp = ptr->next;
		while(temp != NULL) {
			if(strcmp(ptr->item.number, temp->item.number) == 1) {
				x = ptr->item;
				ptr->item = temp->item;
				temp->item = x;
			}
			temp = temp->next;
		}
		ptr = ptr->next;
		fl = 1;
	}
	if(fl)
    dispAll(l);
  else
    printf("\nSTUDENT DATABASE\n\n\nNo students found");

}

void nameSort(list* l){
  int fl = 0;
  node *ptr = l->head, *temp;
	student x;
	while(ptr != NULL) {
		temp = ptr->next;
		while(temp != NULL) {
			if(strcmpi(ptr->item.lname, temp->item.lname) == 1) {
				x = ptr->item;
				ptr->item = temp->item;
				temp->item = x;
			}
			temp = temp->next;
		}
		ptr = ptr->next;
		fl = 1;
	}
	if(fl)
    dispAll(l);
  else
    printf("\nSTUDENT DATABASE\n\n\nNo students found");
}

void dispStud(student s) {
	printf("\nStudent Number: %s", s.number);
  printf("\n\nName: %s, %s %s", s.lname, s.fname, s.mname);
  printf("\n\nProgram & Year level: %s %d", s.program, s.yr);
  printf("\n\nGender: %c", s.gender);
}

void dispAll(list* l) {
	node* temp = l->head;
	printf("\nSTUDENT DATABASE\n\n\n");
	if(temp == NULL)
    printf("No students found");
	while(temp != NULL) {
		dispStud(temp->item);
    temp = temp->next;
		printf("\n\n");
	}
}

void yearDisp(list l) {
	int i;
	node* temp;
	printf("\nSTUDENT DATABASE\n\n\n");
	if(l.head == NULL)
		printf("No students found");
	else {
    for(i = 1; i < 5; i++) {
      temp = l.head;
      while(temp != NULL) {
        if(temp->item.yr == i) {
          dispStud(temp->item);
          printf("\n\n");
        }
        temp = temp->next;
      }
    }
	}
}

void nameSearch(list l, student s) {
  node* temp = l.head;
  int fl = 1;
  printf("\nSEARCH BY NAME\n\n\n");
  while(temp != NULL) {
    if(strcmpi(temp->item.lname, s.lname) == 0 && strcmpi(temp->item.fname, s.fname) == 0 && strcmpi(temp->item.mname, s.mname) == 0){
      fl = 0;
      dispStud(temp->item);
      break;
    }
    temp = temp->next;
  }
  if(fl)
    printf("Name: %s, %s %s\n\n\nStudent not found", s.lname, s.fname, s.mname);
}
