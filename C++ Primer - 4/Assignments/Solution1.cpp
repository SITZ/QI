#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <cmath>
#include <sched.h>
using namespace std;

const int THREAD_COUNT = std::thread::hardware_concurrency();
const int ROW_COUNT = 10;
const int COL_COUNT = 10000000;

int list[ROW_COUNT][COL_COUNT];
thread threadList[ROW_COUNT];
mutex locker;

void getSerialMaximum() {
	for (int rowIndex = 0; rowIndex < ROW_COUNT; rowIndex++) {
		int rowMax = 0;
		for (int colIndex = 0; colIndex < COL_COUNT; colIndex++)
			rowMax = max(rowMax, list[rowIndex][colIndex]);

		cout << "Serial Maximum of Row# " << rowIndex << ": " << rowMax << endl;
	}
}

void getParallelMaximum(int rowIndex) {
	locker.lock();
	cout << "Thread Id: " << rowIndex << endl;
	cout << "Core   Id: " << sched_getcpu() << endl;
	locker.unlock();

	int maximum = 0;
	for (int colIndex = 0; colIndex < COL_COUNT; colIndex++)
		maximum = max(maximum, list[rowIndex][colIndex]);

	locker.lock();
	cout << "Parallel Maximum of Row# " << rowIndex << ": " << maximum << endl;
	locker.unlock();
}

int main(int argc, char* argv[]) {
	cout << "Hardware Concurrency: " << THREAD_COUNT << endl;

	for (int rowIndex= 0; rowIndex< ROW_COUNT; rowIndex++) {
		for (int colIndex = 0; colIndex < COL_COUNT; colIndex++) {
			list[rowIndex][colIndex] = rowIndex + colIndex;
		}
	}

	auto start = std::chrono::high_resolution_clock::now();	
	getSerialMaximum();
	auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds> (finish - start).count() << "ns" << endl;

    start = std::chrono::high_resolution_clock::now();	
	for (int rowIndex = 0; rowIndex < ROW_COUNT; rowIndex++)
		threadList[rowIndex] = thread(getParallelMaximum, rowIndex);

	for (int rowIndex = 0; rowIndex < ROW_COUNT; rowIndex++)
		threadList[rowIndex].join();
	finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds> (finish - start).count() << "ns" << endl;
}
