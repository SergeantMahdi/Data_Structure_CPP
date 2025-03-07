#include <iostream>
#include "Vector/Vector.h"

int main() {
	SGT::Vector<int> vec;
	std::cout << "[Capacity]: "<< vec.maxCapacity() << std::endl;
	vec.reserve(20);
	std::cout << "[Capacity]: " << vec.maxCapacity() << std::endl;


	for (int i = 0; i < 16; i++) {
		vec.emplace_back(i);
	}
	
	vec.push_back(100);
	vec.printData();
	std::cout << "[Size]: " << vec.size() << std::endl;
	std::cout << "[Data]: " << vec.pop_back() << std::endl;
	std::cout << "=======================\n";
	vec.clear();
	vec.push_back(100);
	std::cout << "[Size]: " << vec.size() << std::endl;
	vec.printData();

	vec.push_back(100);
	vec.printData();

}