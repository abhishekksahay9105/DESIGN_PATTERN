#ifndef _OrderDB_h_
#define _OrderDB_h_

#include <vector>
#include <memory>

namespace fds
{
		class DishDB;
		class Customer;

		typedef enum OrderStatus
		{
				cNone = 0,
				cPreparing,
				cPrepared,
				cOutForDeliver,
				cDelivered,
				cCanceled

		} OrderStatus;


		class Order
		{
				private:
						int 									mOrderId{-1};
						std::shared_ptr<DishDB>					mDishList;
						std::shared_ptr<Customer>				mCustomer;
		};

		class OrderDB
		{
				private:
						std::vector<std::shared_ptr<Order>>		mOrderList;
				
				public:

		};
}
#endif
