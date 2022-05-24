#include "Queue.h"

using namespace System;

Queue::Queue():clientsCount(0), isEmpty(true)
{
}

void Queue::push(Client client)
{
	implementation.push(client);
	isEmpty = implementation.empty();
	clientsCount = implementation.size();
}

Client* Queue::pop()
{
	if (!implementation.empty())
	{
		Client client = implementation.front();
		implementation.pop();
		isEmpty = implementation.empty();
		clientsCount = implementation.size();
		return &client;
	}
	return NULL;
}

void Queue::show()
{
	std::queue<Client> copy = implementation;
	std::cout << "Queue:[";
	while (!copy.empty()) {
		std::cout << " " << copy.front();
		copy.pop();
		if (copy.size() > 1) std::cout << ",";
	}
	std::cout << " ]\n";
}

std::ostream& System::operator<<(std::ostream& os, Queue const& q)
{
	return os << "Queue{clientsCount=" << q.clientsCount << ", isEmpty=" << q.isEmpty <<  "}";
}
