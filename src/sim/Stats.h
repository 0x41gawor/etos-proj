#pragma once

#include "../system/ServerStatusEnum.h"

#include <ostream>
#include <iostream>

namespace Sim
{
	class Stats
	{
	public:																			// < M E M B E R S >
		double d_accumulated;
		double d_number;
		double d_mean;

		double q_rects;
		double q_lastSimTime;
		double q_value;

		double u_rects;
		double u_lastSimTime;
		double u_value;
	public:																			// < M E T H O D S >
		Stats();
		void d(double delay); 
		void q(); //params will be decided later
		void u(double simTime, System::ServerStatusEnum status); 
	};

	std::ostream& operator<<(std::ostream& os, Stats const& e);
}
