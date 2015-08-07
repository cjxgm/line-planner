#include "style.hh"

auto ui::use_styles() -> context&
{
	static struct singleton
	{
		singleton()
		{
			auto& c = ui::context::instance();
			c.style("info", 0b010, 0b000);
			c.style("choose", 0b000, 0b010);
			c.style("bg", 0b111, 0b000);
			c.style("label", 0b111, 0b000, true);
			c.style("edit", 0b001, 0b000, false, true);
			c.style("list", 0b010, 0b000);
			c.style("list:select", 0b000, 0b010);
			c.style("list:unselect", 0b010, 0b000);
		}
	} s;
	return ui::context::instance();	// for convenience
}

