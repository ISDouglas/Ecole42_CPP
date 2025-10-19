#include "../includes/iter.hpp"

template <typename T>
void printFancy(const T &t)
{
	std::cout << "🎨 [" << t << "]" << std::endl;
}

void addEmoji(std::string &s)
{
	s += " 😎";
}

int main()
{
	int arrInt[] = {1, 4, 8};
	std::string arrStr[] = {"Alice", "Bob"};
	const std::string arrStrC[] = {"Kk", "Tt"};

	std::cout << "printFancy: " << std::endl;
	iter(arrInt, 3, printFancy<int>);
	iter(arrStr, 2, printFancy<std::string>);
	iter(arrStrC, 2, printFancy<std::string>);

	std::cout << "\naddEmoji: " << std::endl;
	iter(arrStr, 2, addEmoji);
	iter(arrStr, 2, printFancy<std::string>);
}
