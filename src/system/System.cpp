#include "System.h"


System::System::System()
{
}

void System::System::init()
{
	server = Server();
	queue = Queue();
}

std::ostream& System::operator<<(std::ostream& os, System const& s)
{
	return os << "System{server=" << s.server << ", queue=" << s.queue << "}";
}
