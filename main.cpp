#include "src/algorithm/LibArrivalExp.h"
#include "src/algorithm/LibDepartureExp.h"

#include <iostream>
#include <time.h>




int main()
{
	srand(static_cast<unsigned int>(time(0))); // place it in init

	///*
	Algorithm::LibDepartureExp libArrival;

	double sum{0};
	for (int i = 0; i < 10000; i++)
	{
		double x = libArrival.run();
		sum += x;
		std::cout << x <<"\n";
	}
	std::cout << "Mean = " << sum / 10000.0;
   //*/
}