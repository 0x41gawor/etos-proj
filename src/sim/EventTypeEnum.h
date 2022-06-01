#pragma once

#include <ostream>

namespace Sim
{
	enum class EventTypeEnum
	{
		ARRIVAL_A,
		ARRIVAL_B,
		DEPARTURE,
		END
	};

	std::ostream& operator<<(std::ostream& os, EventTypeEnum const& e);
}

