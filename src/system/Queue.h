#pragma once

#include "Client.h"

#include <queue>
#include <iostream>
#include <ostream>

namespace System
{
	class Queue
	{
	private:																		// < M E M B E R S >
		std::queue<Client> implementation;
	public:
		int clientsCount;
		bool isEmpty;
	public:																			// < M E T H O D S >
		Queue();
		void push(Client client);
		Client* pop();
		void show();
	};

	std::ostream& operator<<(std::ostream& os, Queue const& q);
}
