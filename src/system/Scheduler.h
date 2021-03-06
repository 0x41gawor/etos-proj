#pragma once

#include "Queue.h"
#include "Client.h"
#include "Flows.h"

namespace System
{
	class Scheduler
	{
	private:
		Queue queue_A;
		Queue queue_B;
		int cycle;
		int weightSum;
	public:
		int clientsCount_A;
		int clientsCount_B;
		int clientsCount;
		bool isEmpty;

		Scheduler();
		void push(Client client);
		Client* pop();
		void show();
		friend std::ostream& operator<<(std::ostream& os, Scheduler const& s);
	};
	
}

