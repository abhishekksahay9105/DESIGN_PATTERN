#ifndef _Render_h_
#define _Render_h_

#include <memory>

namespace fds
{
		class ResturantDB;
		class Renderer
		{
				private:
						std::shared_ptr<ResturantDB> mResturantDB{nullptr};

				public:
						Renderer (std::shared_ptr<ResturantDB> aResturantDB);

						bool ShowDefault () {return false;} 

						bool showFiltered () {return false;}
		};
}

#endif
