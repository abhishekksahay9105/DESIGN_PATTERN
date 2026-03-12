#include <memory>

class CounterDB
{
		public:
			CounterDB (std::shared_ptr<ParkingDB> aParkingDB);

			~CounterDB () = default;

			int AddCounter ();

			bool RemoveCounter (int aCounterId);

			std::shared<Counter> GetCounter (int aCounterId) const;

			bool Save ();

			bool Restore ();

			CounterDB (const CounterDB&) 		    = default; 	// Copy constructor
			CounterDB& operator=(const CounterDB&)  = default; 	// Assignment Operator
			CounterDB (const CounterDB&&) 		    = default; 	// Move function
			CounterDB& operator=(const CounterDB&&) = default;

		private:
			std::shared_ptr<ParkingDB>				mParkingDB{nullptr};
			std::map<int, std::shared<Counter>		mCounterDB;
			int 									mLastCounterId{0};
};
