/*--------------------------------Implementation of CounterDB--------------------------------------*/
CounterDB::CounterDB (std::shared_ptr<ParkingDB> aParkingDB) : mParkingDB(aParkingDB)
{
}

int CounterDB::AddCounter ()
{
		std::shared_ptr<Counter> counter = std::make_shared<Counter>(mParkingDB, mLastCounterId);
		if (counter)
		{
				mCounterDB[mLastCounterId] = counter;
				mLastCounterId++;
				return counter->GetCounterID ();
		}

		return -1;
}

bool CounterDB::RemoveCounter (int aCounterId)
{
		bool status = false;
		if (mCounterDB.find(aCounterId) != mCounterDB.end())
		{
				delete mCounterDB[aCounterId];
				mCounterDB.erase(aCounterId);
		}
		return std::move(status);
}

std::shared<Counter> CounterDB::GetCounter (int aCounterId) const
{
		if (mCounterDB.find(aCounterId) != mCounterDB.end())
		{
				return mCounterDB[aCounterId];
		}
		return nullptr;
}

bool CounterDB::Save ()
{
		bool status = false;
		std::fstream file(/*FilePath*/, std::ios::out);
		if (file.is_open())
		{
				for (int index = 0; index < int (mCounterDB.size()); index++)
				{
						file << mCounterDB[index]->GetCounterID ();
				}
				status = true;
		}
		file.close();
		return std::move(status);
}

bool CounterDB::Restore ()
{
		bool status = true;
		std::fstream file(/*FilePath*/, std::ios::in);
		if (file.is_open())
		{
				int counterId = -1;
				while (file >> counterId)
				{
						std::shared_ptr<Counter> counter = std::make_shared<Counter>(mParkingDB, counterId);
						mCounterDB[counterId] = counter;
						mLastCounterId = std::max(mLastCounterId+1,counter);
				}
		}
		file.close();
		return std::move(status);
}

