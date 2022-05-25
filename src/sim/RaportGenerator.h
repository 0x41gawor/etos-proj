#pragma once

#include "Stats.h"
#include "../system/System.h"

namespace Sim
{
	class RaportGenerator
	{
	public:																			// < M E M B E R S>
		RaportGenerator();
		void run(Stats stats, System::System system, double simTime);
	};
}

