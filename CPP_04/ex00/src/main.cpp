#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog("dog1");
	const Animal* i = new Cat("cat1");
	const Animal* a = new Cat(*(static_cast<const Cat*>(i)));
	const Animal* b = j;
	Dog* k = new Dog("dog-dog");
	const Dog c(*k);

	std::cout << std::endl;
	std::cout << j->getType() << " sound:" << std::endl;
	j->makeSound(); // dog sound
	std::cout << i->getType() << " sound:" << std::endl;
	i->makeSound(); // cat sound
	std::cout << meta->getType() << " sound:" << std::endl;
	meta->makeSound(); // animal sound
	std::cout << std::endl;

	std::cout << a->getType() << " sound:" << std::endl;
	a->makeSound(); // cat sound
	std::cout << b->getType() << " sound:" << std::endl;
	b->makeSound(); // dog sound
	std::cout << std::endl;
	std::cout << k->getType() << " sound:" << std::endl;
	k->makeSound(); // dog sound
	std::cout << c.getType() << " sound:" << std::endl;
	c.makeSound(); // dog sound
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete a;
	delete k;

	std::cout << "\n=== Wrong Polymorphism (no virtual) ===" << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();

	std::cout << std::endl;
	std::cout << wmeta->getType() << " sound: ";
	wmeta->makeSound(); // WrongAnimal sound
	std::cout << wi->getType() << " sound: ";
	wi->makeSound(); // WrongAnimal sound again (not WrongCat!)

	std::cout << std::endl;
	delete wmeta;
	delete wi;

	return 0;
}
