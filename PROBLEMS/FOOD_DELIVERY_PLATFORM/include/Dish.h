#ifndef _Dish_h_
#define _Dish_h_

#include <memory>
#include <vector>
#include <string>

class Resturant;

namespace fds
{
	class Dish
	{
		private:
			int 							mDishId{-1};
			int 							mPrice{0};
			int 							mCount{0};
			bool 							mIsNonVeg{false};
			std::string 					mDishName;
			std::string						mImage;
			std::shared_ptr<Resturant> 		mResturant{nullptr};

		public:
			Dish (std::string aDishName, int aPrice, std::string aImage);

			int get_DishId () const {return mDishId;}
			int get_Price () const {return mPrice;}
			int get_DishCount () const {return mCount;}
			std::string get_DishName () const {return mDishName;}
			std::string get_Image () const {return mImage;}

			bool Increment () {mCount++; return true;}
			bool Decrement () {if (mCount)mCount--;}
	};


	class DishDB
	{
		private:
			std::unorder_map<int, std::shared_ptr<Dish>>		mDishList;

		public:
			int Add_DishToDB (std::shared_ptr<Dish> aDish);

			std::shared_ptr<Dish> Get_Dishes (int aDishId) const;

			bool RemoveDish (int aDishId);

			bool FilterDish (int aIsNonVeg, int aPriceLimit);
	};
}
#endif
