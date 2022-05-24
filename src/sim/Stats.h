#pragma once

#include <ostream>

namespace Sim
{
	class Stats
	{
	public:
		double d_accumulated;
		double d_number;
		double d_mean;

		double q_rects;
		double q_lastSimTime;
		double q_value;

		double u_rects;
		double u_lastSimTime;
		double u_value;
	public:
		Stats();
		void d(); //params will be decided later
		void q(); //params will be decided later
		void u(); //params will be decided later
	};

	std::ostream& operator<<(std::ostream& os, Stats const& e);
}
