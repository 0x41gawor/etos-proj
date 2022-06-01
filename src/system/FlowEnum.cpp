#include "FlowEnum.h"

using namespace System;

std::ostream& System::operator<<(std::ostream& os, FlowEnum const& f)
{
	std::string str = "";
	switch (f)
	{
	case FlowEnum::A:
		str = "A"; break;
	case FlowEnum::B:
		str = "B"; break;
	}
	return os << str;
}