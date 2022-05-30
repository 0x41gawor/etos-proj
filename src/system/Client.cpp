#include "Client.h"

using namespace System;

Client::Client(double arrivalTime):arrivalTime(arrivalTime)
{
	;;
}

System::Client::Client(double arrivalTime, FlowEnum flow): arrivalTime(arrivalTime), flow{flow}
{
}

std::ostream& System::operator<<(std::ostream& os, Client const& c)
{
	return os << "Client{arrivalTime=" << c.arrivalTime << "}";
}
