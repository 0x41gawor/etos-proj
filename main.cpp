#include <iostream>

#include "src/system/System.h"
#include "src/sim/Event.h"

int main()
{
    Sim::Event event = Sim::Event(0.4, Sim::EventTypeEnum::ARRIVAL);
    std::cout << event;
}