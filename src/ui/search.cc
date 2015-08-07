#include "search.hh"
#include "widget.hh"
#include "list.hh"
#include "edit.hh"
#include "../utf8.hh"

namespace ui
{
	namespace part
	{
		search_result search(int x, int y, int w, int h,
				list_item_table const& items,
				std::string const& title,
				search_state & ss,
				std::string const& input)
		{
			auto tw = utf8::width(title);
			part::label(x, y, title);
			auto rl = part::list(x, y+1, w, h-1, items, ss.selection, ss.yview, input);
			auto re = part::edit(x+tw, y, w-tw, ss.keyword, input);
			if (rl && re) return search_result::done;
			if (input == "") return search_result::none;
			if (input[0] == '\e' && input != "\ebackspace")
				return search_result::none;
			ss.selection = 0;
			ss.yview = 0;
			return search_result::filter;
		}
	}
}

