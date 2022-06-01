#include "Scheduler.h"

using namespace System;

Scheduler::Scheduler() :cycle{ 1 }, weightSum{ Flows::weight_A + Flows::weight_B }, clientsCount_A{ 0 }, clientsCount_B{ 0 }, isEmpty{ true }, clientsCount{ 0 }
{

}

void Scheduler::push(Client client)
{
	switch (client.flow)
	{
	case FlowEnum::A:
		queue_A.push(client);
		break;
	case FlowEnum::B:
		queue_B.push(client);
		break;
	}
	clientsCount_A = queue_A.clientsCount;
	clientsCount_B = queue_B.clientsCount;
	clientsCount = clientsCount_A + clientsCount_B;
	isEmpty = (0 == clientsCount_A + clientsCount_B);
}

Client* Scheduler::pop()
{
	if (cycle <= Flows::weight_A)
	{
		if (queue_A.isEmpty == false)
		{
			cycle++;
			if (cycle > weightSum) cycle = 1;
			Client* client =  queue_A.pop();
			clientsCount_A = queue_A.clientsCount;
			clientsCount = clientsCount_A + clientsCount_B;
			isEmpty = (0 == clientsCount_A + clientsCount_B);
			return client;
		}
		else
		{
			if (queue_B.isEmpty == false)
			{
				cycle = Flows::weight_A+1+1;
				if (cycle > weightSum) cycle = 1;
				Client* client = queue_B.pop();
				clientsCount_B = queue_B.clientsCount;
				clientsCount = clientsCount_A + clientsCount_B;
				isEmpty = (0 == clientsCount_A + clientsCount_B);
				return client;
			}
			else
			{
				return NULL;
			}
		}
	}
	else
	{
		if (queue_B.isEmpty == false)
		{
			cycle++;
			if (cycle > weightSum) cycle = 1;
			Client* client = queue_B.pop();
			clientsCount_B = queue_B.clientsCount;
			clientsCount = clientsCount_A + clientsCount_B;
			isEmpty = (0 == clientsCount_A + clientsCount_B);
			return client;
		}
		else
		{
			if (queue_A.isEmpty == false)
			{
				cycle = 0 + 1 + 1;
				if (cycle > weightSum) cycle = 1;
				Client* client = queue_A.pop();
				clientsCount_A = queue_A.clientsCount;
				clientsCount = clientsCount_A + clientsCount_B;
				isEmpty = (0 == clientsCount_A + clientsCount_B);
				return client;
			}
			else
			{
				return NULL;
			}
		}
	}
	return NULL;
}

void System::Scheduler::show()
{
	std::cout << "Queue A:"; queue_A.show(); 
	std::cout << "Queue B:"; queue_B.show(); 
}

std::ostream& System::operator<<(std::ostream& os, Scheduler const& s)
{
	return os
		<< "Scheduler{queue_A=" << s.queue_A
		<< ", queue_B=" << s.queue_B 
		<< ", cycle=" << s.cycle
		<< ", weightSum=" << s.weightSum
		<< ", clientsCount_A=" << s.clientsCount_A
		<< ", clientsCount_B=" << s.clientsCount_B
		<< ", isEmpty=" << s.isEmpty
		<< "}";
}
