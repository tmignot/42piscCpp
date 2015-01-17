#ifndef RAM_HPP
# define RAM_HPP

#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
	private:
		std::string _totalram, _freeram, _sharedram, _bufferram, _totalswap, _freeswap, _process;
	protected:
	public:
		RAM(void);
		RAM(RAM const&);
		void	getData();
		~RAM(void);
		RAM			&operator=(RAM const&);
};

#endif
