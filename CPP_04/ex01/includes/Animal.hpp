#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();                                  // -1-default constructor
		Animal(const std::string& typeName);       // constructor with parameter
		Animal(const Animal& other);               // -2-copy constructor
		Animal &operator=(const Animal &other);    // -3-overload of the assignment operator 
		virtual ~Animal();                         // -4-destructor
		std::string getType() const;
		virtual void makeSound() const;
};

#endif