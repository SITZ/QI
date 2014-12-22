#include <cmath>
#include <iostream>
using namespace std;

template <class T>
class Time {
private:
	T hour;
	T minute;

public:
	Time() : hour(0), minute(0) {}
	Time(T _hour, T _minute) : hour(_hour), minute(_minute) {}

	void operator=(const Time& time) {
		this->hour = time.hour;
		this->minute = time.minute;
	}

	Time operator+(const Time& time) {
		T totalTime = (this->minute + time.minute);
		totalTime += (this->hour + time.hour) * 60;

		return Time(totalTime / 60, totalTime % 60);
	}

	Time operator-(const Time& time) {
		if (this->hour < time.hour || this->minute <= time.minute) {
			cerr << "\tTime: Can't be negative\n";
			return Time<T>(0, 0);
		}

		T totalTime = (this->minute - time.minute);
		totalTime += (this->hour - time.hour) * 60;

		return Time(totalTime / 60, totalTime % 60);
	}

	bool operator==(const Time& time) {
		return this->hour == time.hour && this->minute == time.minute;
	}

	void show() {
		cout << "Hour: " << this->hour << ", Minute: " << this->minute << endl;
	}
};

int main() {
	Time<int> t1(2, 45);
	Time<int> t2(1, 30);
	Time<int> t3;

	t3 = t1 + t2;
	t3.show();

	t3 = t1 - t2;
	t3.show();

	t3 = t2 - t1;
	t3.show();

	cout << (t1 == t2) << endl;

	t2 = t1;

	cout << (t1 == t2) << endl;

	return 0;
}