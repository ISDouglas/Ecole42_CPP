#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <iostream>

int main()
{
	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size / 2; ++i)
		animals[i] = new Dog("dog-");
	for (int i = size / 2; i < size; ++i)
		animals[i] = new Cat("cat-");

	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << animals[i]->getType() << " makes sound: ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	std::cout << "Test DEEP copy:" << std::endl;
	Dog* Dog2 = dynamic_cast<Dog*>(animals[1]); 
	if (Dog2) 
	{
		std::cout << "-copy 2nd dog to a new dog: dogCopy" << std::endl;
		Dog2->getBrain()->setIdea(0, "Original idea");
		Dog dogCopy = *Dog2;
		dogCopy.getBrain()->setIdea(0, "Changed in copy");
		std::cout << "   Original idea: " << Dog2->getBrain()->getIdea(0)
					<< "   adresse: " << Dog2->getBrain() << std::endl;
		std::cout << "   Copy idea:     " << dogCopy.getBrain()->getIdea(0)
					<< " adresse: " << dogCopy.getBrain() << std::endl;
	}

	{
		std::cout << "---------------------------------------------" << std::endl;
		Dog *dogTest = new Dog();
		Dog *dogTmp = new Dog(*dogTest);

		dogTest->getBrain()->setIdea(0, "My idea");
		dogTmp->getBrain()->setIdea(0, "Myother Idea");
		std::cout << "dogTest idea: " << dogTest->getBrain()->getIdea(0) << std::endl;

		delete dogTest;
		std::cout << "dogTmp idea: " << dogTmp->getBrain()->getIdea(0) << std::endl;
		delete dogTmp;
		std::cout << "---------------------------------------------" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Dog1: "<< std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "I want a bone.");
	std::cout << "Dog2: "<< std::endl;
	Dog dog2 = dog1;
	dog2.getBrain()->setIdea(0, "I want to nap.");
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0)
				<< "   adresse: " << dog1.getBrain() << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0)
				<< "   adresse: " << dog2.getBrain() << std::endl;

	std::cout << "\nTest DEEP copy for Cat:" << std::endl;
	Cat* cat1 = new Cat("catty");
	cat1->getBrain()->setIdea(0, "Cat original");
	Cat catCopy = *cat1;
	catCopy.getBrain()->setIdea(0, "Cat changed");
	std::cout << "Original: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy:     " << catCopy.getBrain()->getIdea(0) << std::endl;
	delete cat1;
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];

	return 0;
}
