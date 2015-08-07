#pragma once
#include <vector>
#include <unordered_map>
#include "state.hh"

namespace planner
{
	struct plan_state : state::transition_list // <line, to>
	{
		int nline{};
		std::unordered_map<state::stop_key, bool> visited;

		plan_state() = default;
		plan_state(state::stop_key src)
			: state::transition_list{state::transition{{}, src}} {}

		bool transit(state::transition const& t);
		void rollback();
	};
	using plan_list = std::vector<plan_state>;

	plan_list plan(state & s, state::stop_key src, state::stop_key dst);
}

