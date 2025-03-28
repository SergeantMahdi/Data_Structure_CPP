#include <iostream>
#include <list>
#include "Vector/Vector.h"
#include "String/String.h"
#include "LinkedList/List.h"


int main() {
	SGT::List<int> list;
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
	list.printData();



}