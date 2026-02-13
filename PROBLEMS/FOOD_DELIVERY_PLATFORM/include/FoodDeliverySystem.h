class FoodDeliverySystem
{
		private:
				std::shared_ptr<Renderer>			mRender{nullptr};
				std::shared_ptr<OrderDB>			mOrderDB{nullptr};
				std::shared_ptr<ResturantDB>		mResturantDB{nullptr};
				std::shared_ptr<CustomerDB>			mCustomerDB{nullptr};

		public:
				FoodDeliverySystem ();

				~FoodDeliverySystem () = default;

				bool RegisterResturant ();

				bool RegisterCustomer ();

				
};
