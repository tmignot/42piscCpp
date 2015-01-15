#include "Span.hpp"

Span::Span( void ) {
	_maxItems = 0;
	_currentIndex = 0;
}
Span::Span( int N ) : _maxItems(N), _currentIndex(0) {
	_vector.reserve(N);
}

Span::Span( Span const & src ) : _maxItems(src._maxItems), _currentIndex(src._currentIndex) {

}

Span::~Span( void ) {

}

void			Span::addNumber( int val ) {
	if (_currentIndex < _maxItems) {
		_vector.push_back(val);
		_currentIndex++;
	} else {
		throw spanLimitReached();
	}
}

void			Span::addRange (int start, int end) {
	unsigned int	diff;
	if (end < start) {
		int temp = start;
		start = end;
		end = temp;
	}
	diff = (unsigned int)(end - start);
	if (diff < (_maxItems - _currentIndex)) {
		for (int i = start; i <= end; i++) {
			_vector.push_back(i);
			_currentIndex++;
		}
	} else {
		throw spanLimitReached();
	}
}

unsigned int	Span::shortestSpan() {
	if (_currentIndex > 1) {
		std::sort (_vector.begin(), _vector.end());
		unsigned int minDiff = (unsigned int)_vector[_currentIndex - 1] - (unsigned int)_vector[0];
		for (unsigned int i = 0; i < _currentIndex - 1; ++i) {
			if (minDiff > _vector[i + 1] - _vector[i]) {
				minDiff = _vector[i + 1] - _vector[i];
			}
		}
		return (minDiff);
	} else {
		throw notEnoughValues();
	}
}
unsigned int	Span::longestSpan() {
	std::sort (_vector.begin(), _vector.end());
	if (_currentIndex > 1) {
		return ((unsigned int)_vector[_currentIndex - 1] - (unsigned int)_vector[0]);
	} else {
		throw notEnoughValues();
	}
}

Span &	Span::operator=( Span const & rhs ) {
	this->_maxItems               = rhs._maxItems;
	return (*this);
}

std::ostream &	operator<<( std::ostream & o, Span const & i ) {
	return (o << i);
}
