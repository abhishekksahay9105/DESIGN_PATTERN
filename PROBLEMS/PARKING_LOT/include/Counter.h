#include <memory>

class Counter
{
		public:
			Counter (std::shared_ptr<ParkingDB> aParkingDB);

			~Counter () = default;
			
			Counter (const Counter&) 		    = default; 	// Copy constructor
			Counter& operator=(const Counter&)  = default; 	// Assignment Operator
			Counter (const Counter&&) 		    = default; 	// Move function
			Counter& operator=(const Counter&&) = default;

			std::shared_ptr<Ticket> GenerateTicket (std::shared_ptr<vehicle> aVehicle);

			int FeeCalculator (std::shared_ptr<Ticket> aTicket) const;

		private:
			int 							mCounterId{-1};
			std::shared_ptr<ParkingDB>		mParkingDB{nullptr};
			CounterStatus					mCounterStatus{CounterStatus::cNone};
};
