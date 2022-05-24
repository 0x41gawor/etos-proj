#pragma once

#include "system/System.h"
#include "sim/EventList.h"
#include "sim/Stats.h"
#include "sim/RaportGenerator.h"
#include "algorithm/Init.h"
#include "algorithm/Time.h"
#include "algorithm/Events.h"

class Program
{
	System::System system;
	Sim::EventList eventList;
	double simTime;
	Sim::Stats stats;
	Sim::RaportGenerator raportGenerator;
	Algorithm::Init algorithmInit;
	Algorithm::Time algorithmTime;
	Algorithm::Events algorithmEvent;
public:
	Program();
	void run();

};

