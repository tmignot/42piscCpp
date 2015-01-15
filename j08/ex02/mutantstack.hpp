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

	bool empty(void) {
	    return (this->_root_node.empty());
	};

	unsigned int size(void) {
	    return (this->_root_node.size());
	};

	void push(T data) {
	    this->_root_node.push_front(data);
	};

	void pop(void) {
	    this->_root_node.pop_front();
	};

	T top(void) {
	    return (this->_root_node.front());
	};

private:
	Mutantstack(Mutantstack &src);
	Mutantstack &operator=(Mutantstack &rhs);

	std::list<T>  _root_node;
};

#endif		/* !_MUTANTSTACK_H_ */