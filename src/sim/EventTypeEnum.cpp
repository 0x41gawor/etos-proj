#include "EventTypeEnum.h"

using namespace Sim;

std::ostream& Sim::operator<<(std::ostream& os, EventTypeEnum const& e)
{
	std::string str = "";
	switch (e)
	{
	case EventTypeEnum::ARRIVAL:
		str = "ARRIVAL"; break;
	case EventTypeEnum::DEPARTURE:
		str = "DEPARTURE"; break;
	case EventTypeEnum::END:
		str = "END"; break;
	}
	return os << str;
}