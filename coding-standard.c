#include <stdio.h> // space after include

int doSomething(int aParameter);

int main() { // do not specify void for empty parameter list
  // indent = 2 spaces
  int a = 10; // space before and after operators
  int b = a + 20; // each declaration on its own line

  int c, d = 10; // !!wrong

  // some code here
  int e = doSomething(a == b);

  if (a == b) { // curly braces even if then-clause is one-liner
    a += b;
  } else if (a > b) {
    a -= b;
  } else {
    a = b;
  }

  switch (a) {
    case 1: a += b;
            break;
    case 2: a -= b;
            break;
    default: a = b;
  }

  return 0; // this is convention for normal termination
}

int doSomething(int aParameter) {
  return 1;
}
