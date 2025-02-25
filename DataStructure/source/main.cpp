#include <iostream>
#include "Vector/Vector.h"

int main() {
	SGT::Vector<int> vec;

	for (int i = 0; i < 13; i++) {
		vec.push_back(i);
	}
	std::cout << "=======================\n";
	vec.printData();

	//vec.insertAt(99, 1);
	//vec.printData();
	
	std::cout << "=======================\n";
	vec.removeAt(1);
	vec.printData();
	std::cout << "=======================\n";
	vec.remove(0);
	vec.printData();
}