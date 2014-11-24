#include <iostream>
using namespace std;

template<typename T>
T maximum(T x, T y) {
	return x < y ? y : x;
}

/*
 Exercise: WAP to swap values of two variables of any data type
 a = 10, b = 20;
 swap(a, b)
 a = 20, b = 10;
 */

template<typename T>
void swapIt(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	cout << "maximum(1, 5)    : " << maximum(1, 5) << endl;
	cout << "maximum(1.1, 1.5): " << maximum(1.1, 1.5) << endl;
	cout << "maximum('a', 'c'): " << maximum('a', 'c') << endl;

	cout << endl;

	int a = 10, b = 20;
	cout << "a: " << a << ", b: " << b << endl;
	swapIt(a, b);
	cout << "a: " << a << ", b: " << b << endl;

	char x = 'x', y = 'y';
	cout << "x: " << x << ", y: " << y << endl;
	swapIt(x, y);
	cout << "x: " << x << ", y: " << y << endl;

	return 0;
}
