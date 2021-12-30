#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> stack(5); //int-type stack at 5 elements
	stack.reset();

	stack.push(166);
	stack.push(157);

	cout << stack.peek() << endl; //top element

	stack.push(0);
	stack.push(37892);
	stack.push(-1);
	stack.print();
	stack.push(11); //Overflow stack
				    //^
	stack.print(); // | element didn't added to stack

	stack.pop(); //deleting elements
	stack.pop();
	stack.pop();
	stack.pop();

	stack.print();

	stack.pop(); //deleted last element, now stack is empty

	stack.print();

	cout << "Is empty: " << stack.is_empty() << endl;

	stack.pop();  //exception

	stack.print();
	return 0;
}