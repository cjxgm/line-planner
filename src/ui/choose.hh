#pragma once
#include <string>
#include <initializer_list>

namespace ui
{
	std::string choose(std::string const& text, std::initializer_list<std::string> choices);
	bool yesno(std::string const& text);
	void ok(std::string const& text, std::string const& ok_text="确定");
}

