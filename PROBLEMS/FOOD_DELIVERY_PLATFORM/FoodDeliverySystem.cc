#include <memory>
#include "FoodDeliverySystem.h"
#include "Render.h"
#include "OrderDB.h"
#include "CustomerDB.h"
#include "ContactInfo.h"
#include "Resturant.h"
#include "Dish.h"
//=======================================================================================================================
// class FoodDeliverySystem
//=======================================================================================================================
using namespace fds;
std::shared_ptr<FoodDeliverySystem> FoodDeliverySystem::Create ()
{
		std::shared_ptr<FoodDeliverySystem> foodDeliverySystem = std::make_shared<FoodDeliverySystem>();

		if (foodDeliverySystem)
				return foodDeliverySystem;

		return nullptr;
}

FoodDeliverySystem::FoodDeliverySystem ()
{
		mResturantDB = ResturantDB::get_ResturantDB ();
		mRender	     = std::make_shared<Renderer>(mResturantDB);
		mOrderDB     = std::make_shared<OrderDB>();
		mCustomerDB  = std::make_shared<CustomerDB>();
}

bool FoodDeliverySystem::Execute ()
{
		int isServerdown = false;
		OrderStatusT mState = cRenderDishes;
		while (!isServerdown)
		{
				switch (mState)
				{
						case cRenderDishes:
						{
								RenderDishes ();
								break;
						}
						case cLoginAsCustomer:
								break;
						case cLoginAsResturant:
						{
								LoginAsResturant ();
								break;
						}
						case cOrderDishes:
								break;
						default:
								mState = cRenderDishes;
								break;
				}
		}

		return true;
}

bool  FoodDeliverySystem::RenderDishes ()
{
	bool status = false;
	if (mResturantDB)
	{	
		//std::unordered_map<int, std::shared_ptr<Resturant>> resturantList =   mResturantDB->get_ResturantList ();

//		for (const auto& iterator : resturantList)
//		{
//				std::shared_ptr<DishDB>	dishDb = iterator.second->get_DishDb;
//
//				DishDB::DishIterator itr = dishDb.begin();
//				while (itr != dishDb.end())
//				{
//						status = true;
//						std::shared_ptr<Dish> dish = itr->second;
//						dish->show ();
//						itr++;
//				}
		//}
	}
	return status;
}


bool  FoodDeliverySystem::LoginAsResturant ()
{
		return RegisterResturant ();
}

bool FoodDeliverySystem::RegisterResturant ()
{
		bool status = false;
		std::shared_ptr<Resturant> resturant = Resturant::Create ();
		if (mResturantDB)
				status = mResturantDB->Add_Resturant (resturant);
		return status;
}
