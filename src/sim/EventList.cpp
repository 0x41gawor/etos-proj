#include "EventList.h"

using namespace Sim;

Sim::EventList::EventList()
{
	implementation = std::priority_queue<Event>();
}

Event* Sim::EventList::pop()
{
	if (!implementation.empty())
	{
		Event event = implementation.top();
		implementation.pop();
		return &event;
	}
	return NULL;
}

void Sim::EventList::push(Event event)
{
	implementation.push(event);
}

void Sim::EventList::show()
{
	std::priority_queue<Event> copy = implementation;
	std::cout << "EventList:[";
	while (!copy.empty()) {
		std::cout << " " << copy.top();
		copy.pop();
		if (copy.size() > 1) std::cout << ",";
	}
	std::cout << " ]\n";
}
