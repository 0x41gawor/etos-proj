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
			break;
		}
		case System::ServerStatusEnum::FREE:
		{
			// ustaw stan serwera na zajêty
			system->server.status = System::ServerStatusEnum::BUSY;
			//zaplanuj zdarzenie zakonczenia obslugi klienta
			eventList->push(Sim::Event(*simTime + libDeparture.run(), Sim::EventTypeEnum::DEPARTURE));
			break;
		}
	}
	return false;
}

bool Events::departure()
{
	switch (system->queue.isEmpty)
	{
		case true:
		{
			// ustaw stan serwera na wolny
			system->server.status = System::ServerStatusEnum::FREE;
			break;
		}
		case false:
		{
			// odejmij 1 od liczby klientów w kolejce
			System::Client client = *system->queue.pop();
			// zaplanuj zdarzenie zakoñczenia obs³ugi dla nastêpnego klienta
			eventList->push(Sim::Event(*simTime + libDeparture.run(), Sim::EventTypeEnum::DEPARTURE));
			// przesun ka¿dego klienta o jedno miejsce --> w FIFO tego nie potrzebujemy
		}
	}
	return false;
}

bool Events::end()
{
	return true;
}