#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{
    private:
        int					_rawBits;
		static const int	_fractionalBits = 8;
    public:
		Fixed();                    // default constructor
		Fixed(const Fixed& aFixed); // copy constructor
		Fixed &operator=(const Fixed &other);
		// destructor
		~Fixed();
		// member functions
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif
