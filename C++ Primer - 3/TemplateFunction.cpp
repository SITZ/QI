#include <iostream>
using namespace std;

template <typename T>
T maximum(T x, T y) {
    return x < y ? y : x;
}

// WAP to swap values of two variables

int main() {
	cout << maximum(1, 5) << endl;
	cout << maximum(1.1, 1.5) << endl;
	cout << maximum('a', 'c') << endl;

	return 0;
}