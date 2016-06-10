#include<iostream>
#include<string>

using namespace std;

class BigNum {
private:
  char digits[100];
public:
  int x;
  BigNum();
  BigNum(int x) { this->x = x; };
  BigNum(char digits[]) { int i = 0; while(i < 99) { digits[i] = '0'; i++; } digits[i] = 0; this->digits = digits; };
  char* getDigits() { return this->digits; };
  void display() { int i = 0; while(i < 100) cout<<digits[i]<<endl; }
};

int main() {
  int i = 0, a = 1, b = 1, c, ctr = 2;
  BigNum *n = BigNum::getDigits();
}
