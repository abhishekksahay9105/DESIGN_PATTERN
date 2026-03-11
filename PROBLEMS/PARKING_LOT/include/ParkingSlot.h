#include <memory>

class ParkingSlot
{
		public:
				static std::shared_ptr<ParkingSlot> Create ();

				ParkingSlot (std::shared_ptr<Location> aLocation, SpotSize aSpotSize);

				ParkingSlot (const ParkingSlot&) = default;
				ParkingSlot& operator=(const ParkingSlot&) = default;
				ParkingSlot (const ParkingSlot&&) = default;
				ParkingSlot& operator=(const ParkingSlot&&) = default;
				
				bool CanVehicleFit (vehicle aVehicle) const = 0;

				int  GetSlotId () const {return mSlotId;}

				void SetIsFree () const {is}

		private:
				std::shared_ptr<Location>	mLocation{nullptr};
				SpotSize					mSpotSize;
				bool 						mIsFree{true};
				int 						mSlotId{-1};
};

class CompactParkingSlot : public ParkingSlot
{
		public:
				CompactParkingSlot (std::shared_ptr<Location> aLocation) : ParkingSlot (aLocation, SpotSize::cCompact) {}
		
				bool CanVehicleFit (vehicle aVehicle) const override;
};

class MediumParkingSlot
{
		public:
				MediumParkingSlot (std::shared_ptr<Location> aLocation) : ParkingSlot (aLocation, SpotSize::cCompact) {}

				bool CanVehicleFit (vehicle aVehicle) const override;
};

class OversizedParkingSlot
{
		public:
				OversizedParkingSlot (std::shared_ptr<Location> aLocation) : ParkingSlot (aLocation, SpotSize::cCompact) {}

				bool CanVehicleFit (vehicle aVehicle) const override;
};
