#include <iostream>
#include "Vector/Vector.h"
#include "String/String.h"

int main() {
	SGT::String str = "Hello World";
	SGT::String str2 = "Hello World";

	std::cout << str.isTheSame("Hello World") << std::endl;
}