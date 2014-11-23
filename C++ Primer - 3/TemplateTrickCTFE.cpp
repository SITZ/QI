#include <iostream>
using namespace std;

template <int N> struct Factorial {
    enum {
        value = N * Factorial<N - 1>::value
    };
};
 
template <> struct Factorial<0> {
    enum { value = 1 };
};
 
// Factorial<4>::value == 24
// Factorial<0>::value == 1

int main() {
    int x = Factorial<0>::value; // == 1
    cout << "0! = " << x << endl;

    int y = Factorial<4>::value; // == 24
    cout << "4! = " << y << endl;

    system("pause");

    return 0;
}
