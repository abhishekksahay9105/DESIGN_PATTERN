/*Parking Lot Main*/
#include "ParkingSystemInterface.h"

enum class Task
{
		cNone = 0,
		cAddCounter,
		cRemoveCounter,
		cWait
};

static Task mTask = cNone;



void Run (std::shared_ptr<ParkingSystemInterface> aPSI)
{
		while (true)
		{
				switch (mTask)
				{
						case cAddCounter:
								aPSI->AddCounter ();
								break;
						case c
						case cNone:
							break;
				}
		}
}

int main ()
{
		std::shared_ptr<ParkingSystemInterface> PSI = ParkingSystemInterface::Create ();
		
		if (PSI)
		{
				Run (PSI);
		}

		return 0;
}
