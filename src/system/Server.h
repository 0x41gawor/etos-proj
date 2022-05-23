#pragma once
#include <ostream>

#include "ServerStatusEnum.h"

namespace System
{
	class Server
	{
	public:
		ServerStatusEnum status;

		Server();
	};

	std::ostream& operator<<(std::ostream& os, Server const& s);
}
