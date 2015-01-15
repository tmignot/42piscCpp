#include <iostream>
#include <algorithm>
#include <list>

#ifndef 	_MUTANTSTACK_H_
# define	_MUTANTSTACK_H_

template<typename T>
class 	Mutantstack {

public:
	Mutantstack(void) {

	};

	~Mutantstack(void) {

	};

	bool 	empty(void) {
	    return (this->_root_node.empty());
	};

	unsigned int size(void) {
	    return (this->_root_node.size());
	};

	void 	push(T data) {
	    this->_root_node.push_front(data);
	};

	void 	pop(void) {
	    this->_root_node.pop_front();
	};

	T 		top(void) {
	    return (this->_root_node.front());
	};

	class iterator : public std::iterator<std::input_iterator_tag, T> {
		T 	*p;
	public:
		iterator(T *x) : p(x) {

		};

		iterator(const iterator &mit) : p(mit.p) {

		};

		iterator 	&operator++() {
			++p;
			return *this;
		};

		iterator 	operator++(T) {
			iterator tmp(*this);
			operator++();

			return (tmp);
		};

		bool 		operator==(const iterator& rhs) {
			return (p == rhs.p);
		};

		bool 		operator!=(const iterator& rhs) {
			return (p != rhs.p);
		};

		int 		&operator*() {
			return (*p);
		};

	private:

	};

private:
	Mutantstack(Mutantstack &src);
	Mutantstack &operator=(Mutantstack &rhs);

	std::list<T>  _root_node;
};

#endif		/* !_MUTANTSTACK_H_ */