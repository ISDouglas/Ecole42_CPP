#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
	public:
		Fixed();                    // default constructor
		Fixed(const	int	intValue);  // constructor with parameter integer
		Fixed(const	float floatValue);  // constructor with parameter float
		Fixed(const Fixed& aFixed); // copy constructor
		Fixed &operator=(const Fixed &other);
		// destructor
		~Fixed();
		// member functions
		float toFloat(void) const;
		int toInt(void) const;
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
