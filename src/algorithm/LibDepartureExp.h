#pragma once

#include "ILibDeparture.h"

#include <stdlib.h>
#include <cmath>

namespace Algorithm
{
	class LibDepartureExp : public ILibDeparture
	{
	public:
		double MEAN = 2.0;
	public:
		double run();
	};

}
