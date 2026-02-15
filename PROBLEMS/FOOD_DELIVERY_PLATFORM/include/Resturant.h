#ifndef _Resturant_h_
#define _Resturant_h_

#include <string>
#include <memory>
#include <unordered_map>

namespace fds
{
		class DishDB;
		class ContactInfo;

		class Resturant
		{
				private:
						std::string 					mResName;
						int								mResturantId;
						std::shared_ptr<ContactInfo>	mContact{nullptr};
						std::shared_ptr<DishDB>			mDishDb{nullptr};

				public:
						static std::shared_ptr<Resturant> Create ();

						Resturant (std::string aResName,  std::shared_ptr<ContactInfo> aContact);
						~Resturant () = default;

						int getResturantId () const {return mResturantId;}
						void setResturantId (int aResturantId) {mResturantId = aResturantId;}

						std::string getResturantName () const {return mResName;}

						std::shared_ptr<ContactInfo> get_ResturantContactInfo () const {return mContact;}

						std::shared_ptr<DishDB> get_DishDb () {return mDishDb;}

		};

		class ResturantDB
		{
				private:
						static std::shared_ptr<ResturantDB> 							mResturantDB;

						int																mLastResturantId{0};

						std::unordered_map<int, std::shared_ptr<Resturant>>       		mResturantList;
						std::unordered_map<std::string, std::shared_ptr<Resturant>>     mEmailResturantList;

				public:
						static std::shared_ptr<ResturantDB> get_ResturantDB ();

						std::unordered_map<int, std::shared_ptr<Resturant>> get_ResturantList () const {return mResturantList;}

						bool Add_Resturant (std::shared_ptr<Resturant> aResturant);
		};


}
#endif
