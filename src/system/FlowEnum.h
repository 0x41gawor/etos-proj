#pragma once

#include <ostream>

namespace System
{
	enum class FlowEnum
	{
		A,
		B
	};

	std::ostream& operator<<(std::ostream& os, FlowEnum const& f);
}

