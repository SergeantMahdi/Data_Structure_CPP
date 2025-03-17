#include <iostream>
#include "Vector/Vector.h"
#include "String/String.h"
#include "LinkedList/List.h"


int main() {
	SGT::List<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.printData();


}