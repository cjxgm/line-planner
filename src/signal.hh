#pragma once
#include <csignal>

namespace app
{
	namespace signal
	{
		extern volatile std::sig_atomic_t quit;
		struct force_quit {};

		void install_callbacks();
	}
}

