#pragma once

#include "Server.h"
#include "Queue.h"

#include <ostream>


namespace System
{
	class System
	{
	public:																			// < M E M B E R S >
		Server server;
		Queue queue;
	public:																			// < M E T H O D S >
		System();
		void init();
	};

	std::ostream& operator<<(std::ostream& os, System const& s);
}

