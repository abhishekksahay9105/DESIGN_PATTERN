/*--------------------------ParkingDB Implementation-------------------------------*/
#include <fstream>
#include "DataTypes.h"

bool ParkingDB::Save ()
{
		bool status = true;

		std::fstream file (, std::ios::out);
		if (file.is_open())
		{
				for (auto spotSize : mParkingDB)
				{
					int spSize = spotSize.first;
					std::vector<std::pair<int, std::shared_ptr<ParkingSlot>& spotVec = spotSize.second;
					for (int index = 0; index < int(spotVec.size());index++)
					{
							int slotId = -1;
							int floor;
							int row;
							int col;
							if (!(file >> floor >> row >> col >> spSize >> slotId >> 0))
								 status = false;

					}
				}


				for (auto spotSize : mParkingUnderUse)
				{
					int spSize = spotSize.first;
					std::vector<std::pair<int, std::shared_ptr<ParkingSlot>& spotVec = spotSize.second;
					for (int index = 0; index < int(spotVec.size());index++)
					{
							int slotId = -1;
							int floor;
							int row;
							int col;
							if (!(file >> floor >> row >> col >> spSize >> slotId >> 0))
								 status = false;

					}
				}
		}
		else
		{
				status = false;
				printf ("Failed to open file %s", "");
		}
		return std::move(status);
}

bool ParkingDB::Restore ()
{
	bool status = true;
	std::fstream file (, std::ios::in);
	
	if (file.is_open ())
	{
		std::shared_ptr<Location> location;
		SpotSize spotSize;
		int slotId;
		bool isBooked = false;
		if (file >> location->mFloor >> location->mRow >> location->mCol >> spotSize >> slotId >> isBooked)
		{
			mNumOfParkingSlot++;
			std::shared_ptr<ParkingSlot> slot = std::make_shared <ParkingSlot>(location, spotSize);
			
			if (isBooked)
			{
					mParkingUnderUse[spotSize].push_back({slotId, slot});
			}
			else
			{
					mParkingDB[spotSize].push_back({slotId, slot});
			}
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

bool ParkingDB::AddParkingSlot (std::shared_ptr<ParkingSlot> aParkingSlot)
{
}

std::shared_ptr<ParkingSlot> GetEmptySlot (std::shared_ptr<vehicle> aVehicle) const
{
}

bool AssignSlot (std::shared_ptr<Ticket> aTicket, int& aSlotId) const
{
}

bool MarkFreeParkingSlot (int aSlotId)
{
}

