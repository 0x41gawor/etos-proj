#include "Program.h"

Program::Program() : simTime{0.0}, algorithmTime{&eventList, &simTime}
{
	system = System::System();
	eventList = Sim::EventList();
	stats = Sim::Stats();
	raportGenerator = Sim::RaportGenerator();
	algorithmInit = Algorithm::Init();
	algorithmEvent = Algorithm::Events();
}

void Program::run()
{
	algorithmInit.run(&eventList, &simTime);
	eventList.show();
	bool end = false;
	
	while (!end)
	{
		Sim::Event event = algorithmTime.run();
		std::cout << "Event popped = " << event << ", simTime = " << simTime << "\n";
		end = algorithmEvent.run(event);
	}
	raportGenerator.run(stats);
}
