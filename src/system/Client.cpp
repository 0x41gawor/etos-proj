#include "Client.h"

using namespace System;

Client::Client(double arrivalTime):arrivalTime(arrivalTime), flow{FlowEnum::A}
{
	;;
}

System::Client::Client(double arrivalTime, FlowEnum flow): arrivalTime(arrivalTime), flow{flow}
{
}

std::ostream& System::operator<<(std::ostream& os, Client const& c)
{
	return os << "Client{arrivalTime=" << c.arrivalTime <<", flow= " <<c.flow << "}";
}
