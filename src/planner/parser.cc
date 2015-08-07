#include <fstream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include "parser.hh"
#include "../ui/widget.hh"
#include "../watch.hh"

auto planner::parse(filename_cref fname) -> state
{
	while (true) {
		std::ifstream f{fname};
		if (f) return parse(f);
		ui::info("bad file, please fix it.");
		app::watch::wait_change();
	}
}


static std::istream& operator >> (std::istream& is,
		planner::state::direction & dir)
{
	int d;
	if (is >> d) dir = static_cast<planner::state::direction>(d);
	return is;
}

auto planner::parse(std::istream& is) -> state
{
	state s;

	{
		state::line_key lk;
		std::string lname;
		state::stop_key sk;
		std::string sname;
		int sidx;
		std::map<state::line_key, std::map<int, std::string>> line_stop;
		std::map<std::string, state::stop_key> name_key;

		// populate line::name, name_key
		// and reorder stops by their indexs for each line
		while (is >> lk.id >> lname >> sk >> sname >> sidx >> lk.dir) {
			auto& line = s.lines[lk];
			line.name = lname;
			line_stop[lk][sidx] = sname;
			name_key[sname] = sk;
		}

		// populate stop::name (uniquified)
		for (auto& nkpair: name_key)
			s.stops[nkpair.second].name = nkpair.first;

		// populate line::stops
		for (auto& ls: line_stop) {
			auto& ss = s.lines[ls.first].stops;
			for (auto& stop: ls.second)
				ss.push_back(name_key[stop.second]);
		}
	}

	// populate stop::lines
	for (auto& klpair: s.lines) {
		auto& lk = klpair.first;
		auto& line = klpair.second;
		for (auto& sk: line.stops)
			s.stops[sk].lines.insert(lk);
	}

	// populate stop::transitions
	for (auto& klpair: s.lines) {
		auto& lkey = klpair.first;
		auto& line = klpair.second;
		auto& ss = line.stops;
		if (!ss.size()) continue;
		for (auto it=ss.begin(), last=it++; it != ss.end(); ++it, ++last)
			s.stops[*last].transitions.emplace_back(lkey, *it);
	}

	// populate linestop
	for (auto& klpair: s.lines) s.linestops.emplace_back(klpair.first);
	for (auto& kspair: s.stops) s.linestops.emplace_back(kspair.first);

	return std::move(s);
}

