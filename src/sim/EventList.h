#pragma once

#include "Event.h"

#include <queue>
#include <iostream>

namespace Sim
{
	class EventList
	{
	private:																		// < M E M B E R S >
		std::priority_queue<Event> implementation;
	public:																			// < M E T H O D S >
		EventList();
		Event* pop();
		void push(Event e);
		void show();
	};
}

