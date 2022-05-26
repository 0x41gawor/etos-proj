#pragma once

#include "ILibDeparture.h"

#include <stdlib.h>
#include <cmath>

namespace Algorithm
{
	class LibDepartureExp : public ILibDeparture
	{
	public:
		double MEAN = 1.0;
	public:
		double run();
	};

}
