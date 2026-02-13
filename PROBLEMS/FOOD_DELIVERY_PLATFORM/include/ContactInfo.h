#ifndef _Data_Types_h_
#define _Data_Types_h_

#include <string>
namespace fds
{
	struct Address
	{
		std::string 		mFalt;
		std::string 		mSociety;
		std::string 		mArea;
		std::string	    	mDistrict;
		std::string 		mPincode;
		unsigned long long 	mLogitude;
		unsigned long long 	mLatitude;
	};

	struct ContactInfo
	{
		std::string 		mPhoneNo;
		std::string 		mSecPhoneNo;
		std::string 		mEmail;
		std::string 		mSecEmail;
		Address				mAddress;
		Address				mSecAddress;
	};
}
#endif
