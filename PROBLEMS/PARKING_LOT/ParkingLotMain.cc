/*Parking Lot Main*/
#include "ParkingSystemInterface.h"

int main ()
{
		std::unique_ptr<ParkingSystemInterface> PSI = ParkingSystemInterface::Create ();

		return 0;
}
