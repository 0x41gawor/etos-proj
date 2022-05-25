#include "Init.h"
#include <stdlib.h>

using namespace Algorithm;

void Init::run(Sim::EventList* eventList, double* simTime)
{
	srand(static_cast<unsigned int>(time(0)));
	*simTime = 0.0;

	eventList->push(Sim::Event(2.0, Sim::EventTypeEnum::ARRIVAL));
	eventList->push(Sim::Event(5.3, Sim::EventTypeEnum::ARRIVAL));
	eventList->push(Sim::Event(4.2, Sim::EventTypeEnum::ARRIVAL));
	eventList->push(Sim::Event(9.8, Sim::EventTypeEnum::ARRIVAL));
	eventList->push(Sim::Event(7.4, Sim::EventTypeEnum::ARRIVAL));
	eventList->push(Sim::Event(10.0, Sim::EventTypeEnum::END));
}
