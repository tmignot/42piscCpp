#include "RAM.hpp"

RAM::RAM(void) : IMonitorModule(), type('i'), data(std::vector<std::string>())
{
	this->update();
}
RAM::RAM(RAM const &ram) : IMonitorModule() {*this = ram;}
RAM::~RAM(void) {}
RAM								&RAM::operator=(RAM const&) {return (*this);}
std::vector<std::string> const	&RAM::getData() const
{
	return (this->data);
}

void							RAM::update(void)
{
	// TODO
}

int								RAM::getWidth(void) const
{
	int			ret = 0;

	for (std::vector<std::string>::const_iterator it = this->data.begin(); it != this->data.end(); ++it)
	{
		if ((*it).length() > static_cast<unsigned int>(ret))
			ret = (*it).length();
	}
	return (ret);
}

WINDOW							*RAM::initWindow(WINDOW *lastwin, WINDOW *displaywin) const
{
	int					w = this->getWidth() + 2;
	int					h = this->data.size() + 2;
	WINDOW				*local_win = NULL;
	if (lastwin)
	{
		if (getbegy(lastwin) + getmaxy(lastwin) + h + 1 < getmaxy(displaywin))
		{
			if (getbegx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(h, w, getbegy(lastwin) + getmaxy(lastwin) + 1, getbegx(lastwin));
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

char							RAM::getType(void) const
{
	return (this->type);
}
