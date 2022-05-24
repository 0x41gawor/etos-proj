#pragma once

#include "EventTypeEnum.h"

namespace Sim
{
	class Event
	{
	public:
		double time;
		EventTypeEnum type;

		Event(double time, EventTypeEnum type);
	};

	std::ostream& operator<<(std::ostream& os, Event const& e);

}
