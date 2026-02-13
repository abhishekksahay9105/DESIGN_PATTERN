
class ResturantDB;
class Renderer
{
		private:
				std::shared_ptr<ResturantDB> mResturantDB{nullptr};

		public:
				Renderer (std::shared_ptr<ResturantDB> aResturantDB);

				bool ShowDefault ();

				bool showFiltered ();
};
