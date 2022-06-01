#include "System.h"


System::System::System()
{
}

void System::System::init()
{
	server = Server();
	scheduler = Scheduler();
}

std::ostream& System::operator<<(std::ostream& os, System const& s)
{
	return os << "System{server=" << s.server << ", queue=" << s.scheduler << "}";
}
