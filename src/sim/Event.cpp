#include "Event.h"


Sim::Event::Event(double time, EventTypeEnum type) :time{ time }, type{ type }
{
	;;
}

std::ostream& Sim::operator<<(std::ostream& os, Event const& e)
{
	return os << "Event{" << "time=" << e.time << ", type=" << e.type << "}";
}
