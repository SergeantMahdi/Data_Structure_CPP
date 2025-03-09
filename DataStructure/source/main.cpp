#include <iostream>
#include "Vector/Vector.h"
#include "String/String.h"

int main() {
	SGT::String str = "Hello World";
	SGT::String str2 = "Hello World";
	SGT::Vector<int> vec;
	for (int i = 0; i < 15; i++) {
		vec.push_back(i);
	}
	vec.printData();
	for (int i = 0; i < 13; i++) {
		vec.pop_back();
	}
	vec.printData();

	std::cout << str.isTheSame("Hello World") << std::endl;
}