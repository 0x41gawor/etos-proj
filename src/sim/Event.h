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

		bool operator<(const Event& e) const;
	};

	std::ostream& operator<<(std::ostream& os, Event const& e);

}
