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
	case Sim::EventTypeEnum::ARRIVAL_A:
		return arrival_A();
	case Sim::EventTypeEnum::ARRIVAL_B:
		return arrival_B();
	case Sim::EventTypeEnum::DEPARTURE:
		return departure();
	}
	return true;
}

bool Events::arrival_A()
{
	//zaplanuj kolejny event Arrival_A
	eventList->push(Sim::Event(*simTime + libArrival.run(System::Flows::mean_A), Sim::EventTypeEnum::ARRIVAL_A));
	system->scheduler.push(System::Client(*simTime, System::FlowEnum::A));
	// czy serwer zajêty?
	switch (system->server.status)
	{
		case System::ServerStatusEnum::BUSY:
		{
			// zbierz statystki 
			stats->q(*simTime, system->scheduler.clientsCount-1);
			stats->q(*simTime, system->scheduler.clientsCount_A-1, System::FlowEnum::A);
			break;
		}
		case System::ServerStatusEnum::FREE:
		{
			// ustaw opóŸnienie=0 dla tego klienta i zbierz statystki 
			stats->d(0.0);
			stats->d(0.0, System::FlowEnum::A);
			stats->u(*simTime, system->server.status);
			// ustaw stan serwera na zajêty
			system->server.status = System::ServerStatusEnum::BUSY;
			// Zdejmij klienta
			system->scheduler.pop();
			//zaplanuj zdarzenie zakonczenia obslugi klienta
			std::cout << "Serverowi dal: " << System::FlowEnum::A << "\n";
			eventList->push(
				Sim::Event(
					*simTime + libDeparture.run(system->server.capacity, System::Flows::getSize(System::FlowEnum::A)), Sim::EventTypeEnum::DEPARTURE
				));
			break;
		}
	}
	return false;
}

bool Events::arrival_B()
{
	//zaplanuj kolejny event Arrival_B
	eventList->push(Sim::Event(*simTime + libArrival.run(System::Flows::mean_B), Sim::EventTypeEnum::ARRIVAL_B));
	system->scheduler.push(System::Client(*simTime, System::FlowEnum::B));
	// czy serwer zajêty?
	switch (system->server.status)
	{
	case System::ServerStatusEnum::BUSY:
	{
		// zbierz statystki 
		stats->q(*simTime, system->scheduler.clientsCount - 1);
		stats->q(*simTime, system->scheduler.clientsCount_B - 1, System::FlowEnum::B);
		break;
	}
	case System::ServerStatusEnum::FREE:
	{
		// ustaw opóŸnienie=0 dla tego klienta i zbierz statystki 
		stats->d(0.0);
		stats->d(0.0, System::FlowEnum::B);
		stats->u(*simTime, system->server.status);
		// ustaw stan serwera na zajêty
		system->server.status = System::ServerStatusEnum::BUSY;
		// Zdejmij klienta
		system->scheduler.pop();
		//zaplanuj zdarzenie zakonczenia obslugi klienta
		std::cout << "Serverowi dal: " << System::FlowEnum::B << "\n";
		eventList->push(
			Sim::Event(
				*simTime + libDeparture.run(system->server.capacity, System::Flows::getSize(System::FlowEnum::B)), Sim::EventTypeEnum::DEPARTURE
			));
		break;
	}
	}
	return false;
}

bool Events::departure()
{
	switch (system->scheduler.isEmpty)
	{
		case true:
		{
			std::cout << "Scheduler: pusty\n";
			// zbierz statystki //TODO
			stats->u(*simTime, system->server.status);
			// ustaw stan serwera na wolny
			system->server.status = System::ServerStatusEnum::FREE;
			break;
		}
		case false:
		{
			// zbierz statystki //TODO
			stats->q(*simTime, system->scheduler.clientsCount);
			// odejmij 1 od liczby klientów w kolejce
			System::Client client = *system->scheduler.pop();
			switch (client.flow)
			{
			case System::FlowEnum::A:
				stats->q(*simTime, system->scheduler.clientsCount_A + 1, System::FlowEnum::A); 
				stats->d(*simTime - client.arrivalTime, System::FlowEnum::A); break;
			case System::FlowEnum::B:
				stats->q(*simTime, system->scheduler.clientsCount_B + 1, System::FlowEnum::B); 
				stats->d(*simTime - client.arrivalTime, System::FlowEnum::B); break;
			}
			std::cout << "Scheduler: "; system->scheduler.show();
			std::cout << "\nServerowi dal: " << client.flow << "\n";
			// oblicz opóŸnienie klienta i zbierz statystki //dodaj jeden do licznika opóŸnieñ klientów //TODO
			stats->d(*simTime - client.arrivalTime);
			// zaplanuj zdarzenie zakoñczenia obs³ugi dla nastêpnego klienta
			eventList->push(
				Sim::Event(
					*simTime + libDeparture.run(system->server.capacity, System::Flows::getSize(client.flow)), Sim::EventTypeEnum::DEPARTURE
				));
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