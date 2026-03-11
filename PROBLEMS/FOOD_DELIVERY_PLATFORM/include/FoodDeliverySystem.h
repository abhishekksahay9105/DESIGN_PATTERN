#ifndef _FoodDeliverySystem_h_
#define _FoodDeliverySystem_h_

#include <memory>

namespace fds
{
		class Renderer;
		class OrderDB;
		class ResturantDB;
		class CustomerDB;

		typedef enum OrderStatusT
		{
				cRenderDishes = 0,
				cLoginAsCustomer,
				cLoginAsResturant,
				cOrderDishes,
				cAddDishes,
				cResturantList

		} OrderStatusT;

		class FoodDeliverySystem
		{
				private:
						std::shared_ptr<Renderer>			mRender{nullptr};
						std::shared_ptr<OrderDB>			mOrderDB{nullptr};
						std::shared_ptr<ResturantDB>		mResturantDB{nullptr};
						std::shared_ptr<CustomerDB>			mCustomerDB{nullptr};

				public:
						static std::shared_ptr<FoodDeliverySystem> Create ();

						FoodDeliverySystem ();

						~FoodDeliverySystem () = default;

						bool Execute ();

						bool RenderDishes ();

						/*Function related to customer*/
						bool RegisterCustomer ();
						bool Order ();
						bool AddToCart ();

						/*Funtion related to Resturan*/
						bool RegisterResturant ();
						bool AddDishesToResturant ();
						bool RemoveDishesFromResturant ();
						void PrintResturantList ();

						/*Function Related to Delivery Boy*/
						bool RegisterDeliveryBoy ();
		};
}

#endif
