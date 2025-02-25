#include <iostream>
#include "Vector/Vector.h"

int main() {
	SGT::Vector<int> vec;

	for (int i = 0; i < 13; i++) {
		vec.push_back(i);
	}
	std::cout << "=======================\n";
	vec.printData();

	if (vec.BinarySearch(55)) {
		std::cout << "Exists!\n";
	}
	else {
		std::cout << "NOT Exists!\n";
	}
}