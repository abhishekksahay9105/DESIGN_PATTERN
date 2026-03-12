/*---------------------------------------Implementation of Counter-------------------------------*/

Counter::Counter (std::shared_ptr<ParkingDB> aParkingDB, int aCounterId) :
		mParkingDB (aParkingDB), mCounterId (aCounterId) 
{
	
}

std::shared_ptr<Ticket> GenerateTicket (std::shared_ptr<vehicle> aVehicle);

int FeeCalculator (std::shared_ptr<Ticket> aTicket) const;


