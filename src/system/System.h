#pragma once
#include <ostream>

#include "Server.h"
#include "Queue.h"

namespace System
{
	class System
	{
	public:
		Server server;
		Queue queue;
	public:
		System();
		void init();
	};

	std::ostream& operator<<(std::ostream& os, System const& s);
}

