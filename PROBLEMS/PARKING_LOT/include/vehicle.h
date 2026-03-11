#include <string>

class vehicle
{
		public:
				static std::shared_ptr<vehicle> Create ();

				vehicle (std::string aNamePlate, VehicleType aVehicleType);
				~vehicle () = default;

				vehicle (const vehicle&) 			= default;
				vehicle& operator=(const vehicle&)  = default;
				vehicle (const vehicle&&) 			= default;
				vehicle& operator=(const vehicle&&) = default;

				bool CanFitToSpot (SpotSize aSize) = 0;

				std::string getNamePlate () {return mNamePlate}
				std::string getVehicleType () {return mVehicleType}
		private:
				std::string 			mNamePlate;
				VehicleType				mVehicleType;
};

class car final : public vehicle
{
		public:
				car (std::string aNamePlate) : vehicle (std::move(aNamePlate), VehicleType::cCar) {}

				bool CanFitToSpot (SpotSize aSize) override;
};

class motor final : public vehicle
{
		public:
				motor (std::string aNamePlate) : vehicle (std::move(aNamePlate), VehicleType::cMotorCycle) {}

				bool CanFitToSpot (SpotSize aSize) override;

};

class truck final : public vehicle
{
		public:
				truck (std::string aNamePlate) : vehicle (std::move(aNamePlate), VehicleType::cTruck) {}

				bool CanFitToSpot (SpotSize aSize) override;
};
