#include <iostream>
//=======================================================================================================================
//class Resturant 
//=======================================================================================================================

std::shared_ptr<Resturant> Resturant::Create ()
{
		std::cout << "Enter  Resturant Name: \n";
		std::cin >> aResName;

		  std::string                     mResName;
        int                             mResturantId;
        std::shared_ptr<ContactInfo>    mContact{nullptr};
        std::shared_ptr<DishDB>         mDishDb{nullptr};

}
