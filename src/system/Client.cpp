#include "Client.h"

System::Client::Client(double arrivalTime):arrivalTime(arrivalTime)
{
	;;
}

std::ostream& System::operator<<(std::ostream& os, Client const& c)
{
	return os << "Client{arrivalTime=" << c.arrivalTime << "}";
}
