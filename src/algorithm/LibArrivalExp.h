#pragma once

#include "ILibArrival.h"

#include <stdlib.h>
#include <cmath>

namespace Algorithm
{
	class LibArrivalExp : ILibArrival
	{
	public:
		double MEAN = 10.0;
	public:
		double run();
	};
}

