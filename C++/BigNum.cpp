#include<iostream>
#include<string>

using namespace std;

class BigNum {
private:
 string digits;
public:
  int x;
  BigNum();
  BigNum(int x) { x = 0; };
  BigNum(string digits) { int i = 0; while(i < 99) { digits += '0'; i++; } this->digits = digits; };
  string& getDigits() { return this->digits; };
  void display() { int i = 0; while(i < 100) { cout<<digits[i]; i++; } }
};

char operator+(BigNum& a, const int& b) {
  char ret;
  ret += a.x + b + '0';
  return ret;
}

string& getFib(BigNum& num) {
  int a, b;
  string c;

  return &c;
}

int main() {
  BigNum num("");
  string *ptr = new string;
  ptr = getFib(num);
  num.display();
  return 0;
}
