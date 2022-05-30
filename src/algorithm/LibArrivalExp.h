#pragma once

#include "ILibArrival.h"

#include <stdlib.h>
#include <cmath>

namespace Algorithm
{
	class LibArrivalExp : public ILibArrival
	{
	public:
		double MEAN = 2.0;
	public:
		double run();
		double run(double mean);
	};
}

