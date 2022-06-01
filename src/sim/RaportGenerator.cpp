#include "RaportGenerator.h"
#include "../system/FlowEnum.h"

using namespace Sim;

RaportGenerator::RaportGenerator()
{
}

void RaportGenerator::run(Stats stats, System::System system,  double simTime)
{
	// dolicz ostatnie q
	stats.q(simTime, system.scheduler.clientsCount);
	stats.q(simTime, system.scheduler.clientsCount_A, System::FlowEnum::A);
	stats.q(simTime, system.scheduler.clientsCount_B, System::FlowEnum::B);
	// dolicz ostatnie u
	stats.u(simTime, system.server.status);
	// wyswietl wyniki
	std::cout << "\n\n R A P O R T \n\n";
	std::cout << "===================Sumarycznie====================\n";
	std::cout << "Sredni czas oczekiwania w kolejce: " << stats.d_mean[0] << "\n";
	std::cout << "Liczba klientow w kolejce oszacowana w czasie ciaglym: " << stats.q_value[0] << "\n";
	std::cout << "Wykorzystanie serwera obslugi: " << stats.u_value << "\n";
	std::cout << "====================Strumien A====================\n";
	std::cout << "Sredni czas oczekiwania w kolejce: " << stats.d_mean[1] << "\n";
	std::cout << "Liczba klientow w kolejce oszacowana w czasie ciaglym: " << stats.q_value[1] << "\n";
	std::cout << "Liczba obsluzonych klientow: " << stats.d_number[1] << "\n";
	std::cout << "====================Strumien B====================\n";
	std::cout << "Sredni czas oczekiwania w kolejce: " << stats.d_mean[2] << "\n";
	std::cout << "Liczba klientow w kolejce oszacowana w czasie ciaglym: " << stats.q_value[2] << "\n";
	std::cout << "Liczba obsluzonych klientow: " << stats.d_number[2] << "\n";
}
