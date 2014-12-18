#include <iostream>
#include <cassert>
using namespace std;

int main() {
	int A[50][50];
	int B[50][50];
	int C[50][50];
	int M, P, Q, N;

	cout << "Enter dimensions of A: ";
	cin >> M >> P;
	cout << "Enter elements of   A: ";
	for (int i = 0; i < M; i++)
		for (int j = 0; j < P; j++)
			cin >> A[i][j];

	cout << "Enter dimensions of B: ";
	cin >> Q >> N;
	cout << "Enter elements of   B: ";
	for (int i = 0; i < Q; i++)
		for (int j = 0; j < N; j++)
			cin >> B[i][j];

	assert (P == Q);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int cellValue = 0;

			for (int k = 0; k < P; k++)
				cellValue += A[i][k] * B[k][j];

			C[i][j] = cellValue;
		}
	}

	cout << "C:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}