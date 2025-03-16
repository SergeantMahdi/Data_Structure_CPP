#include <iostream>
#include "Vector/Vector.h"
#include "String/String.h"
#include "LinkedList/LinkedList.h"


int main() {
	SGT::LinkedList<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.printData();


}