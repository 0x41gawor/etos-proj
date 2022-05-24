#include "Init.h"
#include <stdlib.h>

using namespace Algorithm;

void Init::run(Sim::EventList* eventList)
{
	//TODO implement
	srand(static_cast<unsigned int>(time(0)));

	eventList->push(Sim::Event(2.0, Sim::EventTypeEnum::END));
}
