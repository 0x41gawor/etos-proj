#include "Events.h"

using namespace Algorithm;

bool Events::run(Sim::Event event)
{
	switch (event.type)
	{
	case Sim::EventTypeEnum::END:
		return end();
	case Sim::EventTypeEnum::ARRIVAL:
		return arrival();
	case Sim::EventTypeEnum::DEPARTURE:
		return departure();
	}
	return true;
}

bool Events::arrival()
{
	//TODO implement
	return false;
}

bool Events::departure()
{
	//TODO implement
	return false;
}

bool Events::end()
{
	return true;
}