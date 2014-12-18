#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int minute;
	int second;

public:
	Time() :
			hour(0), minute(0), second(0) {
	}
	Time(int _hour, int _minute, int _second) :
			hour(_hour), minute(_minute), second(_second) {
	}

	bool operator<(const Time time) {
		if (this->hour != time.hour)
			return this->hour < time.hour;
		if (this->minute != time.minute)
			return this->minute < time.minute;
		if (this->second != time.second)
			return this->second < time.second;

		return false;
	}

	int operator-(const Time time) {
		int duration = 0;
		duration += (this->hour - time.hour) * 3600;
		duration += (this->minute - time.minute) * 60;
		duration += (this->second - second);

		return duration;
	}
};

/* Exercise: WAP to calculate between two different points of Time
 Time t1 = 1:00:00,
 Time t2 = 2:00:00
 
 t2 - t1 => Return number of seconds elapsed between these two time samples
 */

int main() {
	Time t1(2, 30, 0);
	Time t2(1, 15, 0);

	cout << "t1 < t2: " << (t1 < t2) << endl;
	cout << "t1 - t2: " << (t1 - t2) << endl;

	return 0;
}
