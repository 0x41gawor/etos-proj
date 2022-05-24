#pragma once

#include "ServerStatusEnum.h"

#include <ostream>


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
