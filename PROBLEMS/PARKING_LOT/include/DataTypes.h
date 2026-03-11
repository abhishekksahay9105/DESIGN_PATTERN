
enum class VehicleType
{
		cCar = 0,
		cMotorCycle,
		cTruck
};

enum class SpotSize
{
		cCompact = 0,
		cMedium,
		cOversized
};

enum class TicketStatus
{
		cNone = 0,
		cRunning,
		cClosed,
		cCanceled
};

enum class CounterStatus
{
		cNone = 0,
		cOpen,
		cClosed
};

typedef struct Location
{
		int mFloor{-1};
		int mRow {-1};
		int mCol {-1};
} Location;
