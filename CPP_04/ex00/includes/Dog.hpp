#ifndef DOG_HPP
# define DOG_HPP
# include "Aminal.hpp"

class Dog: public Aminal {
    public:
		Dog();                                  // -1-default constructor
		Dog(const std::string& typeName);       // constructor with parameter
		Dog(const Dog& other);               // -2-copy constructor
		Dog &operator=(const Dog &other);    // -3-overload of the assignment operator 
		~Dog();                                 // -4-destructor
        void makeSound();
};

#endif