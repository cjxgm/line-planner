#include <sstream>
#include "state.hh"
using namespace planner;
using namespace std::string_literals;

std::string state::linestop::format(linestop const& ls, state & s)
{
	return (ls.is_line ?
			"[线路] "s + s.name(ls.lkey) :
			"[站点] "s + s.name(ls.skey));
}

bool state::linestop::filter(linestop const& ls, std::string const& keyword, state & s)
{
	std::istringstream iss{keyword};
	std::string k;
	auto name = (ls.is_line ?
			s.name(ls.lkey) :
			s.name(ls.skey));

	while (iss >> k)
		if (name.find(k) == k.npos)
			return false;

	return true;
}


std::string state::name(line_key const& line, bool symbol) const
{
	auto dir = "";
	switch (line.dir) {
		case cycle   : dir = (symbol ? "•" : "[环线]"); break;
		case forward : dir = (symbol ? "»" : "[上行]"); break;
		case backward: dir = (symbol ? "«" : "[下行]"); break;
	}
	return lines.at(line).name + dir;
}

std::string state::name(stop_key const& stop) const
{
	return stops.at(stop).name;
}

