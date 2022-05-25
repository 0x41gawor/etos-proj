#pragma once

#include "../sim/EventList.h"

namespace Algorithm
{
	class Time
	{
	private:																		// < M E M B E R S >
		Sim::EventList* eventList;
		double* simTime;
	public:																			// < M E T H O D S >
		Time(Sim::EventList* eventList, double* simTime);
		Sim::Event run();
	};
}

