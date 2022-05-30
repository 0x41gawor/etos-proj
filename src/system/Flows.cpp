#include "Flows.h"

double System::Flows::getSize(FlowEnum flow)
{
	switch (flow)
	{
	case System::FlowEnum::A:
		return size_A;
	case System::FlowEnum::B:
		return size_B;
	}
}
