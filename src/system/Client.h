#pragma once

#include "FlowEnum.h"

#include <ostream>


namespace System
{
	class Client
	{
	public:																			// < M E M B E R S >
		double arrivalTime;
		FlowEnum flow;
	public:																			// < M E T H O D S >
		Client(double arrivalTime);
		Client(double arrivalTime, FlowEnum flow);
	};

	std::ostream& operator<<(std::ostream& os, Client const& c);
}

