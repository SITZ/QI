#include <iostream>
using namespace std;

int main() {
	int sub1, sub2, sub3, sub4, sub5, percentage;
	cout << "Enter marks of five subjects : ";
	cin >> sub1 >> sub2 >> sub3 >> sub4 >> sub5;
	percentage = (sub1 + sub2 + sub3 + sub4 + sub5) / 5;

	if(percentage >= 60)
		cout << "Ist division" << endl;
	else if(percentage >= 50)
		cout << "IInd division" << endl;
	else if(percentage>=40)
		cout << "IIIrd division" << endl;
	else
		cout << "Fail" << endl;

	return 0;
}
