#include "Event.h"

using namespace Sim;

Event::Event(double time, EventTypeEnum type) :time{ time }, type{ type }
{
	;;
}

bool Event::operator<(const Event& e) const
{
	return time > e.time;
}

std::ostream& Sim::operator<<(std::ostream& os, Event const& e)
{
	return os << "Event{" << "time=" << e.time << ", type=" << e.type << "}";
}
