#include <memory>

class FeeCalculator
{
		public:
				FeeCalculator () = default;

				~FeeCalculator () = default;
				
				FeeCalculator(const FeeCalculator&) = default;
				FeeCalculator& operator=(const FeeCalculator&) = default;

				FeeCalculator(const FeeCalculator&&) = default;
				FeeCalculator& operator=(const FeeCalculator&&) = default;

				static int CalculateCharge (std::shared_ptr<Ticket> aTicket);
};
