#include <iostream> 
#include "Dish.h"
#include "Resturant.h"
//=======================================================================================================================
// class Dish
//=======================================================================================================================
using namespace fds;
Dish::Dish (std::string aDishName, int aPrice, std::string aImage, bool aIsNonVeg, std::shared_ptr<Resturant> aResturant) : 
	mPrice(aPrice), 
	mIsNonVeg (aIsNonVeg),
	mDishName(aDishName), 
	mImage(aImage),
	mResturant(aResturant)
{
}

void Dish::show ()
{
		std::cout << "\n\n";
		std::cout << "==========================\n";
		std::cout << "Dish Name : " << mDishName << std::endl;
		std::cout << "Resturant Name: " <<  mResturant->getResturantName () << std::endl;
		std::cout << "Price Name : " << mPrice << std::endl;
		std::cout << "IsNonVeg : " << mIsNonVeg << std::endl;
		std::cout << "Image : " << mImage << std::endl;
		std::cout << "==========================\n";
		std::cout << "\n\n";
}

bool Dish::Decrement ()
{
	if (mCount == 0)
		return false;
	else
		mCount--;
	
	return true;
}


//=======================================================================================================================
// class DishDB
//=======================================================================================================================

int DishDB::Add_DishToDB (std::shared_ptr<Dish> aDish)
{
		mLastDishId++;
		mDishList[mLastDishId] = aDish;
		return mLastDishId;
}
