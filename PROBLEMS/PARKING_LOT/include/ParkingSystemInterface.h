//ParkingSystem Interface 

class TicketInterface
{
		public:
				TicketInterface () = default;

				~TicketInterface () = default;
};

class ParkingSlotInterface
{
		public:
				static std::shared_ptr<ParkingSlot> Create ();

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
				
				// Parking Slots
				virtual int GetEmptySlot (std::string aNamePlate, VehicleType aVehicleType) const = 0;

				virtual bool ParkVehicle (std::shared_ptr<TicketInterface> aTicket) = 0;

				virtual bool RemoveVehicle (std::shared_ptr<TicketInterface> aTicket) = 0;

				// Ticket
				virtual std::shared_ptr<TicketInterface> GenerateTicket (std::string aNamePlate, VehicleType aVehicleType) = 0;

				virtual int FeeCalculate (std::shared_ptr<TicketInterface> aTicket) = 0;
		
		private:
				ParkingSystemInterface () = default;
};
