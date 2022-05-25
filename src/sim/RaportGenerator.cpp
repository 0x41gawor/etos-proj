#include "RaportGenerator.h"

using namespace Sim;

RaportGenerator::RaportGenerator()
{
}

void RaportGenerator::run(Stats stats, System::System system,  double simTime)
{
	// dolicz ostatnie q
	stats.q(simTime, system.queue.clientsCount);
	// dolicz ostatnie u
	stats.u(simTime, system.server.status);
	// wyswietl wyniki
	std::cout << "Sredni czas oczekiwania w kolejce: " << stats.d_mean << "\n";
	std::cout << "Liczba klientow w kolejce oszacowana w czasie ciaglym: " << stats.q_value << "\n";
	std::cout << "Wykorzystanie serwera obslugi: " << stats.u_value << "\n";
}
