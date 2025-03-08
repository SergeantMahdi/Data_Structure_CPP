#include <iostream>
#include "Vector/Vector.h"
#include "String/String.h"

int main() {
	SGT::String str = "Hello World";
	str.reverse();
	std::cout << str << std::endl;
}