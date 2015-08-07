#include "choose.hh"
#include "style.hh"
#include "widget.hh"
#include "../utf8.hh"
#include "../signal.hh"
#include <algorithm>

namespace ui
{
	std::string choose(std::string const& text,
			std::initializer_list<std::string> choices)
	{
		auto& c = use_styles();

		int wchoice = 0;
		for (auto& choice: choices) {
			int w = utf8::width(choice);
			if (w > wchoice) wchoice = w;
		}
		wchoice += 2;

		int wchoices = wchoice*choices.size() + choices.size()-1;
		int wtext = utf8::width(text);
		int w = std::max(wtext, wchoices);

		c.cursor(false);

		c.style("info");
		part::frame(c.w()/2-w/2-4, c.h()/2-3, w+8, 6);
		c.at(c.w()/2-w/2, c.h()/2-1);
		c.put(text);

		c.style("choose");
		auto x = c.w()/2-wchoices/2;
		auto y = c.h()/2+1;
		for (auto& choice: choices) {
			c.at(x, y);
			c.put(' ');
			c.put(utf8::fixed_width(choice, wchoice-1));
			x += wchoice + 1;
		}

		c.update();
		return c.get();
	}

	bool yesno(std::string const& text)
	{
		while (!app::signal::quit) {
			auto choice = choose(text, {"是", "否"});
			if (choice == "y") return true;
			if (choice == "n") return false;
			if (choice == "\ereturn") return true;
			if (choice == "\ebackspace" || choice == "\eescape") return false;
		}
		return false;
	}

	void ok(std::string const& text, std::string const& ok_text)
	{
		while (!app::signal::quit) {
			auto choice = choose(text, {ok_text});
			if (choice == "\ereturn") return;
		}
	}
}

