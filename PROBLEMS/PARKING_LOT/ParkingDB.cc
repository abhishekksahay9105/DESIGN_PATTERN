/*--------------------------ParkingDB Implementation-------------------------------*/
#include <fstream>
#include "DataTypes.h"

bool ParkingDB::RestoreParkingDB ()
{
	bool status = true;
	std::fstream file (, std::ios::in);
	
	if (file.is_open ())
	{
		std::shared_ptr<Location> location;
		SpotSize spotSize;
		int slotId;
		bool isBooked = false;
		if (file << location->mFloor << location->mRow << location->mCol << spotSize << slotId << isBooked)
		{
			mNumOfParkingSlot++;
			std::shared_ptr<ParkingSlot> slot = std::make_shared <ParkingSlot>(location, spotSize);

			mParkingDB[spotSize].push_back({slotId, slot});
		}
		else
		{
				status = false;
				std::cout << "Failed to Read Parking DB File.";
				break;
		}
	}
	else
	{
			status = false;
			std::cout << "Failed to open Parking DB file";
	}

	file.close();
	return status;
}
