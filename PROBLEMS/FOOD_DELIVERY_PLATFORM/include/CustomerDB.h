#ifndef _CustomerDB_h_
#define _CustomerDB_h_

#include <memory>
#include <unordered_map>
class ContactInfo;
namespace fds
{

		class Customer
		{
				private:
						std::string 					mName;
						int								mId;
						std::string 					mDateOfBirth;
						std::shared_ptr<ContactInfo>	mContactInfo{nullptr};
						
				public:
						std::string get_CustomerName () const {return mName;}

						std::shared_ptr<ContactInfo> get_ContactInfo () const {return mContactInfo;}
		};

		class CustomerDB
		{
				private:
					std::unordered_map<int, Customer> 		mCustomerList;

				public:
					CustomerDB () = default;

					~CustomerDB () = default;

					int Add_Customer (std::string aName, std::string aDateOfBirth, std::shared_ptr<ContactInfo> aContactInfo);

					bool Remove (int aId);
		};
}

#endif
