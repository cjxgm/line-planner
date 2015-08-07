#include <curses.h>
#include <clocale>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include "context.hh"
#include "../utf8.hh"
#include "../watch.hh"
#include "../signal.hh"

namespace
{
	struct impl : ui::context
	{
		impl()
		{
			::initscr();
			::start_color();
			::nonl();
			::intrflush(::stdscr, false);
			::keypad(::stdscr, true);
			::noecho();
			::halfdelay(1);
			if (!std::getenv("ESCDELAY"))
				::set_escdelay(25);
		}

		~impl() override { ::endwin(); }
		void clear() override { ::erase(); }
		void update() override { ::refresh(); }
		void style(style_name_cref name) override { attrset(styles.at(name)); }

		void style(style_name_cref name, int fg, int bg,
				bool bold=false, bool underline=false) override
		{
			short colors[8] = {
				COLOR_BLACK,		// 0b000
				COLOR_BLUE,			// 0b001
				COLOR_GREEN,		// 0b010
				COLOR_CYAN,			// 0b011
				COLOR_RED,			// 0b100
				COLOR_MAGENTA,		// 0b101
				COLOR_YELLOW,		// 0b110
				COLOR_WHITE,		// 0b111
			};

			int i = styles.size() + 1;
			init_pair(i, colors[fg], colors[bg]);

			int s = COLOR_PAIR(i);
			if (bold) s |= A_BOLD;
			if (underline) s |= A_UNDERLINE;

			styles[name] = s;
		}

		void cursor(bool show=false) override { ::curs_set(show); }
		void at(int x, int y) override { ::move(y, x); }

		void put(int ch) override { ::addch(ch); }
		void put(std::string const& s) override { ::addstr(s.c_str()); }
		std::string get() override
		{
			wint_t wc;
			int r;

			while ((r = ::get_wch(&wc)) == ERR)
				if (app::watch::file_changed())
					throw ui::file_changed{};
				else if (app::signal::quit)
					throw ui::force_quit{};

			if (r == KEY_CODE_YES)
				switch (wc) {
					case KEY_UP: return "\eup";
					case KEY_DOWN: return "\edown";
					case KEY_LEFT: return "\eleft";
					case KEY_RIGHT: return "\eright";
					case KEY_RESIZE: return "\eresize";
					case KEY_HOME: return "\ehome";
					case KEY_END: return "\eend";
					case KEY_PPAGE: return "\epage:up";
					case KEY_NPAGE: return "\epage:down";
					default: return "\eunknown";
				};
			switch (wc) {
				case 127: return "\ebackspace";
				case '\r': return "\ereturn";
				case '\t': return "\etab";
				case '\e': return "\eescape";
				default: return utf8::from_wchar(wc);
			};
		}

		void box(int x, int y, int w, int h) override
		{
			if (w < 2 || h < 2) return;

			at(x, y);
			put(ACS_ULCORNER);
			at(x+w-1, y);
			put(ACS_URCORNER);
			at(x, y+h-1);
			put(ACS_LLCORNER);
			at(x+w-1, y+h-1);
			put(ACS_LRCORNER);

			xline(x+1, y    , w-2, ACS_HLINE);
			xline(x+1, y+h-1, w-2, ACS_HLINE);
			yline(x    , y+1, h-2, ACS_VLINE);
			yline(x+w-1, y+1, h-2, ACS_VLINE);
		}
		int char_checker_board() override { return ACS_CKBOARD; }
		int char_vertical_line() override { return ACS_VLINE; }

		int w() override { return getmaxx(::stdscr); }
		int h() override { return getmaxy(::stdscr); }

		void xline(int x, int y, int w, int ch=' ') override
		{
			for (int i=0; i<w; i++, x++) {
				at(x, y);
				put(ch);
			}
		}

		void yline(int x, int y, int h, int ch=' ') override
		{
			for (int i=0; i<h; i++, y++) {
				at(x, y);
				put(ch);
			}
		}

	private:
		using style_table = std::unordered_map<style_name, int>;
		style_table styles;
	};
}

auto ui::context::instance() -> context&
{
	static impl ctx;
	return ctx;
}

