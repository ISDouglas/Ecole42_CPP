#include "../includes/whatever.hpp"

template<class P> void swap(P &x, P &y)
{
    P tmp = x;
    x = y;
    y = tmp;
}

template<class P> P &min(P& x, P& y)
{
    return (x < y ? x : y);
}

template<class P> P &max(P& x, P& y)
{
    return (x > y ? x : y);
}

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
