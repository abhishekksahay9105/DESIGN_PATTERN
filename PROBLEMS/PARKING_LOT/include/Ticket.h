#include <chrono>

class vehicle;
class ParkingSlot;
class Ticket
{
		public:
			using Clock			= std::chrono::system_clock;
			using TimePoint		= std::time_point<Clock>;

			Ticket (vehicle aVehicle);

			TimePoint GetEntryTime () const noexpect {return mEntryTime;}

			std::shared_ptr<ParkingSlot> GetParkingSlot () const noexpect {return mParkingSlot;}
			void SetParkingSlot (std::shared_ptr<ParkingSlot> aParkingSlot) {mParkingSlot = aParkingSlot;}

			std::shared_ptr<vehicle> GetVehicle () const noexpect {return mVehicle;}

		private:
			std::shared_ptr<vehicle> 			mVehicle;
			TimePoint							mEntryTime (Clock::now());
			TimePoint							mExitTime;
			std::shared_ptr<ParkingSlot>		mParkingSlot;
			int 								mCharge{-1};
			TicketStatus 						mTicketStatus{TicketStatus::cNone};
};
