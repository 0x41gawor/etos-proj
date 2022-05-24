#include "LibArrival.h"

using namespace Algorithm;

double LibArrival::run()
{
	double RND;

	do
	{
		RND = static_cast<double>(rand()) / RAND_MAX;
	} while (RND == 0);

	return -MEAN * log(RND);
}
