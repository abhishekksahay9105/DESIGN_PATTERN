//Implementation of Concreate class ParkingSystem

class ParkingSystem : public ParkingSystemInterface
{
		public:
				ParkingSystemInterface () = default;

				~ParkingSystemInterface () = default;
				
				// Counter
				int AddCounter () = 0;
				
				bool RemoveCounter (int aCounterId) = 0;
				
				// Parking Slots
				std::shared_ptr<ParkingSlot> GetEmptySlot (std::string aNamePlate, VehicleType aVehicleType) const = 0;

				bool ParkVehicle (std::shared_ptr<Ticket> aTicket) = 0;

				// Ticket
				std::shared_ptr<Ticket> GenerateTicket (std::shared_ptr<vehicle> aVehicle) = 0;

				int FeeCalculate (std::shared_ptr<Ticket> aTicket) = 0;

		private:
				std::shared_ptr<ParkingDB>			mParkingDB{nullptr};
				std::vector<Counter>				mCounterVec;
};

