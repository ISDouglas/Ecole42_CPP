#include "../includes/Serializer.hpp"

int main()
{
	Data d;
	d.index = 123;

	Data* original = &d;
	uintptr_t raw = Serializer::serialize(original);
	Data* recovered = Serializer::deserialize(raw);

	std::cout << "original pointer: " << original << std::endl;
	std::cout << "raw integer: 0x" << std::hex << raw << std::dec << std::endl;
	std::cout << "recovered pointer: " << recovered << std::endl;

	if (recovered == original) {
		std::cout << "SUCCESS: recovered pointer equals original." << std::endl;
		std::cout << "Data contents: id=" << recovered->index << std::endl;
	} else {
		std::cout << "FAIL: pointers differ." << std::endl;
	}

	return 0;
}
