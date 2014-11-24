#include <vector>
#include <utility>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

bool comparison(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	vector<pair<int, int> > tickList;
	tickList.push_back(make_pair(3, 3));
	tickList.push_back(make_pair(1, 3));
	tickList.push_back(make_pair(1, 2));
	tickList.push_back(make_pair(2, 3));

	for (vector<pair<int, int> >::iterator it = tickList.begin(); it != tickList.end(); it++) {
		cout << "Bid: " << it->first << ", Ask: " << it->second << endl;
	}

	cout << endl;

	sort(tickList.begin(), tickList.end(), comparison);

	for (vector<pair<int, int> >::iterator it = tickList.begin(); it != tickList.end(); it++) {
		cout << "Bid: " << it->first << ", Ask: " << it->second << endl;
	}
}
