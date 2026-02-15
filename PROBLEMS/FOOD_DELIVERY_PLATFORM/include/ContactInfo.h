#ifndef _ContactInfo_h_
#define _ContactInfo_h_

#include <memory>
#include <string>

namespace fds
{
	class Address
	{ 
			public:
					static std::shared_ptr<Address> Create ();

			private:

			public:
					Address () {}
					std::string 		mFalt;
					std::string 		mSociety;
					std::string 		mArea;
					std::string	    	mDistrict;
					std::string 		mPincode;
//					unsigned long long 	mLogitude;
//					unsigned long long 	mLatitude;
	};

	class ContactInfo
	{
			public:
					static std::shared_ptr<ContactInfo> Create ();

			private:

			public:
					ContactInfo () {}
					std::string 							mPhoneNo;
					std::string 							mSecPhoneNo;
					std::string 							mEmail;
					std::string 							mSecEmail;
					std::shared_ptr<Address>				mAddress{nullptr};
					std::shared_ptr<Address>				mSecAddress{nullptr};
	};
}
#endif
