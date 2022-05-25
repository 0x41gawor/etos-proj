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
	// czy serwer zaj�ty?
	switch (system->server.status)
	{
		case System::ServerStatusEnum::BUSY:
		{
			// zbierz statystki
			stats->q(*simTime, system->queue.clientsCount);
			// dodaj 1 do liczby klient�w w kolejce
			system->queue.push(System::Client(*simTime));
			break;
		}
		case System::ServerStatusEnum::FREE:
		{
			// ustaw op�nienie=0 dla tego klienta i zbierz statystki
			stats->d(0.0);
			stats->u(*simTime, system->server.status);
			// ustaw stan serwera na zaj�ty
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
			// odejmij 1 od liczby klient�w w kolejce
			System::Client client = *system->queue.pop();
			// oblicz op�nienie klienta i zbierz statystki //dodaj jeden do licznika op�nie� klient�w
			stats->d(*simTime - client.arrivalTime);
			// zaplanuj zdarzenie zako�czenia obs�ugi dla nast�pnego klienta
			eventList->push(Sim::Event(*simTime + libDeparture.run(), Sim::EventTypeEnum::DEPARTURE));
			// przesun ka�dego klienta o jedno miejsce --> w FIFO tego nie potrzebujemy
		}
	}
	return false;
}

bool Events::end()
{
	// tu trzeba doda� co� co pozwoli doko�czy� pobranie eventu Departure z listy zdarze�, poniewa� ostatnia statystyka sie nie nalicza
	// po prostu to jest zadanie RaportGenerator ma on dost�p do statystk, wiec na podstawie lastSimTime i obecnego stanu serwera doliczy koniec
	// TODO
	return true;
}