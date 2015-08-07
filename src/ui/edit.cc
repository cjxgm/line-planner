#include "edit.hh"
#include "style.hh"
#include "../utf8.hh"
#include "../signal.hh"
#include <algorithm>

namespace ui
{
	namespace part
	{
		static bool edit_input(std::string & s, std::string const& input)
		{
			if (input == "") return false;
			if (input == "\ereturn") return true;
			if (input == "\ebackspace") utf8::strip_one_inplace(s);
			if (input[0] == '\e') return false;
			s += input;
			return false;
		}

		bool edit(int x, int y, int w, std::string & s, std::string const& input)
		{
			if (w < 0) return false;
			auto done = edit_input(s, input);

			// render
			auto& c = use_styles();
			c.style("edit");
			c.at(x, y);
			c.put(utf8::fixed_width(s, w, true));

			c.at(x+ std::min(utf8::width(s), w-1), y);
			c.cursor(true);

			return done;
		}
	}

	std::string edit(int x, int y, int w, std::string s)
	{
		auto& c = context::instance();
		std::string input;
		while (!app::signal::quit && !part::edit(x, y, w, s, input)) {
			c.update();
			input = c.get();
		}
		return std::move(s);
	}
}

