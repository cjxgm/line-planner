#pragma once
#include <string>
#include "list.hh"

namespace ui
{
	enum class search_result { none, done, filter };

	struct search_state
	{
		std::string keyword;
		int selection{};
		int yview{};

		search_state(std::string const& kw={}) : keyword{kw} {}
	};

	namespace part
	{
		search_result search(int x, int y, int w, int h,
				list_item_table const& items,
				std::string const& title,
				search_state & ss,
				std::string const& input);
	}

	template <class Container, class Format, class Filter>
	int search(Container const& items, Format format, Filter filter,
			std::string const& title,
			search_state & ss);
}

// search.inl
#include <algorithm>
#include <utility>
#include <iterator>
#include <tuple>
#include "context.hh"
#include "list.hh"
#include "../signal.hh"

namespace ui
{
	template <class Container, class Format, class Filter>
	inline auto format_filter(Container const& items,
			Format format, Filter filter, std::string const& keyword)
	{
		Container filtered;
		std::vector<int> index_map;

		{
			int i = 0;
			for (auto& item: items) {
				if (filter(item, keyword)) {
					filtered.push_back(item);
					index_map.push_back(i);
				}
				i++;
			}
		}

		list_item_table litems;
		std::transform(filtered.begin(), filtered.end(),
				std::back_inserter(litems), format);

		return make_tuple(std::move(litems), std::move(index_map));
	}

	template <class Container, class Format, class Filter>
	inline int search(Container const& items, Format format, Filter filter,
			std::string const& title,
			search_state & ss)
	{
		list_item_table litems;
		std::vector<int> index_map;
		std::tie(litems, index_map) = format_filter(items,
				format, filter, ss.keyword);

		auto& c = context::instance();
		std::string input;
		while (!app::signal::quit) {
			auto result = part::search(0, 0, c.w(), c.h(), litems, title, ss, input);
			if (result == search_result::done) break;
			if (result == search_result::filter) {
				std::tie(litems, index_map) = format_filter(items,
						format, filter, ss.keyword);
				// redraw
				part::search(0, 0, c.w(), c.h(), litems, title, ss, "");
			}
			c.update();
			input = c.get();
		}

		return index_map[ss.selection];
	}
}


