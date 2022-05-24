#include <iostream>

#include "src/system/System.h"
#include "src/sim/EventList.h"

int main()
{
    Sim::Event event1 = Sim::Event(0.8, Sim::EventTypeEnum::ARRIVAL);
    Sim::Event event2 = Sim::Event(0.4, Sim::EventTypeEnum::DEPARTURE);
    Sim::Event event3 = Sim::Event(1.2, Sim::EventTypeEnum::END);
    Sim::Event event4 = Sim::Event(0.1, Sim::EventTypeEnum::END);
    Sim::Event event5 = Sim::Event(1.3, Sim::EventTypeEnum::END);

    Sim::EventList eventList = Sim::EventList();
    eventList.push(event1);
    eventList.push(event2);
    eventList.push(event3);
    eventList.push(event4);
    eventList.push(event5);
    eventList.show();

    
}