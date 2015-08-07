#pragma once
#include <string>

namespace ui
{
	namespace part
	{
		void fill(int x, int y, int w, int h);
		void frame(int x, int y, int w, int h);
		void yscroll(int x, int y, int h, int i, int max);
		void label(int x, int y, std::string const& text);
	}

	void info(std::string const& text);
	void background();
}

