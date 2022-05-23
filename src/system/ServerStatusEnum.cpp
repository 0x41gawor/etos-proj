#include "ServerStatusEnum.h"

using namespace System;

std::ostream& System::operator<<(std::ostream& os, ServerStatusEnum const& e)
{
	std::string str = "";
	switch (e)
	{
	case ServerStatusEnum::FREE:
		str = "Arrival"; break;
	case ServerStatusEnum::BUSY:
		str = "Processing"; break;
	}
	return os << str;
}
