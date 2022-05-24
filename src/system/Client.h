#pragma once

#include <ostream>


namespace System
{
	class Client
	{
	public:																			// < M E M B E R S >
		double arrivalTime;
	public:																			// < M E T H O D S >
		Client(double arrivalTime);
	};

	std::ostream& operator<<(std::ostream& os, Client const& c);
}

