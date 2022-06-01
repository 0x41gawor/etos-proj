#pragma once

#include "../sim/EventList.h"
#include "../system/System.h"
#include "../sim/Stats.h"
#include "../system/Flows.h"
#include "LibArrivalExp.h"
#include "LibDepartureExp.h"

namespace Algorithm
{
	class Events
	{
	private:																		// < M E M B E R S >
		Sim::EventList* eventList;		// Algorithm::Events needs constant reference to eventList to plan out new events of type
		double* simTime;				// Algorithm::Events needs constant reference to simTime to push new events
		System::System* system;			// Algorithm::Events needs constant reference to system (server and queue)
		Sim::Stats* stats;				// Algorithm::Events needs constant reference to stats
		LibArrivalExp libArrival;
		LibDepartureExp libDeparture;
		
		
	public:																			// < M E T H O D S >
		Events(Sim::EventList* eventList, double* simTime, System::System* system, Sim::Stats* stats);
		bool run(Sim::Event);
	private:
		bool arrival_A();
		bool arrival_B();
		bool departure();
		bool end();
	};

}
