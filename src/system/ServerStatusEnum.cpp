#include "ServerStatusEnum.h"

using namespace System;

std::ostream& System::operator<<(std::ostream& os, ServerStatusEnum const& e)
{
	std::string str = "";
	switch (e)
	{
	case ServerStatusEnum::FREE:
		str = "FREE"; break;
	case ServerStatusEnum::BUSY:
		str = "BUSY"; break;
	}
	return os << str;
}
