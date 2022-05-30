#pragma once

#include "ILibDeparture.h"

#include <stdlib.h>
#include <cmath>

namespace Algorithm
{
	class LibDepartureExp : public ILibDeparture
	{
	public:
		double MEAN = 1.25;
	public:
		double run();
		double run(double capacity, double size);
	};

}
