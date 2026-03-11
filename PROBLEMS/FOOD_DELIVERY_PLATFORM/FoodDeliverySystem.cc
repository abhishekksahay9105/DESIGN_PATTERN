#include <memory>
#include <iostream>
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
		printf ("FoodDeliverySystem::Execute\n");

		int isServerdown = false;
		OrderStatusT mState = cRenderDishes;
		while (!isServerdown)
		{
				int abc;
				std::cout << "Enter the Work that you want to do: \n";
				if(std::cin >> abc)
				{

						mState =  OrderStatusT(abc); 
						switch (mState)
						{
								case cRenderDishes:
										{
												printf ("cRenderDishes\n");
												RenderDishes ();
												break;
										}
								case cLoginAsCustomer:
										break;
								case cLoginAsResturant:
										{
												printf ("cLoginAsResturant\n");
												RegisterResturant ();
												break;
										}
								case cAddDishes:
										{
												printf ("cAddDishes\n");
												AddDishesToResturant ();
												break;
										}
								case cOrderDishes:
										break;
								case cResturantList:
									{
											printf ("cResturantList");
											PrintResturantList ();
											break;
									}	
								default:
										mState = cRenderDishes;
										break;
						}
				}
		}

		return true;
}

bool FoodDeliverySystem::RenderDishes ()
{
	printf ("FoodDeliverySystem::RenderDishes\n");

	bool status = false;
	if (mResturantDB)
	{	
		std::unordered_map<int, std::shared_ptr<Resturant>> resturantList =   mResturantDB->get_ResturantList ();

		for (const auto& iterator : resturantList)
		{
				std::shared_ptr<Resturant> resturant = iterator.second;
				std::shared_ptr<DishDB>	dishDb = resturant->get_DishDb ();

				DishDB::DishIterator itr = dishDb->begin();
				while (itr != dishDb->end())
				{
						status = true;
						std::shared_ptr<Dish> dish = itr->second;
						dish->show ();
						itr++;
				}
		}
	}
	return status;
}

bool FoodDeliverySystem::RegisterCustomer ()
{
	return true;
}

bool FoodDeliverySystem::Order ()
{
		return true;
}

bool FoodDeliverySystem::AddToCart ()
{
		return true;
}

bool FoodDeliverySystem::RegisterResturant ()
{
		bool status = false;
		std::shared_ptr<Resturant> resturant = Resturant::Create ();
		if (mResturantDB)
				status = mResturantDB->Add_Resturant (resturant);
		return status;
}

bool FoodDeliverySystem::AddDishesToResturant ()
{
		bool status = false;

		std::cout << "Enter Resturant Id\n";
		int restId  = 0;

		if (std::cin >> restId)
		{
			std::shared_ptr<Resturant> resturant = mResturantDB->get_Resturant (restId);

			bool isAddMoreDish = true; 
			if (resturant && isAddMoreDish)
			{
					resturant->Add_Dish ();
					std::cout << "Is Add More dishes (yes/no)\n";
					std::string isadd;
					std::cin >> isadd;
					if (isadd != "yes")
						isAddMoreDish = false;
			}
		}

		return status;
}

bool FoodDeliverySystem::RemoveDishesFromResturant ()
{
		return true;
}

void FoodDeliverySystem::PrintResturantList ()
{
		printf ("FoodDeliverySystem::PrintResturantList\n");
		mResturantDB->Print();
}

bool RegisterDeliveryBoy ()
{
		return true;
}
