#include <iostream>
#include "Vector/Vector.h"

int main() {
	SGT::Vector<int> vec;

	for (int i = 0; i < 13; i++) {
		vec.push_back(i);
	}
	vec[1] = 100;
	vec.printData();
	std::cout << "[Size]: " << vec.size() << std::endl;
	std::cout << "[Data]: " << vec.pop_back() << std::endl;
	std::cout << "=======================\n";
	std::cout << "[Size]: " << vec.size() << std::endl;
	vec.printData();
}