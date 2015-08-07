#pragma once
#include "../planner/state.hh"
#include "search.hh"

namespace ui
{
	using ls_type = planner::state::linestop;
	using ls_cref = ls_type const&;
	using ls_list = planner::state::linestop_list;
	using ls_list_cref = ls_list const&;
	ls_type linestop(std::string const& title, ls_list_cref lss, planner::state & s, search_state & ss);
	ls_type view(ls_cref ls, planner::state & s, search_state & ss);
}

