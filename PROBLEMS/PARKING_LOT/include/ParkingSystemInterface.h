//ParkingSystem Interface 

class vehicleInterface
{
		public:
				static std::shared_ptr<vehicleInterface> Create (std::string aNamePlate, VehicleType aVehicleType);
				
				vehicleInterface () = default;

				~vehicleInterface () = default;

};

class TicketInterface
{
		public:
				TicketInterface () = default;

				~TicketInterface () = default;
};

class Counter
{
		public:
			Counter () = default;

			~Counter () = default;

			//Ticket Generation
			virtual std::shared<TicketInterface> TicketGeneration () = 0;

			virtual int GetCounterID () const = 0;
};

class ParkingSlotInterface
{
		public:
				static std::shared_ptr<ParkingSlotInterface> Create ();

				ParkingSlot (std::shared_ptr<Location> aLocation, SpotSize aSpotSize);

				bool CanVehicleFit () const = 0;

				int  GetSlotId () const = 0;
};

class ParkingSystemInterface
{
		public:
				static std::unique_ptr<ParkingSystemInterface> Create ();

				~ParkingSystemInterface () = default;
				
				// Counter
				virtual int AddCounter () = 0;
				
				virtual bool RemoveCounter (int aCounterId) = 0;

				virtual std::shared<CounterInterface> GetCounter (int aCounterId) = 0;

				// Parking Slots
				virtual int AddParkingSlot () = 0; 

				virtual bool RemoveParkingSlot (int aSlotId) = 0;

				//virtual int GetEmptySlot (std::string aNamePlate, VehicleType aVehicleType) const = 0;				

				// Parking Vehicle
				virtual bool ParkVehicle (std::shared_ptr<TicketInterface> aTicket) = 0;

				virtual bool RemoveVehicle (std::shared_ptr<TicketInterface> aTicket) = 0;

				// Ticket
				virtual std::shared_ptr<TicketInterface> GenerateTicket (std::string aNamePlate, VehicleType aVehicleType) = 0;

				virtual int FeeCalculate (std::shared_ptr<TicketInterface> aTicket) = 0;
		
		private:
				ParkingSystemInterface () = default;
};
