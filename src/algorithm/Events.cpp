#include "Events.h"

using namespace Algorithm;

Algorithm::Events::Events(Sim::EventList* eventList, double* simTime, System::System* system, Sim::Stats* stats)
	:eventList{ eventList }, simTime{ simTime }, system {system}, stats { stats },
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
			// zbierz statystki
			stats->q(*simTime, system->queue.clientsCount);
			// dodaj 1 do liczby klientów w kolejce
			system->queue.push(System::Client(*simTime));
			break;
		}
		case System::ServerStatusEnum::FREE:
		{
			// ustaw opóŸnienie=0 dla tego klienta i zbierz statystki
			stats->d(0.0);
			stats->u(*simTime, system->server.status);
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
			// zbierz statystki
			stats->u(*simTime, system->server.status);
			// ustaw stan serwera na wolny
			system->server.status = System::ServerStatusEnum::FREE;
			break;
		}
		case false:
		{
			// zbierz statystki
			stats->q(*simTime, system->queue.clientsCount);
			// odejmij 1 od liczby klientów w kolejce
			System::Client client = *system->queue.pop();
			// oblicz opóŸnienie klienta i zbierz statystki //dodaj jeden do licznika opóŸnieñ klientów
			stats->d(*simTime - client.arrivalTime);
			// zaplanuj zdarzenie zakoñczenia obs³ugi dla nastêpnego klienta
			eventList->push(Sim::Event(*simTime + libDeparture.run(), Sim::EventTypeEnum::DEPARTURE));
			// przesun ka¿dego klienta o jedno miejsce --> w FIFO tego nie potrzebujemy
		}
	}
	return false;
}

bool Events::end()
{
	// tu trzeba dodaæ coœ co pozwoli dokoñczyæ pobranie eventu Departure z listy zdarzeñ, poniewa¿ ostatnia statystyka sie nie nalicza
	// po prostu to jest zadanie RaportGenerator ma on dostêp do statystk, wiec na podstawie lastSimTime i obecnego stanu serwera doliczy koniec
	// TODO
	return true;
}