#pragma once
#include <queue>
#include <iostream>
#include <ostream>

#include "Client.h"

namespace System
{
	class Queue
	{
	private:
		std::queue<Client> implementation;
	public:
		int clientsCount;
		bool isEmpty;

		Queue();
		void push(Client client);
		Client* pop();
		void show();
	};

	std::ostream& operator<<(std::ostream& os, Queue const& q);
}
