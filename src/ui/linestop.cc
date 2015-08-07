#include "linestop.hh"
#include "search.hh"


namespace ui
{
	planner::state::linestop linestop(std::string const& title, ls_list_cref lss, planner::state & s, search_state & ss)
	{
		auto format = [&](ls_cref ls) { return ls_type::format(ls, s); };
		auto filter = [&](ls_cref ls, std::string const& keyword) {
			return ls_type::filter(ls, keyword, s);
		};
		auto sel = search(lss, format, filter, title, ss);
		return lss[sel];
	}

	ls_type view(ls_cref ls, planner::state & s, search_state & ss)
	{
		ls_list lss;
		if (ls.is_line)
			for (auto& stop: s.lines[ls.lkey].stops)
				lss.emplace_back(stop);
		else
			for (auto& line: s.stops[ls.skey].lines)
				lss.emplace_back(line);

		auto title = ls_type::format(ls, s) + "：";
		return linestop(title, lss, s, ss);
	}
}

