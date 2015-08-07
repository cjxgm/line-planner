#pragma once
#include "../planner/state.hh"

namespace ui
{
	struct stage
	{
		using self = stage;
		using ref  = self &;
		using state = planner::state;

		static ref instance();

		void main();

	private:
		state s;
		state::stop_key src;
		state::stop_key dst;

		void linestop(bool is_dst);
		void dispatch(state::linestop const& ls, bool is_dst);
		void view(state::linestop const& ls, bool is_dst);
		void plan();
	};
}

