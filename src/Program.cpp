#include "Program.h"

Program::Program() : simTime{0.0}
{
	system = System::System();
	eventList = Sim::EventList();
	stats = Sim::Stats();
	raportGenerator = Sim::RaportGenerator();
	algorithmInit = Algorithm::Init();
	algorithmTime = Algorithm::Time();
	algorithmEvent = Algorithm::Events();
}

void Program::run()
{
	algorithmInit.run(&eventList);
	eventList.show();
	bool end = false;
	
	while (!end)
	{
		Sim::Event event = algorithmTime.run();
		end = algorithmEvent.run(event);
	}
	raportGenerator.run(stats);
}
