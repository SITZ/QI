#include <iostream>
using namespace std;

class Time {
private:
	int hours;
	int minutes;

public:
	void setTime(int h, int m) {
		hours = h;
		minutes = m;
	}

	Time sum(Time TM) {
		Time t;
		t.minutes = minutes + TM.minutes;
		t.hours = t.minutes / 60;
		t.minutes = t.minutes % 60;
		t.hours += hours + TM.hours;
		return t;
	}

	void showTime() {
		cout << hours << " hours and " << minutes << " minutes" << endl;
	}
};

int main() {
	Time T1, T2, T3;
	T1.setTime(2, 45);
	T2.setTime(3, 30);
	T3 = T1.sum(T2);

	cout << "\n Time 1 : "; T1.showTime();
	cout << "\n Time 2 : "; T2.showTime();
	cout << "\n Time 3 : "; T3.showTime();

	return 0;
}