#include <iostream>
#include <list>
#include "Vector/Vector.h"
#include "String/String.h"
#include "LinkedList/List.h"


int main() {
	SGT::List<int> list;

	list.push_back(1);
	list.push_front(10);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.printData();
	std::cout << "[Removing]: " << "index 2" << std::endl;
	list.remove_back();
	list.printData();



}