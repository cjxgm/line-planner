#pragma once
#include <string>
#include "../mixin.hh"

namespace ui
{
	struct file_changed {};
	struct force_quit {};
	struct cancel {};

	struct context : mixin::non_transferable
	{
		virtual ~context() = default;
		static context& instance();

		virtual void clear() = 0;
		virtual void update() = 0;

		using style_name = std::string;
		using style_name_cref = style_name const&;
		virtual void style(style_name_cref sname) = 0;
		virtual void style(style_name_cref sname, int fg, int bg,
				bool bold=false, bool underline=false) = 0;

		virtual void cursor(bool show=false) = 0;
		virtual void at(int x, int y) = 0;
		virtual void put(int ch) = 0;
		virtual void put(std::string const& s) = 0;
		virtual std::string get() = 0;
		virtual void box(int x, int y, int w, int h) = 0;
		// alternative chars
		virtual int char_checker_board() = 0;
		virtual int char_vertical_line() = 0;

		virtual int w() = 0;
		virtual int h() = 0;

		virtual void xline(int x, int y, int w, int ch=' ') = 0;
		virtual void yline(int x, int y, int h, int ch=' ') = 0;
	};
}

