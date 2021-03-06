#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>

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

bool		is_nanf(const char *s){
	return (s[0] == 'n' && s[1] == 'a' && s[2] == 'n' && s[3] == 'f' && s[4] == '\0');
}

bool		is_inff(const char *s){
	return ((s[0] == '+' && s[1] == 'i' && s[2] == 'n' && s[3] == 'f' && s[4] == 'f' && s[5] == '\0') || (s[0] == '-' && s[1] == 'i' && s[2] == 'n' && s[3] == 'f' && s[4] == 'f' && s[5] == '\0'));
}

bool		is_nan(const char *s){
	return (s[0] == 'n' && s[1] == 'a' && s[2] == 'n' && s[3] == '\0');
}

bool		is_inf(const char *s){
	return ((s[0] == '+' && s[1] == 'i' && s[2] == 'n' && s[3] == 'f' && s[4] == '\0') || (s[0] == '-' && s[1] == 'i' && s[2] == 'n' && s[3] == 'f' && s[4] == '\0'));
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
			{
				if ((!s[i + 1] && s[i] == 'f') || is_nanf(s) || is_inff(s))
					return true;
				return false;
			}
			if (x > 1)
				return false;
		}
		return true;
	}
	return false;
}

bool		is_double(const char *s) {
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
			{
				if (is_nan(s) || is_inf(s))
					return true;
				return false;
			}
			if (x > 1)
				return false;
		}
		return true;
	}
	return false;
}

bool		is_char(const char *s) {
	std::string t = "\\127";
	if (s == t)
		return true;
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
	std::string t = "\\127";
	for (i = 0; i < 31; i++) {
		if (s == ascii[i])
			break;
	}
	if (i == 31) {
		i = static_cast <int>(s[0]);
	}
	if (i >= 0 && i <= 31)
	std::cout << "char: " << ascii[i] << std::endl;
	else if (s == t) {
	std::cout << "char: " << "\\127" << std::endl;
	i = 127;
	}
	else
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

void		print_from_double(char const *s) {
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
	if (!(std::abs(d) > static_cast<float>(std::numeric_limits<float>::max()))) 
		std::cout << "float: " << std::fixed << f << "f" << std::endl;
	else if (is_inf(s))
		std::cout << "float: " << s[0] << s[1] << s[2] << s[3] << 'f' << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
	if (!(std::abs(d) > std::numeric_limits<double>::max()))
		std::cout << "double: " << std::fixed << d <<  std::endl;
	else if (is_inf(s))
		std::cout << "double: " << s[0] << s[1] << s[2] << s[3] << std::endl;
	else
		std::cout << "double: " << "impossible" << std::endl;
}

void		print_from_float(char const *s) {
	double	d = strtof(s, NULL);
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
	if (!(std::abs(d) > static_cast<float>(std::numeric_limits<float>::max()))) 
		std::cout << "float: " << std::fixed << f << "f" << std::endl;
	else if (is_inff(s))
		std::cout << "float: " << s[0] << s[1] << s[2] << s[3] << 'f' << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
	if (!(std::abs(d) > std::numeric_limits<double>::max()))
		std::cout << "double: " << std::fixed << d <<  std::endl;
	else if (is_inff(s))
		std::cout << "double: " << s[0] << s[1] << s[2] << s[3] << std::endl;
	else
		std::cout << "double: " << "impossible" << std::endl;
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
		if (is_int(av[i]))
			print_from_int(av[i]);
		else if (is_char(av[i]))
			print_from_char(av[i]);
		else if (is_float(av[i]))
			print_from_float(av[i]);
		else if (is_double(av[i]))
			print_from_double(av[i]);
	}
	return 0;
}
