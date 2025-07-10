#ifndef CAT_HPP
# define CAT_HPP
# include "Aminal.hpp"

class Cat: public Aminal {
	public:
		Cat();                                  // -1-default constructor
		Cat(const std::string& typeName);       // constructor with parameter
		Cat(const Cat& other);               // -2-copy constructor
		Cat &operator=(const Cat &other);    // -3-overload of the assignment operator 
		~Cat();                                 // -4-destructor
		void makeSound();
};

#endif