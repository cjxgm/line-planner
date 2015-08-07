#pragma once
#include <string>

namespace utf8
{
	void init();
	int length(std::string const& u8s);
	int width(std::string const& u8s);
	std::string fixed_width(std::string const& u8s, int w,
			bool strip_left=false);
	std::string from_wchar(wchar_t wc);
	std::string fillgap(std::string const& u8s, std::string const& u8gap="\n");
	void strip_one_inplace(std::string & u8s, bool front=false);

	inline std::string strip_one(std::string u8s, bool front=false)
	{
		strip_one_inplace(u8s, front);
		return std::move(u8s);
	}
}

