#ifndef		ARRAY_TPP
# define	ARRAY_TPP

# include	<iostream>
# include	<exception>

template<typename T>
class	Array
{
	private:
		unsigned int	l;
		T				*arr;

	public:
		Array<T>( void )
		: l( 0 ), arr( new T[0] )
		{ }

		Array<T>( unsigned int const n )
		: l( n ), arr( new T[n] )
		{ }

		Array<T>( Array<T> const & src )
		{ *this = src; }

		~Array<T>( void )
		{ delete [] arr; }

		Array<T>		&operator=( Array<T> const & src )
		{
			l = src.l;
			arr = new T[l];
			for ( int i = 0; i < l; ++i )
				arr[i] = src.arr[i];
			return ( *this );
		}

		T				&operator[]( unsigned int const n ) const
		{
			if ( n >= l )
				throw std::exception( );
			return ( arr[n] );
		}

		unsigned int	size( void ) const
		{
			return ( l );
		}

		std::ostream	&print( std::ostream & o ) const
		{
			o << "Array of size " << l << ": ";
			for ( int i = 0; i < l; ++i )
				o << arr[i] << " ";
			return ( o );
		}
};

template<typename T>
std::ostream	&operator<<( std::ostream & o, Array<T> const & a )
{
	return ( a.print( o ) );
}

#endif
