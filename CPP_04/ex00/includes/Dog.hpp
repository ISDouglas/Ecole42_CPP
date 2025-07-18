#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal {
    public:
		Dog();                                  // -1-default constructor
		Dog(const std::string& typeName);       // constructor with parameter
		Dog(const Dog& other);                  // -2-copy constructor
		Dog &operator=(const Dog &other);       // -3-overload of the assignment operator 
		~Dog();                                 // -4-destructor
		void makeSound() const;
};

#endif