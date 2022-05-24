#pragma once

#include "ILibDeparture.h"

#include <stdlib.h>
#include <cmath>

namespace Algorithm
{
	class LibDepartureExp : ILibDeparture
	{
	public:
		double MEAN = 7.0;
	public:
		double run();
	};

}
