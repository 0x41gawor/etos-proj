#pragma once
#include "FlowEnum.h"

namespace System
{
	class Flows
	{
	public:
		static const int weight_A = 5; // A has to be a flow with greater weight!!
		static const int weight_B = 1;
		static constexpr double size_A = 5.0;
		static constexpr double size_B = 5.0;
		static constexpr double mean_A = 1.0;
		static constexpr double mean_B = 5.0;

		static double getSize(FlowEnum flow);
	};

}