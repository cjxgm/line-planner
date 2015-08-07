#pragma once
#include <string>

namespace ui
{
	namespace part
	{
		bool edit(int x, int y, int w,
				std::string & s, std::string const& input);
	}

	std::string edit(int x, int y, int w, std::string s={});
}

