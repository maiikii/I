typedef class Student {
  public:
    Student(int anAge);
    int getAge();
    void setAge(int anAge);
  private:
    int age;
} Student;

Student::Student(int anAge) {
  setAge(anAge);
}

int Student::getAge() {
  // compute age based on bday
  return age;
}

void Student::setAge(int anAge) {
  if (anAge > 0) {
    age = anAge;
  }
}

int main() {
  Student bob(15); //  Student bob = Student(15);
  bob.setAge(15);
  bob.getAge();
  return 0;
}
