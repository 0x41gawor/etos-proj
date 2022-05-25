#include "Time.h"

using namespace Algorithm;

Sim::Event Time::run()
{
	Sim::Event event = Sim::Event(2.0, Sim::EventTypeEnum::END);

	return event;
}
