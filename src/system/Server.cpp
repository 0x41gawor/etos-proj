#include "Server.h"

using namespace System;

Server::Server()
{
	status = ServerStatusEnum::FREE;
}

std::ostream& System::operator<<(std::ostream& os, Server const& s)
{
	return os << "Server{status=" << s.status << "}";
}
