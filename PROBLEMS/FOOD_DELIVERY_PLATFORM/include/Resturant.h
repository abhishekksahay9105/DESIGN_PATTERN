#ifndef _Resturant_h_
#define _Resturant_h_
#include <string>

class Resturant
{
	private:
		std::string 					mResName;
		int								mResturantId;
		std::shared_ptr<ContactInfo>	mContact{nullptr};
		std::shared_ptr<DishDB>			mDishDb{nullptr};

	public:
		static std::shared_ptr<Resturant> Create ();
		
		~Resturant () = default;

		int getResturantId () const {return mResturantId;}
		bool setResturantId (int aResturantId) {mResturantId = aResturantId}

		std::shared_ptr<ContactInfo> get_ResturantContactInfo () const {return mContact;}

		std::shared_ptr<DishDB> get_DishDb {return mDishDb;}

	private:
		Resturant (std::string aResName,  std::shared_ptr<ContactInfo> aContact);
};

class ResturantDB
{
		private:
		public:
};
#endif
