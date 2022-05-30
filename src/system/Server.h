#pragma once

#include "ServerStatusEnum.h"

#include <ostream>


namespace System
{
	class Server
	{
	public:																			// < M E M B E R S >
		ServerStatusEnum status;
		double capacity;
	public:																			// < M E T H O D S >
		Server();
	};

	std::ostream& operator<<(std::ostream& os, Server const& s);
}
