#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

class Time {
  public:
    Time(): hours(0), mins(0) {}
    Time(int aHours, int aMins): hours(aHours), mins(aMins) {}
    void display();
    Time operator+(Time another); 
    bool operator<(Time another) const;

  private:
    int hours;
    int mins;
};

void Time::display() {
  cout << hours << " hours, " << mins << " mins" << endl;
}

Time Time::operator+(Time another) {
  return Time(this->hours + another.hours, this->mins + another.mins);
}

bool Time::operator<(Time another) const {
  if (this->hours < another.hours) {
    return true;
  } else if (this->hours > another.hours) {
    return false;
  } else {
    return this->mins < another.mins;
  }
}


int main() {
  Time time(1, 5);
  Time nextTime(0, 30);

  time = time + nextTime;

  if (time < nextTime) {
    time.display();
  } else {
    nextTime.display();
  }

  vector<double> numbers;

  numbers.push_back(2);
  numbers.push_back(1);
  numbers.push_back(4);
  numbers.push_back(3);

  int i;
  for (i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;

  sort(numbers.begin(), numbers.end());

  for (i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;

  vector<Time> times;
  times.push_back(time);
  times.push_back(nextTime);

  for (i = 0; i < times.size(); i++) {
    times[i].display();
  }
  
  sort(times.begin(), times.end());

  for (i = 0; i < times.size(); i++) {
    times[i].display();
  }
  return 0;
}
