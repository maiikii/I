#include <stdio.h>
#include <string.h>

void add(char *val1, char *val2, int base);
void sub(char *val1, char *val2, int base);

int main() {
  
   char val1[10];
   char val2[10];
   int base;
   int choice;
   int len1, len2, i;
   
   printf("\nPlease indicate the base first: ");
   scanf("%d", &base);
   printf("\nEnter your numbers: ");
   printf("\n\n");
   
   scanf("%s", &val1[10]);
   scanf("%s", &val2[10]);
   
   for(i=0; val1[i]!='\0'; i++) {
     printf("%c", val1[i]);
   }
   
   for(i=0; val2[i]!='\0'; i++) {
     printf("%d", val2[i]);
   }
    //len1 = strlen(val1);
    //len2 = strlen(val2);
   
   printf("\nLength val1 = %d", len1);
   printf("\nLength val2 = %d", len2);
   
   printf("\nPress 1 to perform Addition.");
   printf("\nPress 2 to perform Subtraction.");
   printf("\n\n");
   scanf("\n%d", &choice);
   
   printf("\nLength val1 = %d", strlen(val1));
   printf("\nLength val2 = %d", strlen(val2));
   
   if (choice == 1) {
     add(val1, val2, base);
   }else {
     sub(val1, val2, base);
   }
    return 0;
   }

void add(char *val1, char *val2, int base){
  
  int i=0;
  int temp1;
  int temp2;
  
  printf("\nInt is %d.", (val1[0] + '0'));
  printf("\nInt is %d.", (val2[0] + '0'));
}
void sub(char *val1, char *val2, int base) {
}
