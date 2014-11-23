#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack { 
  private: 
    vector<T> elems; 

  public: 
    void push(T const& elem) {
    	elems.push_back(elem);  
    }

    void pop() {
    	elems.pop_back();
    }

    T top() const {
    	return elems.back();
    }

    bool empty() const{
        return elems.empty(); 
    } 
};

/*
    Exercise: WAP to create a generic class for working with a tuple / pair of any data type
*/

template<class T>
class Pair {
private:
    T first;
    T second;

public:
    Pair() :
        first(NULL), second(NULL) {}
    Pair(T _first, T _second) : 
        first(_first), second(_second) {}
};

int main() { 
    // Stack of integer values
    Stack<int>    intStack;
    // Stack of string values
    Stack<string> stringStack;

    // Manipulate int stack 
    intStack.push(7); 
    cout << intStack.top() <<endl; 
    intStack.push(10);
    cout << intStack.top() << endl;

    // Manipulate string stack 
    stringStack.push("hello"); 
    cout << stringStack.top() << endl; 
    stringStack.push("world");
    cout << stringStack.top() << endl;
    stringStack.pop();
    cout << stringStack.top() << endl;
    stringStack.pop(); 

    return 0;
} 
