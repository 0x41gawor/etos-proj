#include "LibArrivalExp.h"

using namespace Algorithm;

double LibArrivalExp::run()
{
	double RND;

	do
	{
		RND = static_cast<double>(rand()) / RAND_MAX;
	} while (RND == 0);

	return -MEAN * log(RND);
}

double Algorithm::LibArrivalExp::run(double mean)
{
	double RND;

	do
	{
		RND = static_cast<double>(rand()) / RAND_MAX;
	} while (RND == 0);

	return -mean * log(RND);
}
