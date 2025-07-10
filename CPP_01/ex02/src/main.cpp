#include <string>
#include <iostream>

int main()
{
	std::string brain("HI THIS IS BRAIN");
	std::string* pointer = &brain;
	std::string& ref = brain;

	std::cout << "Original brain: " << std::endl;
	std::cout << "         Value: " << brain << std::endl;
	std::cout << "         Memory address: " << &brain << std::endl;
	std::cout << "Pointer brain: " << std::endl;
	std::cout << "         Value: " << *pointer << std::endl;
	std::cout << "         Memory address: " << pointer << std::endl;
	std::cout << "Reference brain: " << std::endl;
	std::cout << "         Value: " << ref << std::endl;
	std::cout << "         Memory address: " << &ref << std::endl;
	return 0;
}
