#ifndef MODULE_HPP
# define MODULE_HPP

class IMonitorModule
{
	private:
	protected:
	public:
		IMonitorModule(void);
		IMonitorModule(IMonitorModule const&);
		~IMonitorModule(void);
		IMonitorModule				&operator=(IMonitorModule const&);
};

#endif
