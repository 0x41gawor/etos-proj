#pragma once

#include "Event.h"

#include <queue>
#include <iostream>

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

