template<typename T>
MutantStack<T>::MutantStack() {

}

template<typename T>
MutantStack<T>::~MutantStack() {

}

template<typename T>
MutantStack<T>::MutantStack ( MutantStack<T> const &m) {
    (*this) = m;
}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const &m) {
    (*this) = m;
    return (*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
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

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    T *first;
    first = &(this->top());
    MutantStack<T>::iterator end (first + 1);
    return (end);
}