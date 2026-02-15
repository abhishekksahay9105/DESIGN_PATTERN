#ifndef _Dish_h_
#define _Dish_h_

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>


namespace fds
{
	class Resturant;
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
			Dish (std::string aDishName, int aPrice, std::string aImage,  bool aIsNonVeg);

			int get_DishId () const {return mDishId;}
			int get_Price () const {return mPrice;}
			int get_DishCount () const {return mCount;}
			std::string get_DishName () const {return mDishName;}
			std::string get_Image () const {return mImage;}

			void show ();

			bool Increment () {mCount++; return true;}
			bool Decrement ();
	};


	class DishDB
	{
		private:
			std::unordered_map<int, std::shared_ptr<Dish>>		mDishList;

		public:
			using DishIterator =  std::unordered_map<int, std::shared_ptr<Dish>>::const_iterator;

			DishIterator begin () const {return mDishList.begin();}
			DishIterator end () const {return mDishList.end();}

			int Add_DishToDB (std::shared_ptr<Dish> aDish);

			std::shared_ptr<Dish> Get_Dishes (int aDishId) const;

			bool RemoveDish (int aDishId);

			bool FilterDish (int aIsNonVeg, int aPriceLimit);
	};
}
#endif
