#include "Time.hpp"

Time::Time(void) : IMonitorModule(), type('i'), data(std::vector<std::string>()), name("Time")
{
	this->update();
}
Time::Time(Time const &time) : IMonitorModule() {*this = time;}
Time::~Time(void) {}
Time				&Time::operator=(Time const&) {return (*this);}
WINDOW							*Time::initWindow(WINDOW *lastwin, WINDOW *displaywin) const
{
	int					w = this->getWidth() + 2;
	int					h = this->data.size() + 2;
	WINDOW				*local_win = NULL;
	if (lastwin)
	{
		if (getbegy(lastwin) + getmaxy(lastwin) + h + 1 < getmaxy(displaywin))
		{
			if (getbegx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(h, w, getbegy(lastwin) + getmaxy(lastwin), getbegx(lastwin));
		}
		else
		{
			if (getbegx(lastwin) + getmaxx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(h, w, 1, getbegx(lastwin) + getmaxx(lastwin) + 1);
		}
	}
	else
		local_win = newwin(h, w, 1, 1);
	if (local_win)
	{
		box(local_win, 0, 0);
		wrefresh(local_win);
	}
	return (local_win);
}
int								Time::getWidth(void) const
{
	int			ret = 0;

	for (std::vector<std::string>::const_iterator it = this->data.begin(); it != this->data.end(); ++it)
	{
		if ((*it).length() > static_cast<unsigned int>(ret))
			ret = (*it).length();
	}
	return (ret);
}
char							Time::getType(void) const
{
	return (this->type);
}
std::vector<std::string> const	&Time::getData(void) const
{
	return (this->data);
}
void							Time::update(void)
{
	time_t t = time(0);
	struct tm * now = localtime( & t );
	data.clear();
	data.push_back("  Hello 42 !  ");
	std::ostringstream date;
  	date<< now->tm_mday << '/'
		<< (now->tm_mon + 1) << '/'
		<< (now->tm_year + 1900);
	data.push_back(date.str());
	date.str("");
	date<< (now->tm_hour) << 'h'
		<< now->tm_min << 'm'
		<< now->tm_sec << 's';
	data.push_back(date.str());
}

std::string const				&Time::getName(void) const
{
	return (this->name);
}
