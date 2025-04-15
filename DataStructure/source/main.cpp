#include <iostream>
#include <list>
#include "Vector/Vector.h"
#include "String/String.h"
#include "LinkedList/List.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"



int main() {
	/*SGT::List<int> list;
	SGT::List<int> list2;

	list.push_back(1);
	list.push_front(10);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list2.push_back(32);
	list2.push_back(42);
	list2.push_back(52);
	list2.push_back(62);
	list.append(list2);
	list.printData();*/


	/*SGT::Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.printData();
	stack.pop();
	stack.printData();
	std::cout << stack.top();*/

	SGT::Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.printData();

}