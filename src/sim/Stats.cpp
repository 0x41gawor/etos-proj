#include "Stats.h"


using namespace Sim;

Sim::Stats::Stats() 
	:d_accumulated{ 0 }, d_number{ 0 }, d_mean{ 0 },
	q_rects{ 0 }, q_lastSimTime{ 0 }, q_value{ 0 },
	u_rects{ 0 }, u_lastSimTime{ 0 }, u_value{ 0 }
{
	;;
}

void Stats::d(double delay)
{
	d_accumulated += delay;
	d_number++;
	d_mean = d_accumulated / d_number;
}

void Stats::q(double simTime, int clientsCount)
{
	double timeInterval = simTime - q_lastSimTime;
	q_lastSimTime = simTime;
	double rect = timeInterval * clientsCount;
	q_rects += rect;
	q_value = q_rects / simTime;
}

void Stats::u(double simTime, System::ServerStatusEnum status)
{
	double timeInterval = simTime - u_lastSimTime;
	u_lastSimTime = simTime;
	double rect = timeInterval * static_cast<double>(status);
	u_rects += rect;
	u_value = u_rects / simTime;
	std::cout << "\n" << u_value << "\n";
}

std::ostream& operator<<(std::ostream& os, Stats const& s)
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
