#include<stdio.h> 
#include<conio.h> 

int main()
{ 
unsigned int num1 = 3, num2 = -2; 

printf("num1's initial value is %u.\n",num1); 
printf("num2's initial value is %u.\n",num2); 

num1 = num1 + 1; 
num2 = num2 - 1; 

printf("num1's value is now %u.\n",num1); 
printf("num2's value is now %u.\n",num2); 

num1 = 2147483647; 
num2 = -2147483648; 

printf("num1's value is now %u.\n",num1); 
printf("num2's value is now %u.\n",num2); 

num1 = num1 + 1; 
num2 = num2 - 1; 

printf("num1's value is now %u.\n",num1); 
printf("num2's value is now %u.\n",num2);

getch();
return 0;
}
