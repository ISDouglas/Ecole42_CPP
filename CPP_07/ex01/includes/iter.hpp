#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void iter(T *array, const unsigned int size, F f)
{
	for (unsigned int i = 0; i < size; i++)
		f(array[i]);
} 

template <typename T, typename F>
void iter(const T *array, const unsigned int size, F f)
{
	for (unsigned int i = 0; i < size; i++)
		f(array[i]);
}

#endif
