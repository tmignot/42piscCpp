#include <iostream>

template <class T>
void		swap(T &a, T &b)
{
	T		tmp;

	tmp = b;
	b = a;
	a = tmp;
}

template <class T>
T&			min(T& a, T& b)
{
	return (a > b ? b : a);
}

template <class T>
T&			max(T& a, T& b)
{
	return (a > b ? a : b);
}

int			main(void)
{
	double a = 3465.65;
	double b = 3465.65;
	int c = 2;
	int d = 3;
	std::string e("toto");
	std::string f("tata");

	swap( a, b );
	swap( c, d );
	swap( e, f );

	std::cout << "swap( a, b ) : a = " << a << ", b = " << b << std::endl;
	std::cout << "swap( c, d ) : c = " << a << ", d = " << b << std::endl;
	std::cout << "swap( e, f ) : e = " << a << ", f = " << b << std::endl;

	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;

	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	return 0;
}
