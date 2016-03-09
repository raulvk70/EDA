#include <iostream>
using namespace std;
#include "StaticStack.h"

void lexicographical(int num, StaticStack<int> stack);

int main() {
	StaticStack<int> stack = StaticStack<int>();
	
	lexicographical(64323, stack);

	system("pause");
	return 0;
}

void lexicographical(int num, StaticStack<int> stack) {
	int addition;

	// It pushes each separate digit of the integer number in the stack
	while (num > 0) {
		stack.push(num % 10);
		num = num / 10;
	}

	cout << stack.top();
	addition = stack.top();
	stack.pop();
	// It pops each element, printing it and adding it to a sum
	while (!stack.empty())
	{
		cout << " + " << stack.top();
		addition += stack.top();
		stack.pop();
	}
	cout << " = " << addition << endl;
}