#include "Init.h"
#include <stdlib.h>

using namespace Algorithm;

void Init::run(Sim::EventList* eventList, double* simTime)
{
	// inicjalizacja stanu systemu i liczników statystyk
	srand(static_cast<unsigned int>(time(0)));
	*simTime = 0.0;
	// inicjalizacja listy zdarzeñ
	eventList->push(Sim::Event(2.0, Sim::EventTypeEnum::ARRIVAL));
	eventList->push(Sim::Event(100.0, Sim::EventTypeEnum::END));
}
