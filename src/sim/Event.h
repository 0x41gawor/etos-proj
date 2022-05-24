#pragma once

#include "EventTypeEnum.h"

namespace Sim
{
	class Event
	{
	public:																			// < M E M B E R S >
		double time;
		EventTypeEnum type;
	public:																			// < M E T H O D S >
		Event(double time, EventTypeEnum type);

		bool operator<(const Event& e) const;
	};

	std::ostream& operator<<(std::ostream& os, Event const& e);

}
