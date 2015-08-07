#include <iostream>
#include "signal.hh"
#include "utf8.hh"
#include "watch.hh"
#include "ui/context.hh"
#include "ui/widget.hh"
#include "ui/choose.hh"
#include "ui/linestop.hh"
#include "ui/plan.hh"
#include "ui/stage.hh"
#include "planner/parser.hh"
#include "planner/plan.hh"

int main()
{
	using namespace std::string_literals;
	// set title
	std::cout << "\e]0;乘车方案规划器\a" << std::endl;

	std::cout << "installing signal callbacks..." << std::endl;
	app::signal::install_callbacks();

	std::cout << "initializing utf8..." << std::endl;
	utf8::init();

	ui::info("开始监视数据文件……");
	app::watch::install_watchman(".", "linestop");

	ui::info("解析线路站点数据……");
	auto state = planner::parse("linestop");

	ui::stage::instance().main();

	ui::info("exiting...");
}

