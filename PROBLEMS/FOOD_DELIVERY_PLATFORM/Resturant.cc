#include <iostream>
#include "Resturant.h"
#include "ContactInfo.h"
#include "Dish.h"
//=======================================================================================================================
//class Resturant 
//=======================================================================================================================
using namespace fds;
std::shared_ptr<ResturantDB> ResturantDB::mResturantDB = nullptr;

std::shared_ptr<fds::Resturant> fds::Resturant::Create ()
{
		std::shared_ptr<fds::Resturant> resturant;
		std::cout << "Enter  Resturant Name: \n";
		std::string resName;
		if (std::cin >> resName)
		{
				std::shared_ptr<ContactInfo> contact = fds::ContactInfo::Create ();
				if (contact)
				{
					resturant = std::make_shared<fds::Resturant> (resName, contact);
				}
		}
		return resturant;
}

Resturant::Resturant (std::string aResName,  std::shared_ptr<ContactInfo> aContact) :
	mResName (aResName), mContact(aContact)
{
	mDishDb = std::make_shared<DishDB>();
}

bool Resturant::Add_Dish ()
{
	std::string dishName;
	int price;
	std::string image;
	bool aIsNonVeg;

	std::cout << " Enter Dish Detail:\n";
	std::cout << " DishName : ";
	std::cin >> dishName;
	std::cout << " Price : ";
	std::cin >> price;
	std::cout << "Image : ";
	std::cin >> image;
	std::cout << "IsNonVeg : ";
	std::cin >> aIsNonVeg;
	std::shared_ptr<Dish> dish = std::make_shared<Dish>(dishName, price, image, aIsNonVeg, this->shared_from_this());
	return mDishDb->Add_DishToDB (dish);

}

bool  Resturant::Print ()
{
	bool status = false;
	std::cout << "+-----------------------+" << std::endl; 
	std::cout << "Resturant Id: " << mResturantId << std::endl;
	std::cout << "Resturant Name: " << mResName << std::endl;
    mContact->Print ();
	std::cout << "+-----------------------+" << std::endl;
	std::cout << std::endl;

	return status;
}

//=======================================================================================================================
//class ResturantDB 
//=====================================================================================================================
bool ResturantDB::Add_Resturant (std::shared_ptr<Resturant> aResturant)
{
	bool status = false;

	if (aResturant)
	{
			status = true;
			aResturant->setResturantId (mLastResturantId);
			mResturantList[mLastResturantId] = aResturant;
	}

	return status;
}

std::shared_ptr<Resturant> ResturantDB::get_Resturant (int aRestId) const
{
		auto iterator = mResturantList.find (aRestId);

		if (iterator !=  mResturantList.end())
		{
				return iterator->second;
		}

		return nullptr;
}

std::shared_ptr<Resturant> ResturantDB::get_Resturant (std::string aEmail) const
{
		auto iterator = mEmailResturantList.find (aEmail);

		if (iterator !=  mEmailResturantList.end())
		{
				return iterator->second;
		}

		return nullptr;
}

std::shared_ptr<ResturantDB> ResturantDB::get_ResturantDB ()
{
		if (!mResturantDB)
				mResturantDB = std::make_shared<ResturantDB>();

		return mResturantDB;
}

bool ResturantDB::Print ()
{
		bool status = false;
		printf ("ResturantDB::Print");

		for (const auto& resturant : mResturantList)
		{
				resturant.second->Print ();
		}

		return status;
}
