#include <algorithm>
#include <vector>
#include <map>
#include "plan.hh"

namespace planner
{
	bool plan_state::transit(state::transition const& t)
	{
		if (visited[t.stop]) return false;

		auto& line = back().line;
		if (line.id != t.line.id) nline++;
		else if (line.dir != t.line.dir) return false;

		visited[t.stop] = true;
		push_back(t);
		return true;
	}

	void plan_state::rollback()
	{
		visited[back().stop] = false;
		auto lid = back().line.id;
		pop_back();
		if (back().line.id != lid) nline--;
	}

	struct dfs_searcher
	{
		dfs_searcher(state& s, state::stop_key src,
				state::stop_key dst, int maxnline)
			: s{s}, plan{src}, dst{dst}, maxnline{maxnline} {}

		void operator () ()
		{
			if (plan.nline > maxnline) return;
			if (result.size() && plan.nline > result[0].nline)
				return;

			auto u = plan.back().stop;
			if (u == dst) {
				if (result.size() && plan.nline < result[0].nline)
					result.clear();
				result.push_back(plan);
				return;
			}

			for (auto& t: s.stops[u].transitions)
				if (plan.transit(t)) {
					operator () ();
					plan.rollback();
				}
		}

		plan_list result;
	private:
		state & s;
		plan_state plan;
		state::stop_key dst;
		int maxnline;
	};

	plan_list plan(state & s, state::stop_key src, state::stop_key dst)
	{
		dfs_searcher dfs{s, src, dst, 3};
		dfs();
		std::sort(dfs.result.begin(), dfs.result.end(),
				[](auto& a, auto& b) { return (a.size() < b.size()); });
		return std::move(dfs.result);
	}
}

