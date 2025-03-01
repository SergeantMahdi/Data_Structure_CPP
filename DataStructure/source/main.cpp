#include <iostream>
#include "Vector/Vector.h"

void* operator new(size_t size) {
	std::cout << "NEW IS CALLED\n";
	void* p = malloc(size);
	return p;
}

int main() {
	SGT::Vector<int> vec;
	std::cout << "[Capacity]: "<< vec.maxCapacity() << std::endl;
	vec.reserve(20);
	std::cout << "[Capacity]: " << vec.maxCapacity() << std::endl;


	for (int i = 0; i < 16; i++) {
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