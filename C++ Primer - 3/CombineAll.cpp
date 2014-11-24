#include <iostream>
using namespace std;

/*
 Pair -> best_bid_price, best_ask_price
 List -> <Pairs> {{80, 85}, {81, 84}...}
 Sort operation -> Operation needed
 */

template<class T1, class T2>
class Pair {
public:
	T1 bestBid;
	T2 bestAsk;

	Pair() :
			bestBid(0), bestAsk(0) {
	}
	Pair(T1 b, T2 a) :
			bestBid(b), bestAsk(a) {
	}
	Pair(Pair const & otherPair) :
			bestBid(otherPair.bestBid), bestAsk(otherPair.bestAsk) {
	}

	bool operator<(const Pair<T1, T2>& otherPair) {
		if (this->bestBid != otherPair.bestBid)
			return this->bestBid < otherPair.bestBid;
		else
			return this->bestAsk < otherPair.bestAsk;
	}

	Pair const & operator=(Pair const & otherPair) {
		this->bestBid = otherPair.bestBid;
		this->bestAsk = otherPair.bestAsk;

		return *this;
	}
};

template<class T>
class List {
private:
	int currentSize;
	int maximumSize;
	T* list;

public:
	List() {
		currentSize = 0;
		maximumSize = 10;
		list = new T[maximumSize];
	}

	~List() {
		delete[] list;
	}

	void insert(T p) {
		if (currentSize == maximumSize) {
			T* tempList = new T[currentSize];
			for (int i = 0; i < currentSize; i++)
				tempList[i] = list[i];

			maximumSize *= 2;
			list = new T[maximumSize];

			for (int i = 0; i < currentSize; i++)
				list[i] = tempList[i];
		}

		list[currentSize++] = p;
	}

	T operator[](int index) {
		return list[index];
	}

	int size() {
		return currentSize;
	}
};

template<class T>
void sort(List<T>& input) {
	for (int i = 0; i < input.size(); i++) {
		for (int j = i + 1; j < input.size(); j++) {
			if (input[j] < input[i]) {
				T temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}
}

int main() {
	List<Pair<int, int> > tickList;

	tickList.insert(Pair<int, int>(3, 3));
	tickList.insert(Pair<int, int>(1, 3));
	tickList.insert(Pair<int, int>(1, 2));
	tickList.insert(Pair<int, int>(2, 3));

	for (int index = 0; index < tickList.size(); index++) {
		cout << "Bid: " << tickList[index].bestBid << ", Ask: " << tickList[index].bestAsk << endl;
	}
	cout << endl;

	sort(tickList);

	for (int index = 0; index < tickList.size(); index++) {
		cout << "Bid: " << tickList[index].bestBid << ", Ask: " << tickList[index].bestAsk << endl;
	}
}
