#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
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

// TODO: Create a class for working with a tuple / pair

int main() { 
    Stack<int>    intStack;       // stack of ints 
    Stack<string> stringStack;    // stack of strings 

    // manipulate int stack 
    intStack.push(7); 
    cout << intStack.top() <<endl; 

    // manipulate string stack 
    stringStack.push("hello"); 
    cout << stringStack.top() << endl; 
    stringStack.pop(); 

} 