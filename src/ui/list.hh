#pragma once
#include <string>
#include <vector>

namespace ui
{
	using list_item_table = std::vector<std::string>;

	namespace part
	{
		bool list(int x, int y, int w, int h,
				list_item_table const& items,
				int & selection, int & yview,
				std::string const& input);
	}

	int list(int x, int y, int w, int h, list_item_table const& items);
	int list(std::initializer_list<std::string> choices);
}

