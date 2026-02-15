#include <iostream>
#include "ContactInfo.h"

using namespace fds;
std::shared_ptr<Address> Address::Create ()
{
		std::shared_ptr<Address> address = std::make_shared<Address>();

		std::cout << "Enter Falt No. :\n" << std::endl;
		std::cin >>  address->mFalt;

		std::cout << "Enter Society Name :" << std::endl;
		std::cin >>  address->mSociety;

		std::cout << "Enter Area :" << std::endl;
		std::cin >>  address->mArea;

		std::cout << "Enter District :" << std::endl;
		std::cin >>  address->mDistrict;

		std::cout << "Enter Pincode :" << std::endl;
		std::cin >>  address->mPincode;

		return address;
}

std::shared_ptr<ContactInfo> ContactInfo::Create ()
{
		std::shared_ptr<ContactInfo> info = std::make_shared<ContactInfo>();

		std::cout << "Enter PhoneNo :" << std::endl;
		std::cin >>  info->mPhoneNo;

		std::cout << "Enter Secondary PhoneNo :" << std::endl;
		std::cin >>  info->mSecPhoneNo;

		std::cout << "Enter mEmail :" << std::endl;
		std::cin >>  info->mEmail;

		std::cout << "Enter Secondary mEmail :" << std::endl;
		std::cin >>  info->mSecEmail;

		info->mAddress = Address::Create ();
		info->mSecAddress = Address::Create ();

		return info;
}
