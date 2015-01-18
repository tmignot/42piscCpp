#ifndef		EASYFIND_HPP
# define	EASYFIND_HPP

# include <algorithm>

template <typename T>
int		easyfind(T const & v, int n) {
	int ret = std::distance(v.begin(), std::find(v.begin(), v.end(), n));
	return ret == v.size() ? -1 : ret;
}

#endif
