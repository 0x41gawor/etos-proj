#include "src/Program.h"

#include "src/system/Scheduler.h"
int main()
{
	//Program program = Program();
	//program.run();
	System::Scheduler scheduler;
	scheduler.push(System::Client(1.0, System::FlowEnum::A));
	scheduler.push(System::Client(0.9, System::FlowEnum::B));
	scheduler.push(System::Client(2.0, System::FlowEnum::B));
	scheduler.push(System::Client(2.0, System::FlowEnum::B));
	scheduler.push(System::Client(2.0, System::FlowEnum::B));
	scheduler.push(System::Client(2.0, System::FlowEnum::B));
	scheduler.push(System::Client(2.0, System::FlowEnum::B));
	scheduler.push(System::Client(2.0, System::FlowEnum::B));
	scheduler.push(System::Client(2.0, System::FlowEnum::B));
	scheduler.push(System::Client(2.0, System::FlowEnum::B));
	scheduler.push(System::Client(3.0, System::FlowEnum::A));
	scheduler.push(System::Client(3.0, System::FlowEnum::A));
	scheduler.push(System::Client(3.0, System::FlowEnum::A));
	scheduler.push(System::Client(3.0, System::FlowEnum::A));
	scheduler.push(System::Client(3.0, System::FlowEnum::A));
	scheduler.push(System::Client(3.0, System::FlowEnum::A));

	for (int i = 0; i < 15; i++)
	{
		System::Client c = *scheduler.pop();
		std::cout << c << "\n";
	}
	
}