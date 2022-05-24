#include "Stats.h"

Sim::Stats::Stats() 
	:d_accumulated{ 0 }, d_number{ 0 }, d_mean{ 0 },
	q_rects{ 0 }, q_lastSimTime{ 0 }, q_value{ 0 },
	u_rects{ 0 }, u_lastSimTime{ 0 }, u_value{ 0 }
{
	;;
}

void Sim::Stats::d()
{
	//TODO implement
}

void Sim::Stats::q()
{
	//TODO implement
}

void Sim::Stats::u()
{
	//TODO implement
}

std::ostream& Sim::operator<<(std::ostream& os, Stats const& s)
{
	return os << "Stats{d_accumulated=" << s.d_accumulated
		<< ", d_number=" << s.d_number
		<< ", d_mean=" << s.d_mean
		<< ", q_rects=" << s.q_rects
		<< ", q_lastSimTime=" << s.q_lastSimTime
		<< ", q_value=" << s.q_value
		<< ", u_rects=" << s.u_rects
		<< ", u_lastSimTime=" << s.u_lastSimTime
		<< ", u_value=" << s.u_value
		<< "}";
}
