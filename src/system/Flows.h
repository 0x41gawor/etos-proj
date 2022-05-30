#pragma once
#include "FlowEnum.h"

namespace System
{
	static class Flows
	{
	public:
		static const int weight_A = 6; // A has to be a flow with greater weight!!
		static const int weight_B = 1;
		double size_A = 5.0;
		double size_B = 5.0;
		double mean_A = 2.0;
		double mean_B = 2.0;

		double getSize(FlowEnum flow);
	};

}