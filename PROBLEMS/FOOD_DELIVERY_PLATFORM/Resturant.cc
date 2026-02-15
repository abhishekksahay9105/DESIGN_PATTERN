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
}

std::shared_ptr<ResturantDB> ResturantDB::get_ResturantDB ()
{
		if (!mResturantDB)
				mResturantDB = std::make_shared<ResturantDB>();

		return mResturantDB;
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

