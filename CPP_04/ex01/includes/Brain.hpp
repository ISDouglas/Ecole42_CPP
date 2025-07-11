#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();                               // -1-default constructor
		Brain(const Brain& other);             // -2-copy constructor
		Brain &operator=(const Brain &other);  // -3-overload of the assignment operator 
		~Brain();                              // -4-destructor
		void setIdea(int index, const std::string idea);
		std::string getIdea(int index) const;
};

#endif