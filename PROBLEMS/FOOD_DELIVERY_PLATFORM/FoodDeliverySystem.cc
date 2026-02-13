#include <memory>
//=======================================================================================================================
// class FoodDeliverySystem
//=======================================================================================================================
FoodDeliverySystem::FoodDeliverySystem ()
{
		mResturantDB = std::make_shared<ResturantDB>();
		mRender	     = std::make_shared<Renderer>(Renderer);
		mOrderDB     = std::make_shared<OrderDB>;
		mCustomerDB  = std::make_shared<CustomerDB>;
}


bool FoodDeliverySystem::RegisterResturant ()
{
	Resturant (std::string aResName,  std::shared_ptr<ContactInfo> aContact);
}
