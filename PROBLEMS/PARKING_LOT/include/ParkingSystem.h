//Implementation of Concreate class ParkingSystem

class ParkingSystem : public ParkingSystemInterface
{
		public:
				ParkingSystem () = default;

				~ParkingSystem () = default;
				
				bool Intialize ();

				// Function Related to Counter Counter
				int AddCounter ();
				
				bool RemoveCounter (int aCounterId);

				std::shared<Counter> GetCounter (int aCounterId);

				//Function ParkingDB
				int AddParkingSlot () = 0; 

				bool RemoveParkingSlot (int aSlotId) = 0;

				// Parking Vehicle
				bool ParkVehicle (std::shared_ptr<TicketInterface> aTicket) = 0;

				bool RemoveVehicle (std::shared_ptr<TicketInterface> aTicket) = 0;

				// Ticket
				std::shared_ptr<TicketInterface> GenerateTicket (std::string aNamePlate, VehicleType aVehicleType) = 0;

				int FeeCalculate (std::shared_ptr<TicketInterface> aTicket) = 0;

		private:
				std::shared_ptr<ParkingDB>			mParkingDB{nullptr};
				std::shared_ptr<CounterDB>			mCounterDB{nullptr};
};

