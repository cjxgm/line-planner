#pragma once
#include <string>

namespace app
{
	namespace watch
	{
		bool file_changed();
		void wait_change();
		void install_watchman(std::string const& dir, std::string const& filename);
	}
}

