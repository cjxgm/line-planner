#include <string>
#include "stage.hh"
#include "linestop.hh"
#include "widget.hh"
#include "choose.hh"
#include "plan.hh"
#include "../watch.hh"
#include "../planner/parser.hh"
#include "../planner/plan.hh"

using namespace std::string_literals;

auto ui::stage::instance() -> ref
{
	static self s;
	return s;
}

void ui::stage::main()
{

	ui::info("开始监视数据文件……");
	app::watch::install_watchman(".", "linestop");

	ui::info("解析线路站点数据……");
	s = planner::parse("linestop");

	while (true) {
		try {
			linestop(false);
			try {
				if (!ui::list({"退出", "返回"}))
					break;
			}
			catch (ui::cancel) {}
		}

		catch (ui::file_changed) {
			ui::info("解析线路站点数据……");
			s = planner::parse("linestop");
		}

		catch (ui::force_quit) {
			app::signal::quit = false;
			try {
				if (!ui::list({"强制退出", "返回主界面"}))
					break;
			}
			catch (ui::cancel) {}
		}

		catch (app::signal::force_quit) {
			app::signal::quit = false;
			ui::ok("成功触发不可取消的强制退出");
			break;
		}

		catch (std::exception const& e) {
			app::signal::quit = false;
			ui::ok("程序出现异常："s + e.what());
			try {
				if (!ui::list({"强制退出", "返回主界面"}))
					break;
			}
			catch (ui::cancel) {}
		}

		catch (...) {
			app::signal::quit = false;
			ui::ok("致命错误");
			throw;
		}
	}
}

void ui::stage::linestop(bool is_dst)
{
	search_state ss;
	auto prompt = (is_dst ? "搜索终点：" : "搜索起点：");

	try {
		while (true)
			dispatch(ui::linestop(prompt, s.linestops, s, ss), is_dst);
	}
	catch (ui::cancel) {}
}

void ui::stage::dispatch(state::linestop const& ls, bool is_dst)
{
	auto mark = (is_dst ? "设为终点" : "设为起点");

	if (ls.is_line) view(ls, is_dst);
	else try {
		switch (ui::list({mark, "查看停靠线路"})) {
			case 0:
				if (is_dst) {
					dst = ls.skey;
					plan();
				}
				else {
					src = ls.skey;
					linestop(true);
				}
				break;
			case 1: view(ls, is_dst); break;
		}
	}
	catch (ui::cancel) {}
}

void ui::stage::view(state::linestop const& ls, bool is_dst)
{
	ui::search_state ss;

	try {
		while (true)
			dispatch(ui::view(ls, s, ss), is_dst);
	}
	catch (ui::cancel) {}
}

void ui::stage::plan()
{
	auto src_name = s.name(src);
	auto dst_name = s.name(dst);
	ui::info("搜寻方案 "s + src_name + " -> " + dst_name + " ……");
	auto plans = planner::plan(s, src, dst);
	if (plans.size()) ui::plan(plans, s);
	else ui::ok("没有合适的方案 "s + src_name + " -> " + dst_name);
}

