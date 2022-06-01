#include "EventTypeEnum.h"

using namespace Sim;

std::ostream& Sim::operator<<(std::ostream& os, EventTypeEnum const& e)
{
	std::string str = "";
	switch (e)
	{
	case EventTypeEnum::ARRIVAL_A:
		str = "ARRIVAL_A"; break;
	case EventTypeEnum::ARRIVAL_B:
		str = "ARRIVAL_B"; break;
	case EventTypeEnum::DEPARTURE:
		str = "DEPARTURE"; break;
	case EventTypeEnum::END:
		str = "END"; break;
	}
	return os << str;
}