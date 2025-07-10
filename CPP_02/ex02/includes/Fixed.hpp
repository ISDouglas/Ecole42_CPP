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
		// operators
		Fixed &operator=(const Fixed &other); //copy assignment operator
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed &operator++();  // ++a
		Fixed operator++(int);// a++ (int):dummy parameter
		Fixed &operator--();  // --a
		Fixed operator--(int);// a--
		// destructor
		~Fixed();
		// member functions
		float toFloat(void) const;
		int toInt(void) const;
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
