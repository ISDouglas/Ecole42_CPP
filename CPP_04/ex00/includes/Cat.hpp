#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();                                  // -1-default constructor
		Cat(const std::string& typeName);       // constructor with parameter
		Cat(const Cat& other);                  // -2-copy constructor
		Cat &operator=(const Cat &other);       // -3-overload of the assignment operator 
		~Cat();                                 // -4-destructor
		void makeSound() const;
};

#endif