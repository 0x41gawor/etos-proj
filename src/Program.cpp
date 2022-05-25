#include "Program.h"

Program::Program() : simTime{0.0}, algorithmTime{&eventList, &simTime}, algorithmEvent{&eventList, &simTime, &system, &stats}
{
	system = System::System();
	eventList = Sim::EventList();
	stats = Sim::Stats();
	raportGenerator = Sim::RaportGenerator();
	algorithmInit = Algorithm::Init();
}

void Program::run()
{
	// wywo³adnie algorytmu inijalizuj¹cego
	algorithmInit.run(&eventList, &simTime);
	eventList.show();
	bool end = false;
	
	while (!end) // koniec symulacji?
	{
		// wywo³anie algorytmu czasowego
		Sim::Event event = algorithmTime.run();
		std::cout << "Event popped = " << event << ", simTime = " << simTime << "\n";
		// wowo³anie algorytmu zdarzeniowego
		end = algorithmEvent.run(event);
	}
	eventList.show();
	std::cout << "Sredni czas oczekiwania w kolejce: " << stats.d_mean << "\n";
	std::cout << "Wykorzystanie serwera obslugi: " << stats.u_value << "\n";
	std::cout << "Liczba czasow w kolejce oszacowana w czasie ciaglym: " << stats.u_value << "\n";
	// oblicz interesuj¹ce estymacje
	// sporz¹dŸ raport
	raportGenerator.run(stats);
}
