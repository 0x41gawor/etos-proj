#pragma once
#include <ostream>

namespace Sim
{
	enum class EventTypeEnum
	{
		ARRIVAL,
		DEPARTURE,
		END
	};

	std::ostream& operator<<(std::ostream& os, EventTypeEnum const& e);
}

