#pragma once

#include "../system/ServerStatusEnum.h"
#include "../system/FlowEnum.h"

#include <ostream>
#include <iostream>

namespace Sim
{
	class Stats
	{
	public:																			// < M E M B E R S >
		double d_accumulated[3];
		double d_number[3];
		double d_mean[3];

		double q_rects[3];
		double q_lastSimTime[3];
		double q_value[3];

		double u_rects;
		double u_lastSimTime;
		double u_value;
	public:																			// < M E T H O D S >
		Stats();
		void d(double delay);														// overall delay
		void d(double delay, System::FlowEnum flow);								// delay for specific flow
		void q(double simTime, int);												// overall queue.count
		void q(double simTime, int, System::FlowEnum flow);							// queue.count for specific flow	
		void u(double simTime, System::ServerStatusEnum status); 
	};

	std::ostream& operator<<(std::ostream& os, Stats const& e);
}
