#include "Time.h"

using namespace Algorithm;

Algorithm::Time::Time(Sim::EventList* eventList, double* simTime) :eventList{ eventList }, simTime{simTime}
{
	
}

Sim::Event Time::run()
{
	// okreœl kolejny typ zdarzenia
	Sim::Event event = *eventList->pop();
	// zwieksz czas zegara
	*simTime = event.time;

	return event;
}
