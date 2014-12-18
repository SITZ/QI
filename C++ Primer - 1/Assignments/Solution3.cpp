#include <iostream>
using namespace std;

int main() {
	int i, j, k;
	int N;
	cout << "Enter N : ";
	cin >> N;
	for (i = 1; i <= N; i++) {
		for (j = N; j > i; j--)
			cout << ' ';
		for (k = 1; k < 2 * i; k++)
			cout << '*';
		cout << endl;
	}

	return 0;
}
