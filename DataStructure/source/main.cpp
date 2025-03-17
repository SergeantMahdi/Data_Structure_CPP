#include <iostream>
#include "Vector/Vector.h"
#include "String/String.h"
#include "LinkedList/List.h"


int main() {
	SGT::List<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);

	list.insertAt(1, 99);
	list.insertAt(0, 19);

	list.printData();


}