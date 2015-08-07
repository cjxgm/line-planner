#include "widget.hh"
#include "style.hh"
#include "context.hh"
#include "../utf8.hh"

namespace ui
{
	namespace part
	{
		void fill(int x, int y, int w, int h)
		{
			auto& c = context::instance();
			for (int i=0; i<h; i++, y++)
				c.xline(x, y, w);
		}

		void frame(int x, int y, int w, int h)
		{
			auto& c = context::instance();
			fill(x, y, w, h);
			c.box(x, y, w, h);
		}

		void yscroll(int x, int y, int h, int i, int max)
		{
			auto& c = context::instance();
			c.yline(x, y, h, c.char_vertical_line());
			if (max > 1) y += i*(h-1)/(max-1);
			c.at(x, y);
			c.put(c.char_checker_board());
		}

		void label(int x, int y, std::string const& text)
		{
			auto& c = use_styles();
			c.style("label");
			c.at(x, y);
			c.put(text);
		}
	}

	void info(std::string const& text)
	{
		auto& c = use_styles();

		c.cursor(false);
		c.style("info");
		auto tw = utf8::width(text);
		part::frame(c.w()/2-tw/2-4, c.h()/2-2, tw+8, 5);
		c.at(c.w()/2-tw/2, c.h()/2);
		c.put(text);
		c.update();
	}

	void background()
	{
		auto& c = use_styles();
		c.style("bg");
		part::fill(0, 0, c.w(), c.h());
	}
}

