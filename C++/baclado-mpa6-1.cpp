#include<iostream>
#include<string>

using namespace std;

class BigNum {
private:
  string digits;
public:
  string a;
  string b;
  int x;
  BigNum();
  BigNum(int x) { this->x = x; };
  BigNum(string);
  string getDigits() { return digits; }
  void setDigits(string n);
  void display() { int i = 0; while(i < 100) { cout<<digits[i]; i++; } }
  BigNum operator+(BigNum n);
  BigNum operator-(BigNum n);
  BigNum operator/(BigNum n);
  BigNum operator*(BigNum n);
  BigNum operator%(BigNum n);
};

BigNum::BigNum(string digits) {
  int i = 0;
  while(i < 100) {
    digits += '0';
    i++;
  }
  this->digits = digits;
}

void BigNum::setDigits(string n) {
  int i = 0;
  while(i < 100 && n[i] != 0) {
    this->digits[i] = n[i];
    i++;
  }
}

BigNum operator+(BigNum n) {
  return n.a + n.b + '0';
}

BigNum operator-(BigNum n) {
  return (n.a - '0') + (n.b - '0');
}

BigNum operator/(BigNum n) {

}

BigNum operator*(BigNum n) {

}

BigNum::BigNum operator%(BigNum n) {

}

int main() {
  BigNum n("");
  n.getDigits();
  string c;
  int ctr = 2, x, y, z;

  while(ctr < 102) {
    if(ctr < 7)
      c = n.a + n.b;
    else {
      x = n.a.length() - 1;
      y = n.b.length() - 1;
      z = x;
      if(y > x) z = y;
      if((n.a[0] - '0') + (n.b[0]- '0') > 9)
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
    n.b = n.c;
    ctr++;
  }
  n = c;
  n.setDigits(n);
  n.display();
  return 0;
}
