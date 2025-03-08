#include <iostream>
#include "Vector/Vector.h"
#include "String/String.h"

int main() {
	SGT::String str = "Hello World";
	str.toUpperCase();
	std::cout << str << std::endl;
}