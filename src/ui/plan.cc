#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdio>
#include "plan.hh"
#include "search.hh"
#include "widget.hh"
#include "../utf8.hh"

namespace ui
{
	static auto plans_format(plan_cref p, planner::state & s)
	{
		std::ostringstream ss;
		ss << "(";
		if (p.nline == 0)
			ss << "原地";
		else if (p.nline == 1)
			ss << "直达";
		else ss << p.nline-1 << "次换乘";
		ss << ") [" << p.size() << "站] ";

		planner::state::line_key last;
		std::string laststop;
		for (auto& trans: p) {
			if (trans.line != last) {
				if (last) ss << "<" << s.name(last) << "> " << laststop << " ";
				last = trans.line;
			}
			laststop = s.stops[trans.stop].name;
		}
		if (last) ss << "<" << s.name(last) << "> " << laststop;

		return ss.str();
	}

	static auto render(plan_cref p, planner::state & s)
	{
		std::ostringstream ss;
		ss << "digraph" << std::endl;
		ss << "{" << std::endl;
		ss << "\tgraph [rankdir=LR]" << std::endl;
		ss << std::endl;
		ss << "\tedge [fontname=\"Fantasque Sans Mono\"]" << std::endl;
		ss << "\tedge [fontsize=12]" << std::endl;
		ss << "\tedge [fontcolor=\"#FF0000\"]" << std::endl;
		ss << "\tedge [color=\"#0000AA\"]" << std::endl;
		ss << "\tedge [arrowsize=0.6]" << std::endl;
		ss << std::endl;
		ss << "\tnode [shape=box]" << std::endl;
		ss << "\tnode [style=filled]" << std::endl;
		ss << "\tnode [fontname=\"Fantasque Sans Mono\"]" << std::endl;
		ss << "\tnode [fontsize=11]" << std::endl;
		ss << "\tnode [fontcolor=\"#006600\"]" << std::endl;
		ss << "\tnode [color=\"#00660088\"]" << std::endl;
		ss << "\tnode [fillcolor=\"#00FF0011\"]" << std::endl;
		ss << "\tnode [width=0]" << std::endl;
		ss << std::endl;

		std::string laststop;
		std::string lastline;
		for (auto& t: p) {
			auto stop = utf8::fillgap(s.name(t.stop), "\\n");
			if (laststop != "") {
				auto line = s.name(t.line, false);
				ss << "\t\"" << laststop << "\" -> \"" << stop << "\"";
				if (line != lastline) {
					ss << " [label=\"" << line << "\" color=\"#FF0000\" penwidth=1.5]";
					lastline = std::move(line);
				}
				ss << std::endl;
			}
			laststop = std::move(stop);
		}
		ss << "}" << std::endl;
		return ss.str();
	}

	static void preview(plan_cref p, planner::state & s)
	{
		auto title = s.name(p.front().stop) + " " + plans_format(p, s);
		std::string command = "./preview \"";
		command += title;
		command += "\"";

		// XXX WARNING !!! USE C LIBRARY !!! WARNING XXX //
		auto fp = ::popen(command.c_str(), "w");
		if (!fp) throw std::runtime_error{"component missing"};
		auto script = render(p, s);
		fwrite(script.c_str(), script.size(), 1, fp);
		fclose(fp);
	}


	void plan(plan_list_cref plans, planner::state & s)
	{
		search_state ss;
		try {
			while (true) {
				auto format = [&](auto& p) { return plans_format(p, s); };
				auto filter = [](auto&, auto&) { return true; };

				auto p = search(plans, format, filter, "所有乘车方案", ss);
				plan(plans[p], s);
			}
		}
		catch (ui::cancel) {}
	}

	void plan(plan_cref p, planner::state & s)
	{
		if (p.size() == 1) return;
		info("预览中...");
		preview(p, s);
	}
}

