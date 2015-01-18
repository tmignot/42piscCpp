#ifndef CPU_HPP
# define CPU_HPP

#include "IMonitorModule.hpp"
#include <mach/mach.h>
#include <mach/processor_info.h>
#include <sys/sysctl.h>
#include <sstream>

class CPU : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		std::string									name;
		unsigned int								cpu_count;
		processor_cpu_load_info_t					cpu_load;
		mach_msg_type_number_t						cpu_msg_count;
		float										totaltime[4][2];
		int											temp[4];
	protected:
	public:
		CPU(void);
		CPU(CPU const&);
		~CPU(void);
		CPU											&operator=(CPU const&);
		virtual void								update(void);
		virtual std::vector<std::string> const		&getData(void) const;
		virtual char								getType(void) const;
		virtual std::string const					&getName(void) const;
};

#endif
