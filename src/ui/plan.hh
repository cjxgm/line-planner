#pragma once
#include "../planner/plan.hh"
#include "../planner/state.hh"
#include "search.hh"

namespace ui
{
	using plan_type = planner::plan_state;
	using plan_cref = plan_type const&;
	using plan_list = planner::plan_list;
	using plan_list_cref = plan_list const&;
	void plan(plan_list_cref plans, planner::state & s);
	void plan(plan_cref plan, planner::state & s);
}

