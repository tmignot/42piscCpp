#ifndef ARRAY_H
# define ARRAY_H

# include <exception>

template<class T>
class Array
{
	private:
		T					*array;
		unsigned int		n;

	public:
		Array(void) : array(new T[0]), n(0) {}
		Array(unsigned int n) : array(new T[n]), n(n) {}
		Array(Array const &array) {*this = array;}
		~Array(void) {delete [] this->array;}
		Array			&operator=(Array const &array)
		{
			this->array = new T[array.n];
			for (int i = 0; i < array.n; i++)
				this->array[i] = T(array.array[i]);
			this->n = array.n;
			return (*this);
		}
		T				&operator[](unsigned int n)
		{
			if (n >= this->n)
				throw std::exception();
			return this->array[n];
		}
		unsigned int		size(void) {return (this->n);}
};

#endif
