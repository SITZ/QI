#include <iostream>
using namespace std;

double mean(int** matrix, int& M, int& N) {
	double sum = 0;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			sum += matrix[i][j];

	return sum / (M * N);
}

int main() {
	int M, N;
	cout << "M : ";
	cin >> M;
	cout << "N : ";
	cin >> N;
	
	cout << "Enter Matrix (" << M * N << ") elements: ";
	
	int** matrix = new int*[M];
	for (int i = 0; i < M; i++)
		matrix[i] = new int[N];

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	cout << "Mean : " << mean(matrix, M, N) << endl;

	for (int i = 0; i < M; i++)
		delete matrix[i];
	delete matrix;

	return 0;
}