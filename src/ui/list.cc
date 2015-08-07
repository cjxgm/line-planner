#include "list.hh"
#include "context.hh"
#include "style.hh"
#include "widget.hh"
#include "../utf8.hh"
#include "../signal.hh"

namespace ui
{
	namespace part
	{
		static bool list_input(int h, int nitem,
				int & selection, int & yview, std::string const& input)
		{
			if (input == "\ereturn") return true;
			if (input == "\eescape") throw ui::cancel{};
			if (input == "\eup") {
				if (selection > 0) selection--;
				if (selection < yview) yview--;
				return false;
			}
			if (input == "\edown") {
				if (selection < nitem-1) selection++;
				if (selection >= yview+h) yview++;
				return false;
			}
			if (input == "\epage:up") {
				for (int i=0; i<h; i++)
					list_input(h, nitem, selection, yview, "\eup");
				return false;
			}
			if (input == "\epage:down") {
				for (int i=0; i<h; i++)
					list_input(h, nitem, selection, yview, "\edown");
				return false;
			}
			return false;
		}

		bool list(int x, int y, int w, int h, list_item_table const& items,
				int & selection, int & yview, std::string const& input)
		{
			auto& c = use_styles();
			c.cursor(false);

			c.style("list");
			frame(x, y, w, h);
			x++; y++; w-=2; h-=2;
			int nitem = items.size();
			auto done = list_input(h, nitem, selection, yview, input);

			yscroll(x+w, y, h, selection, nitem);

			if (!items.size()) return false;

			for (int i=0; i<h; i++, y++) {
				c.style((yview+i == selection ?
							"list:select" :
							"list:unselect"));
				c.at(x, y);
				std::string item;
				if (yview+i < nitem) item = items[yview+i];
				c.put(' ');
				c.put(utf8::fixed_width(item, w-2));
				c.put(' ');
			}

			return done;
		}
	}

	int list(int x, int y, int w, int h, list_item_table const& items)
	{
		auto& c = context::instance();
		int selection{};
		int yview{};
		std::string input;
		while (!app::signal::quit &&
				!part::list(x, y, w, h, items, selection, yview, input)) {
			c.update();
			input = c.get();
		}
		return selection;
	}

	int list(std::initializer_list<std::string> choices)
	{
		auto& c = context::instance();

		int maxw = 4;
		for (auto& choice: choices) {
			auto w = utf8::width(choice);
			if (w > maxw) maxw = w;
		}
		int w = maxw + 4;
		int h = choices.size()+2;

		int selection{};
		int yview{};
		list_item_table items{choices};
		std::string input;
		while (!app::signal::quit) {
			int x = c.w()/2 - w/2;
			int y = c.h()/2 - h/2;
			if (part::list(x, y, w, h, items, selection, yview, input)) break;
			c.update();
			input = c.get();
		}
		return selection;
	}
}

