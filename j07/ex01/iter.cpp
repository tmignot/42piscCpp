#include <iostream>
#include <string>

template<class T>
void			displayFour(T s)
{
	char		*str = (char*)(s.c_str());

	if (s.length() > 4)
		str[4] = '\0';
	std::cout << str << std::endl;
}

template void	displayFour<std::string> (std::string);

void			doubleUp(int n)
{
	std::cout << n * 2 << std::endl;
}

template<class T, class U>
void			iter(T *array, size_t size, U (*f)(T))
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

int				main(void)
{
	int			intArray[10] = 
	{
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9
	};
	std::string	stringArray[11] =
	{
		"this",
		"is",
		"a",
		"long",
		"fucking",
		"string",
		"array",
		"does",
		"this",
		"never",
		"end ?"
	};
	::iter(intArray, 10, &doubleUp);
	::iter(stringArray, 11, &displayFour);
	return (0);
}
