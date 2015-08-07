#include "signal.hh"

namespace app
{
	namespace signal
	{
		volatile std::sig_atomic_t quit{};

		void install_callbacks()
		{
			std::signal(SIGINT, [](int) {
					if (quit) throw force_quit{};
					quit = true;
				});
		}
	}
}

