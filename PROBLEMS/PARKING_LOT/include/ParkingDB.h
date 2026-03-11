class ParkingDB
{
		public:
				static Create ();

				ParkingDB () = default;

				~ParkingDB () = default;

				ParkingDB (const ParkingDB&) = default;
				ParkingDB& operator=(const ParkingDB&) = default;


				ParkingDB (const ParkingDB&) = default;
				ParkingDB& operator=(const ParkingDB&) = default;
				
				bool RestoreParkingDB ();

				bool SaveParkingDB ();

				bool AddParkingSlot (std::shared_ptr<ParkingSlot> aParkingSlot);

				std::shared_ptr<ParkingSlot> GetEmptySlot (std::shared_ptr<vehicle> aVehicle) const;
				
				bool AssignSlot (std::shared_ptr<Ticket> aTicket, int& aSlotId) const;

				bool MarkFreeParkingSlot (int aSlotId);

		private:
				std::unordered_map<SpotSize, std::vector<std::pair<int, std::shared_ptr<ParkingSlot>>>> 			mParkingDB;
				std::unordered_map<SpotSize, std::vector<std::pair<int, std::shared_ptr<ParkingSlot>>>> 			mParkingUnderUse;
				int																					mNumOfParkingSlot{0};
};
