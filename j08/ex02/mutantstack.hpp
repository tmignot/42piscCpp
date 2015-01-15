#ifndef     _MUTANTSTACK_H_
# define    _MUTANTSTACK_H_

#include    <stack>
#include    <iostream>
#include    <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    ~MutantStack();
    MutantStack( MutantStack const &);
    MutantStack & operator=(MutantStack const &);

    //Operator functions
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

    MutantStack<T>::iterator begin();
    MutantStack<T>::iterator end();
};

#include "mutantstack.cpp"


#endif /* _MUTANTSTACK_H_ */