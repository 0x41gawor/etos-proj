#pragma once

#include "../sim/EventList.h"

namespace Algorithm
{
	class Time
	{
	private:																		// < M E M B E R S >
		Sim::EventList* eventList; // Algorithm::Time needs constant reference to eventList to pop out events from it
		double* simTime;			// Algorithm::Time needs constant reference to simTime set its value to the popped event.time
	public:																			// < M E T H O D S >
		Time(Sim::EventList* eventList, double* simTime);
		Sim::Event run();
	};
}

