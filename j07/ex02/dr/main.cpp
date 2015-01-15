#include	"array.hpp"

int		main( void )
{
	Array<int>	arr = Array<int>( 3 );
	std::cout << "size = " << arr.size() << std::endl;
	std::cout << arr << std::endl;
	arr[2] = 3;
	std::cout << arr << std::endl;
	arr[3] = 4;
	std::cout << arr << std::endl;
	return ( 0 );
}
