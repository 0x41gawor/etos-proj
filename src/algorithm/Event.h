#pragma once

#include "../sim/Event.h"

namespace Algorithm
{
	class Event
	{
	public:																			// < M E T H O D S >
		bool run(Sim::Event);
	private:
		bool arrival();
		bool departure();
		bool end();
	};

}
