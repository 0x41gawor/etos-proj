#include "Init.h"
#include <stdlib.h>

using namespace Algorithm;

void Init::run(Sim::EventList* eventList, double* simTime)
{
	// inicjalizacja stanu systemu i licznik�w statystyk
	srand(static_cast<unsigned int>(time(0)));
	*simTime = 0.0;
	// inicjalizacja listy zdarze�
	eventList->push(Sim::Event(1.0, Sim::EventTypeEnum::ARRIVAL_A));
	eventList->push(Sim::Event(1.0, Sim::EventTypeEnum::ARRIVAL_B));
	eventList->push(Sim::Event(10.0, Sim::EventTypeEnum::END));
}
