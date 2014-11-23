#include <iostream>
#include <string>
using namespace std;

/*
  Exercise: WAP to create a class for represent time of the day.
  Time : Hours, Minutes, Seconds
  Time time1 = new Time();
  Time time2 = new Time(10, 30, 30);
*/

class Time {
private:
  int hours;
  int minutes;
  int seconds;

public:
  Time() : 
    hours(0), minutes(0), seconds(0) {}
  Time(int _hours, int _minutes, int _seconds) :
    hours(_hours), minutes(_minutes), seconds(_seconds) {}
       
  void printTime() {
    cout << hours << ":" << minutes << ":" << seconds << endl;
  }
};

int main() {
    Time* time1 = new Time();
    time1->printTime();
    
    Time* time2 = new Time(10, 11, 12);
    time2->printTime();
    
    return 0;
}
