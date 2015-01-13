#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdlib.h>

static const std::string ascii[31] = {
	"\\0",
	"\\1",
	"\\2",
	"\\3",
	"\\4",
	"\\5",
	"\\6",
	"\\a",
	"\\b",
	"\\n",
	"\\v",
	"\\f",
	"\\r",
	"\\14",
	"\\15",
	"\\16",
	"\\17",
	"\\18",
	"\\19",
	"\\20",
	"\\21",
	"\\22",
	"\\23",
	"\\24",
	"\\25",
	"\\26",
	"\\27",
	"\\28",
	"\\29",
	"\\30",
	"\\31"
};

int		mstrcmp(const char *s, const char *ss) {
	int i = 0;
	while (s[i] == ss[i])
		i++;
	return (s[i] - ss[i]);
}

bool		is_float(const char *s) {
	int i = 0, x = 0;
	if (s[i]) {
		if (s[i] == '-') {
			i++;
		}
		if (s[i] == '0')
			i++;
		while (s[i]) {
			if (s[i] >= '0' && s[i] <= '9')
				i++;
			else if (s[i] == '.') {
				x++;
				i++;
			}
			else
				return false;
			if (x > 1)
				return false;
		}
		return true;
	}
	return false;
}

bool		is_char(const char *s) {
	for (int i = 0; i < 31; i++) {
		if (s == ascii[i])
			return true;
	}
	if (!s[1]) {
		return (s[0] >= 0);
	}
	return false;
}

void		print_from_char(const char *s) {
	int i = 0;
	for (i = 0; i < 31; i++) {
		if (s == ascii[i])
			break;
	}
	if (i == 31) {
		i = static_cast <int>(s[0]);
	}
	std::cout << "char: " << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(i) << std::endl;
}

bool		is_int(char const *s) {
	int i = 0;
	if (s[i]) {
		if (s[i] == '-') {
			i++;
		}
		if (s[i] == '0') {
			if (!s[i + 1])
				return true;
			return false;
		}
		while (s[i]) {
			if (s[i] >= '0' && s[i] <= '9')
				i++;
			else
				return false;
		}
		return true;
	}
	return false;
}

void		print_from_float(char const *s) {
	double	d = strtod(s, NULL);
	std::stringstream outInt, outLimitInt;
	outLimitInt << std::fixed << std::setprecision(0) << d;
	int i = static_cast <int>(d);
	float f = static_cast <float>(d);
	outInt << i;
	char const *c;
	if (i >= 0 && i <= 31)
		c = ascii[i].c_str();
	else if (i <  0 || i > 127)
		c = "impossible";
	else if (i == 127)
		c = "\\127";
	else
		c = reinterpret_cast<char *>(&i);
	std::cout << "char: '" << c << "'" << std::endl;
	if (outInt.str() != outLimitInt.str()) 
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (std::abs(d) > static_cast<float>(std::numeric_limits<float>::max())) 
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << f << "f" << std::endl;
	if (std::abs(d) > std::numeric_limits<double>::max()) 
		std::cout << "double: " << "impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << d <<  std::endl;
}

void		print_from_int(char const *s) {
	double	d = strtod(s, NULL);
	std::stringstream outDouble, outInt, outFloat;
	outDouble << std::setprecision(0) << std::fixed << d;
	int i = static_cast <int>(d);
	float f = static_cast <float>(d);
	outInt << i;
	outFloat << i;
	char const *c;
	if (i >= 0 && i <= 31)
		c = ascii[i].c_str();
	else if (i <  0 || i > 127)
		c = "impossible";
	else if (i == 127)
		c = "\\127";
	else
		c = reinterpret_cast<char *>(&i);
	std::cout << "char: '" << c << "'" << std::endl;
	if (outInt.str() != s) 
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (outFloat.str() != s)
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	if (outDouble.str() != s)
		std::cout << "double: " << "impossible" << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << d <<  std::endl;
}

int			main(int ac, const char **av) {
	if (ac < 2) {
		std::cout << "Usage: literal" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++) {
		if (is_char(av[i]))
			print_from_char(av[i]);
		else if (is_int(av[i]))
			print_from_int(av[i]);
		else if (is_float(av[i]))
			print_from_float(av[i]);
	}
	return 0;
}
