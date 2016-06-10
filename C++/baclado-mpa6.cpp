#include<iostream>
#include<string>

using namespace std;

class BigNum {
private:
  string digits;
public:
  int x;
  string a;
  string b;
  BigNum();
  BigNum(int x) { this->x = x; };
  BigNum(string);
  string getDigits() { return digits; }
  void setDigits(BigNum);
  void display() { int i = 0; while(i < 100) { cout<<digits[i]; i++; } }
  BigNum operator+(BigNum n) { return (n.a - '0') + (n.b - '0') + '0'; }
  BigNum operator-(BigNum n) { (n.a - '0') + (n.b - '0') };
  BigNum operator/(BigNum n) { return n.a / n.b; }
  BigNum operator*(BigNum n) { return n.a * n.b; }
  BigNum operator%(BigNum n) { return n.a % n.b; }
};

BigNum::BigNum(string digits) {
  int i = 0;
  while(i < 100) {
    digits += '0';
    i++;
  }
  this->digits = digits;
}

void BigNum::setDigits(BigNum n) {
  int i = 0;
  while(i < 100 && n[i] != 0) {
    this->digits[i] = n[i];
    i++;
  }
}

BigNum operator+(BigNum n, int x) {
  return ;
}

BigNum operator-(BigNum n, int x) {
  return 0;
}

BigNum operator/(BigNum n) {
  return 0;
}

BigNum operator*(BigNum n) {
  return 0;
}

BigNum operator%(BigNum n) {
  return 0;
}

int main() {
  BigNum n("");
  n.getDigits();
  int ctr = 2, x, y, z;
  string c;

  while(ctr < 2) {
    if(ctr < 7)
      c = (n.a - '0') + (n.b - '0') + '0';
    else {
      x = n.a.length() - 1;
      y = n.b.length() - 1;
      z = x;
      if(y > x) z = y;
      if((n.a[0] - '0') + (n.b[0] - '0') > 9)
        z++;
      for(int i; i < z; i++)
        c += '0';
      for(; x <= 0 && y <= 0; x--, y--,z--)
        c[z] = ( (n.a[x] - '0') + (n.b[y] - '0') ) + '0';
      if(x > 0) {
        for(; x >= 0; x--, z--)
          c[z] = n.a[x];
      }else if(y > 0) {
        for(; y >= 0; y--, z--)
          c[z] = n.b[y];
      }
    }
    n.a = n.b;
    n.b = c;
    ctr++;
  }

  n.setDigits(n);
  n.display();
  return 0;
}
