#pragma once
#include <iostream>
#include <string>
#include "state.hh"

namespace planner
{
	using filename_cref = std::string const&;
	state parse(filename_cref fname);
	state parse(std::istream& is);
}

