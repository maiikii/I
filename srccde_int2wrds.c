#include<stdio.h>

void fun1(int n);
void fun2(int m);
void fun3(int j,int k);
void test1(int n);
void test2(int n);
void test3(int n);
void test4(int n);

int main(){
  int n;
  printf("enter a num(1-100,00,000):");
  scanf("%d",&n);
  printf("\nyou have entered:");
  if(n<=100)
    test1(n);
  else if(n>100&&n<1000)
    test2(n);
  else if(n>=1000&&n<=100000)
    test3(n);
  else if(n>100000&&n<=10000000)
    test4(n);
  return 0;
}

void test1(n){
  int m,j,k;
  if(n>=0&&n<=10)
    fun1(n);
  else if(n>10&&n<20){
    m=n%10;
    fun2(m);
  }else if(n>=20&&n<=100){
    j=n/10;
    k=n%10;
    fun3(j,k);
  }
}

void test2(int n)
{
  int b,c;
  c=n/100;
  fun1(c);
  printf(" hundred ");
  b=n%100;
  test1(b);
}

void test3(int n)
{
  int a,b,c;
  if(n==1000){
    printf(" Thousand ");
    exit(0);
  }else if(n==100000){
    printf("Lakh");
    exit(0);
  }else{
    a=n/1000;
    test1(a);
    printf(" Thousand ");
    c=n%1000;
    if(c<=99)
      test1(c);
    else
      test2(c);
  }
}

void test4(int n)
{
int a,b;
if(n==10000000)
{
printf("ten million");
exit(0);
}
a=n/100000;
test1(a);printf(" hundred ");
b=n%100000;
if(b==0)exit(0);
else if(b<=99)test1(b);
else if(b>99&&b<=999)test2(b);
else test3(b);
}

void fun1(int n)
{
switch(n)
{
case 0:printf("zero");break;
case 1:printf("one");break;
case 2:printf("two");break;
case 3:printf("three");break;
case 4:printf("four");break;
case 5:printf("five");break;
case 6:printf("six");break;
case 7:printf("seven");break;
case 8:printf("eight");break;
case 9:printf("nine");break;
case 10:printf("ten");break;
default:printf("");
}
}
void fun2(int m)
{
switch(m)
{
case 1:printf("eleven");break;
case 2:printf("twelve");break;
case 3:printf("thirteen");break;
case 4:printf("fourteen");break;
case 5:printf("fifteen");break;
case 6:printf("sixteen");break;
case 7:printf("seventeen");break;
case 8:printf("eighteen");break;
case 9:printf("nineteen");break;
default:printf("");
}
}
void fun3(int j,int k)
{
switch(j)
{
case 2:printf("twenty ");break;
case 3:printf("thirty ");break;
case 4:printf("fourty ");break;
case 5:printf("fifty ");break;
case 6:printf("sixty ");break;
case 7:printf("seventy ");break;
case 8:printf("eighty ");break;
case 9:printf("ninty ");break;
case 10:printf("hundred");break;
default:printf("");
}
fun1(k);
}
