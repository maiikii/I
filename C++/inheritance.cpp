#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Parent {
  public:
    Parent();
    Parent(string name);
    virtual void introduceYourself();
    void setName(string name);

  protected:
    string name;
    double grade;
};

Parent::Parent(): grade(0) {
}

Parent::Parent(string name): grade(0) {
  this->name = name;
}

void Parent::introduceYourself() {
  cout << "Hi! My name is " << name << endl;
}

void Parent::setName(string name) {
  this->name = name;
}

class Child: public Parent {
  public:
    int sizeSneakers;
    virtual void introduceYourself();
};

void Child::introduceYourself() {
  cout << "What's up! My name is " << name << endl;
}

int main() {
  Parent mom("Mom");
  mom.introduceYourself();

  Child kid;
  kid.setName("Kid");
  kid.introduceYourself();

  Parent* parent = &kid;
  parent->introduceYourself();
  
  return 0;
}
