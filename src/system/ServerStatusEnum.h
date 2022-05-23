#pragma once
#include <ostream>


namespace System
{
	enum class ServerStatusEnum
	{
		FREE = 0,
		BUSY
	};

	std::ostream& operator<<(std::ostream& os, ServerStatusEnum const& e);
}

