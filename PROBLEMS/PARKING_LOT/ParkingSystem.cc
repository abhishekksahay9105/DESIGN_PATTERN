/*-----------------------------------Implementation of Parking System-----------------------------------------*/


std::unique_ptr<ParkingSystemInterface> ParkingSystemInterface::Create ()
{
		std::unique_ptr<ParkingSystem> interface = std::make_unique<ParkingSystem>();

		if (interface && interface->Intialize ())
		{
				return interface;
		}
		else
		{
				std::cout << "Failed to Create ParkingSytem\n";
				return nullptr;
		}
}

bool ParkingSystem::Intialize ()
{
	bool status = true;
	mParkingDB = std::make_shared<ParkingDB>();
	status &= mParkingDB && mParkingDB->Restore();

	mCounterDB = std::make_shared<CounterDB>(mParkingDB);
	status &= mCounterDB && mCounterDB->Restore();
	
	return status;
}

// Function Related to Counter
int ParkingSystem::AddCounter ()
{
		int counterId = -1;
		if (mCounterDB)
		{
				counterId = mCounterDB->AddCounter ();
		}
		return counterId;
}

bool ParkingSystem::RemoveCounter (int aCounterId)
{
		return  mCounterDB->RemoveCounter (aCounterId);
}

std::shared<Counter> ParkingSystem::GetCounter (int aCounterId)
{
		return  mCounterDB->GetCounter (aCounterId);
}

//Function ParkingDB
int ParkingSystem::AddParkingSlot ()
{

}

bool ParkingSystem::RemoveParkingSlot (int aSlotId)
{
}
