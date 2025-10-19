#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <exception>

template <typename T>
class Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array():_array(NULL), _size(0) {}
		Array(unsigned int n): _array(new T[n]()), _size(n) {}
		Array(const Array &other):_array(new T[other._size]), _size(other._size)
		{
			for (unsigned int i = 0; i < _size; ++i)
				_array[i] = other._array[i];
		}
		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete [] _array;
				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_array[i] = other._array[i];
			}
			return *this;
		}
		T &operator[](unsigned int i)
		{
			if (i >= _size)
				throw IndexOutBounds();
			return this->_array[i];
		}
		const T &operator[](unsigned int i) const
		{
			if (i >= _size)
				throw IndexOutBounds();
			return this->_array[i];
		}
		~Array()
		{
			delete [] this->_array;
		}
		unsigned int size() const {return _size;}
		class IndexOutBounds: public std::exception { public: const char *what() const throw(){return "Index is out of bounds";}};
};

#endif
