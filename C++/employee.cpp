#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Employee {
  public:
    virtual float computeSalary() = 0;
    string getName();
    void setName(string name);
  private:
    string name;
};


string Employee::getName() {
  return name;
}

void Employee::setName(string name) {
  this->name = name;
}

class Regular: public Employee {
  public:
    Regular(int hours, float hourlyRate);
    virtual float computeSalary();
  private:
    int hours;
    float hourlyRate;
};

Regular::Regular(int hours, float hourlyRate) {
  this->hours = hours;
  this->hourlyRate = hourlyRate;
}

float Regular::computeSalary() {
  return hours * hourlyRate;
}


class Manager: public Employee {
  public:
    Manager(float monthlyRate);
    virtual float computeSalary();
  private:
    float monthlyRate;
};

Manager::Manager(float monthlyRate) {
  this->monthlyRate = monthlyRate;
}

float Manager::computeSalary() {
  return monthlyRate;
}

class Contractual: public Employee {
  public:
    Contractual(int days, float dailyRate);
    virtual float computeSalary();
  private:
    int days;
    float dailyRate;
};

Contractual::Contractual(int days, float dailyRate) {
  this->days = days;
  this->dailyRate = dailyRate;
}

float Contractual::computeSalary() {
  return days * dailyRate;
}

int main() {
  Regular kim(12, 20); 
  Manager dave(50000);
  Contractual kelly(30, 200);

  kim.setName("Kim");
  dave.setName("Dave");
  kelly.setName("Kelly");

  Employee* employees[3];
  employees[0] = &kim;
  employees[1] = &dave;
  employees[2] = &kelly;

  for (int i = 0; i < 3; i++) {
    cout << employees[i]->getName() << ": " 
      << employees[i]->computeSalary() << endl;
  }
  return 0;
}
