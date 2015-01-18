#include "Network.hpp"

Network::Network(void) : IMonitorModule(), type('i'), data(std::vector<std::string>()), name("Network")
{
	this->update();
}
Network::Network(Network const &network) : IMonitorModule() {*this = network;}
Network::~Network(void) {}
Network				&Network::operator=(Network const&) {return (*this);}
std::vector<std::string> const	&Network::getData() const
{
	return (this->data);
}

void							Network::update(void)
{
	static int k = 0;
	if (!(k % 10)) {
		int mib[6];
		char *buf = NULL, *lim, *next;
		size_t len;
		struct if_msghdr *ifm;


		static int64_t prev_ibytes;
		static int64_t prev_obytes;

		int64_t ibytes = 0;
		int64_t obytes = 0;

		mib[0]  = CTL_NET;          // networking subsystem
		mib[1]  = PF_ROUTE;         // type of information
		mib[2]  = 0;                // protocol (IPPROTO_xxx)
		mib[3]  = 0;                // address family
		mib[4]  = NET_RT_IFLIST2;   // operation
		mib[5]  = 0;

		sysctl(mib, 6, NULL, &len, NULL, 0);
		buf = new char[len];
		sysctl(mib, 6, buf, &len, NULL, 0);
		lim = buf + len;
		for (next = buf; next < lim; ) {
			ifm = (struct if_msghdr *)next;
			next += ifm->ifm_msglen;

			if (ifm->ifm_type == RTM_IFINFO2) {
				struct if_msghdr2   *if2m = (struct if_msghdr2 *)ifm;

				if(if2m->ifm_data.ifi_type!=18) { /* do not count loopback traffic */
					obytes   += if2m->ifm_data.ifi_obytes;
					ibytes   += if2m->ifm_data.ifi_ibytes;
				}
			}
		}

		int64_t delta_obytes = obytes - prev_obytes;
		int64_t delta_ibytes = ibytes - prev_ibytes;

		delete [] buf;

		prev_ibytes = ibytes;
		prev_obytes = obytes;

		data.clear();
		data.push_back(" Networking ");
		std::ostringstream sstr;
		if (k)
			sstr << " input:  " << delta_ibytes / (1024) << "Ko/s  ";
		else
			sstr << " input:  " << 0 << "Ko/s    ";
		data.push_back(sstr.str());
		sstr.str("");
		if (k)
			sstr << " output: " << delta_obytes / (1024) << "Ko/s  ";
		else
			sstr << " output: " << 0 << "Ko/s    ";
		data.push_back(sstr.str());
	}
	++k;
}

int								Network::getWidth(void) const
{
	int			ret = 0;

	for (std::vector<std::string>::const_iterator it = this->data.begin(); it != this->data.end(); ++it)
	{
		if ((*it).length() > static_cast<unsigned int>(ret))
			ret = (*it).length();
	}
	return (ret);
}

WINDOW							*Network::initWindow(WINDOW *lastwin, WINDOW *displaywin) const
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

char							Network::getType(void) const
{
	return (this->type);
}

std::string const				&Network::getName(void) const
{
	return (this->name);
}
