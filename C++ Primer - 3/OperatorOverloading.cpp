#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int minute;
	int second;

public:
	Time() : 
		hour(0), minute(0), second(0) {};
	Time(int _hour, int _minute, int _second) : 
		hour(_hour), minute(_minute), second(_second) {};
	
	bool operator<(const Time time) {
		if (this->hour != time.hour)
			return this->hour < time.hour;
		if (this->minute != time.minute)
			return this->minute < time.minute;
		if (this->second != time.second)
			return this->second < time.second;

		return false;
	}
};

// Exercise: Difference between times

int main() {
	Time t1(2, 0, 0);
	Time t2(1, 0, 0);

	cout << (t1 < t2) << endl;

	return 0;
}