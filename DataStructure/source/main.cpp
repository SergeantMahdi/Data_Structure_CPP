#include <iostream>
#include "Vector/Vector.h"

int main() {
	SGT::Vector<int> vec;

	for (int i = 0; i < 13; i++) {
		vec.push_back(i);
	}
	vec[1] = 100;
	std::cout << "[Max]: " << vec.max() << std::endl;
	std::cout << "=======================\n";
	vec.printData();
}