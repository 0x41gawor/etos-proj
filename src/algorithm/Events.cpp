#include "Events.h"

using namespace Algorithm;

Algorithm::Events::Events(Sim::EventList* eventList, double* simTime, System::System* system) 
	:eventList{ eventList }, simTime{ simTime }, system {system},
	libArrival{}, libDeparture{}
{
	
}

bool Events::run(Sim::Event event)
{
	switch (event.type)
	{
	case Sim::EventTypeEnum::END:
		return end();
	case Sim::EventTypeEnum::ARRIVAL:
		return arrival();
	case Sim::EventTypeEnum::DEPARTURE:
		return departure();
	}
	return true;
}

bool Events::arrival()
{
	//zaplanuj kolejne ArrivalEvent
	eventList->push(Sim::Event(*simTime + libArrival.run(), Sim::EventTypeEnum::ARRIVAL));
	// czy serwer zajêty?
	switch (system->server.status)
	{
		case System::ServerStatusEnum::BUSY:
		{
			// dodaj 1 do liczby klientów w kolejce
			system->queue.push(System::Client(*simTime));
		}
		case System::ServerStatusEnum::FREE:
		{
			// ustaw stan serwera na zajêty
			system->server.status = System::ServerStatusEnum::BUSY;
			//zaplanuj zdarzenie zakonczenia obslugi klienta
			eventList->push(Sim::Event(* simTime + libDeparture.run(), Sim::EventTypeEnum::DEPARTURE));
		}
	}
	return false;
}

bool Events::departure()
{
	//TODO implement
	return false;
}

bool Events::end()
{
	return true;
}