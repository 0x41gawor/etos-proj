#include "Time.h"

using namespace Algorithm;

Algorithm::Time::Time(Sim::EventList* eventList, double* simTime) :eventList{ eventList }, simTime{simTime}
{
	
}

Sim::Event Time::run()
{
	Sim::Event event = *eventList->pop();
	*simTime = event.time;

	return event;
}
