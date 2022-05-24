#pragma once

#include "Event.h"
#include <queue>

namespace Sim
{
	class EventList
	{
	private:
		std::priority_queue<Event> implementation;

	public:
		EventList();
		Event* pop();
		void push(Event e);
		void show();
	};
}

