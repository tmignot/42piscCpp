#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
	private :

		unsigned int		_n;
		unsigned int		_i;
		std::vector<int>	_vector;

		Span();

	public :

		Span(unsigned int);
		Span(Span const&);
		Span& operator=(Span const&);

		unsigned int		getSize() const;
		std::vector<int>	getVect() const;

		void	addNumber(int);
		void	addRange(int, int);

		unsigned int shortestSpan();
		unsigned int longestSpan();

		class NotEnoughSpaceException : public std::exception {
			private :
				NotEnoughSpaceException& operator=(NotEnoughSpaceException const&);

			public :
				NotEnoughSpaceException();
			 	NotEnoughSpaceException(NotEnoughSpaceException const&);
				~NotEnoughSpaceException() throw();

				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception {
			private :
				NoSpanException& operator=(NoSpanException const&);

			public :
				NoSpanException();
			 	NoSpanException(NoSpanException const&);
				~NoSpanException() throw();

				virtual const char *what() const throw();
		};

};


#endif
