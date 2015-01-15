#include "Span.hpp"
#include <complex>
#include <algorithm>
#include <iostream>

Span::Span(unsigned int n) : _n(n), _i(0) {
	_vector.reserve(_n);
}

void	Span::addNumber(int n) {
	if (_i < _n) {
		_vector[_i] = n;
		_i++;
	}
	else {
		throw  NotEnoughSpaceException();
	}
}

void	Span::addRange(int start, int end) {
	if (std::abs(end - start)  > (_n - _i))
		throw NotEnoughSpaceException();
	else {
		int inc = (start < end) ? 1 : -1;
		for (int i = _i; i != std::abs(end - start) + 1; ++i) {
			_vector[i] = start + i * inc;
		}
		_i += std::abs(end - start) + 1;
	}

}

unsigned int Span::shortestSpan() {
	if (_i < 2) {
		throw NoSpanException();
	}
	std::sort(_vector.begin(), _vector.begin() + _i);
	unsigned int s = longestSpan();
	for (int i = 0; i < _i - 1; ++i) {
		if (s > std::abs(_vector[i + 1] - _vector[i]))
			s = std::abs(_vector[i + 1] - _vector[i]);
	}
	return s;
}

unsigned int Span::longestSpan() {
	if (_i < 2) {
		throw NoSpanException();
	}
	std::sort(_vector.begin(), _vector.begin() + _i);
	return std::abs(_vector[_i - 1] - *_vector.begin());
}

Span::NotEnoughSpaceException::NotEnoughSpaceException() : std::exception() {}
Span::NotEnoughSpaceException::NotEnoughSpaceException(Span::NotEnoughSpaceException const&) : std::exception() {}
Span::NotEnoughSpaceException::~NotEnoughSpaceException() throw() {}
const char *Span::NotEnoughSpaceException::what() const throw() { return "Span : Not enough space"; }

Span::NoSpanException::NoSpanException() : std::exception() {}
Span::NoSpanException::NoSpanException(Span::NoSpanException const&) : std::exception() {}
Span::NoSpanException::~NoSpanException() throw() {}
const char *Span::NoSpanException::what() const throw() { return "Span : No span to compare"; }
