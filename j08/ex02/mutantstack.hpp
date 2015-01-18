#ifndef     _MUTANTSTACK_H_
# define    _MUTANTSTACK_H_

#include    <stack>
#include    <iostream>
#include    <iterator>

template<class T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>() {}
    ~MutantStack<T>() {}
    MutantStack<T>(MutantStack<T> const& copy) { *this = copy; }
    MutantStack<T>& operator=(MutantStack<T> const& rhs) { *this = rhs; return *this; }

    class iterator : public std::iterator<std::input_iterator_tag, T>
    {
        T* p;
        
    public:
        iterator(T* x) :p(x) {}
        iterator(const iterator& mit)
            : p(mit.p) {

        }

        iterator&       operator++() {
            ++p;
            return *this;
        }

        iterator        operator++(int) {
            iterator    tmp(*this);
            operator++();
            return tmp;
        }

        iterator&       operator--() {
            --p;
            return *this;
        }

        iterator        operator--(int) {
            iterator tmp(*this);
            operator--();
            return tmp;
        }

        bool            operator==(const iterator& rhs) {
            return p==rhs.p;
        }

        bool            operator!=(const iterator& rhs) {
            return p!=rhs.p;
        }

        int& operator*() {
            return *p;
        }
    };

    MutantStack<T>::iterator begin() {
		MutantStack<T> yop;
		T *last;
		while (!this->empty())
		{
			yop.push(this->top());
			this->pop();
		}

		this->push(yop.top());
		last = &(this->top());
		yop.pop();
		while (!yop.empty())
		{
			this->push(yop.top());
			yop.pop();
		}
		MutantStack<T>::iterator begin (last);
		return (begin);
	}

    MutantStack<T>::iterator end() {
		T *first;
		first = &(this->top());
		MutantStack<T>::iterator end (first + 1);
		return (end);
	}

};

#endif /* _MUTANTSTACK_H_ */
