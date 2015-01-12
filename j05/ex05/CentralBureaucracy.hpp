#ifndef CENTRAL_BUREAUCRACY_H
# define CENTRAL_BUREAUCRACY_H

#include "OfficeBlock.hpp"

class CentralBureaucracy
{
	private:
		class String
		{
			private:
				std::string					value;
			public:
				String						*next;
				String						*last;
				String(void);
				String(std::string);
				String(String const&);
				~String(void);
				String						&operator=(String const&);
				std::string					*pop(void);
				void						add(std::string);
				void						deleteAll(void);
		};
		OfficeBlock							*offices[20];
		CentralBureaucracy::String			*targets;
		Bureaucrat							*waiting;

	public:
		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy const&);
		~CentralBureaucracy(void);
		CentralBureaucracy					&operator=(CentralBureaucracy const&);
		void								hire(Bureaucrat&);
		void								queueUp(std::string);
		void								doBureaucracy(void);
};

#endif
