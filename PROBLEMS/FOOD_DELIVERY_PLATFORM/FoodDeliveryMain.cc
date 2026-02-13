

typedef enum todo
{
		cRenderDishes = 0,
		cLoginAsCustomer,
		cLoginAsResturant,
		cOrderDishes,
		
} todo;


int main ()
{
		int isServerdown = false;
		
		todoT mState = cRenderDishes;
		while (!isServerdown)
		{

				switch (mState)
				{
						case cRenderDishes:
								break;
						case cLoginAsCustomer:
								break;
						case cLoginAsResturant:
								
								break;
						case cOrderDishes:
								break;
						default:
								mState = cRenderDishes;
								break;
				}
		}
}

