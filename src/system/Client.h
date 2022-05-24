#pragma once

#include <ostream>


namespace System
{
	class Client
	{
	public:
		double arrivalTime;

		Client(double arrivalTime);
	};

	std::ostream& operator<<(std::ostream& os, Client const& c);
}

