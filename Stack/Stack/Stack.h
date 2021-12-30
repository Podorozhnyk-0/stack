#pragma once
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class Stack
{
private:
	int current_length = 0;
	int max_length = 0;
	T* stack = nullptr;
public:
	Stack(int amount = 5);
	~Stack();

	void reset();

	T peek();

	void pop();

	void push(T value);

	bool is_empty();

	void print();
};

template<class T>
inline Stack<T>::Stack(int amount)
{
	max_length = amount;
	current_length = 0;
	stack = new T[max_length]{0};
}

template<class T>
inline Stack<T>::~Stack()
{
	current_length = 0;
	max_length = 0;
	delete[] stack;
}

template<class T>
inline bool Stack<T>::is_empty()
{
	if (current_length == 0) {
		return true;
	}
	return false;
}

template<class T>
inline void Stack<T>::print()
{
	cout << "( ";
	for (size_t i = 0; i < current_length; i++) {
		cout << stack[i] << " ";
	}
	cout << ")" << endl;
}

template<class T>
inline void Stack<T>::reset()
{
	for (size_t i = 0; i < current_length; i++) {
		stack[i] = 0;
	}
	current_length = 0;
}

template<class T>
inline void Stack<T>::push(T value)
{
	try {
		if (current_length == max_length) {
			throw exception("Stack is overflow");
		}
		stack[current_length++] = value;
	}
	catch (exception ex) {
		std::cerr << ex.what() << endl;
	}
}

template<class T>
inline T Stack<T>::peek()
{
	return stack[current_length - 1];
}

template<class T>
inline void Stack<T>::pop()
{
	try {
		if (is_empty()) {
			throw exception("Stack is empty");
		}
		stack[current_length--] = 0;
	}
	catch (exception ex) {
		std::cerr << ex.what() << endl;
	}
}
