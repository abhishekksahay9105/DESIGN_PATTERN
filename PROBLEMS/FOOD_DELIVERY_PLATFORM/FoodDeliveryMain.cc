#include <iostream>
#include "FoodDeliverySystem.h"
#include <memory>

int main ()
{
		std::shared_ptr<fds::FoodDeliverySystem> foodDeliverySystem = fds::FoodDeliverySystem::Create ();
		if (foodDeliverySystem)
		{
				foodDeliverySystem->Execute ();
				std::cout << "khush raho bhai" << std::endl;
		}
				
		return 0;
}

