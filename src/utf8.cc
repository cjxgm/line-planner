#include <cstdlib>
#include <cwchar>
#include <stdexcept>
#include "utf8.hh"

namespace utf8
{
	void init() { std::setlocale(LC_ALL, ""); }

	int length(std::string const& u8s)
	{
		auto len = std::mbstowcs({}, u8s.c_str(), u8s.size());
		if (len == size_t(-1))
			throw std::invalid_argument{"bad utf8 string"};
		return len;
	}

	static auto to_wstring(std::string const& u8s)
	{
		std::wstring ws(length(u8s), {});
		std::mbstowcs(&ws[0], u8s.c_str(), ws.size());
		return std::move(ws);
	}

	static auto from_wstring(std::wstring const& ws)
	{
		auto len = std::wcstombs({}, ws.c_str(), ws.size());
		if (len == size_t(-1))
			throw std::invalid_argument{"bad ucs4 string"};
		std::string u8s(len, {});
		std::wcstombs(&u8s[0], ws.c_str(), u8s.size());
		return std::move(u8s);
	}

	static int width(std::wstring const& ws)
	{
		return ::wcswidth(ws.c_str(), ws.size()*4);
	}

	int width(std::string const& u8s)
	{
		return width(to_wstring(u8s));
	}

	std::string fixed_width(std::string const& u8s, int w, bool strip_left)
	{
		auto ws = to_wstring(u8s);
		auto sw = width(ws);
		if (sw == w) return u8s;

		if (sw > w) {
			if (strip_left)
				while (sw > w) {
					sw -= wcwidth(ws[0]);
					ws.erase(0, 1);
				}
			else
				while (sw > w) {
					sw -= wcwidth(ws.back());
					ws.pop_back();
				}
		}
		if (sw < w) ws += std::wstring(w-sw, ' ');
		return from_wstring(ws);
	}

	std::string fillgap(std::string const& u8s, std::string const& u8gap)
	{
		auto ws = to_wstring(u8s);
		auto wgap = to_wstring(u8gap);
		for (auto pos=ws.size()-1; pos>0; pos--)
			ws.insert(pos, wgap);
		return from_wstring(ws);
	}

	void strip_one_inplace(std::string & u8s, bool front)
	{
		if (!u8s.size()) return;
		auto ws = to_wstring(u8s);
		if (front) ws.erase(0, 1);
		else ws.pop_back();
		u8s = from_wstring(ws);
	}

	std::string from_wchar(wchar_t wc)
	{
		return from_wstring(std::wstring(1, wc));
	}
}

