#pragma once
#include <string>
#include <vector>
#include <set>
#include <map>

namespace planner
{
	struct state
	{
		enum direction : int { cycle, forward, backward };

		struct line_key
		{
			using self = line_key;
			using cref = self const&;

			int id;
			direction dir;
			line_key() : id{}, dir{} {}

			bool operator < (cref k) const
			{
				if (id < k.id) return true;
				if (id > k.id) return false;
				return (dir < k.dir);
			}

			bool operator != (cref k) const
			{
				return (id != k.id || dir != k.dir);
			}

			bool operator == (cref k) const
			{
				return (id == k.id && dir == k.dir);
			}

			bool nil() const { return (*this == self{}); }
			operator bool () const { return (*this != self{}); }
		};
		using stop_key = int;

		struct transition
		{
			line_key line;
			stop_key stop;

			// <line, to>
			transition(line_key const& lk, stop_key const& sk)
				: line(lk), stop(sk) {}

			bool operator < (transition const& t) const
			{
				if (line < t.line) return true;
				if (t.line < line) return false;
				return (stop < t.stop);
			}
			bool operator == (transition const& t) const
			{
				return (line == t.line && stop == t.stop);
			}
		};
		using transition_list = std::vector<transition>;

		struct line
		{
			std::string name;
			std::vector<stop_key> stops;
		};
		struct stop
		{
			std::string name;
			std::set<line_key> lines;
			transition_list transitions; // <line, to>
		};

		struct linestop
		{
			bool is_line;
			union
			{
				line_key lkey;
				stop_key skey;
			};

			linestop() {}
			linestop(line_key lk) : is_line{ true}, lkey(lk) {}
			linestop(stop_key sk) : is_line{false}, skey(sk) {}

			static std::string format(linestop const& ls, state & s);
			static bool filter(linestop const& ls, std::string const& keyword, state & s);
		};

		using line_table = std::map<line_key, line>;
		using stop_table = std::map<stop_key, stop>;
		using linestop_list = std::vector<linestop>;


		std::string name(line_key const& line, bool symbol=true) const;
		std::string name(stop_key const& stop) const;


		line_table lines;
		stop_table stops;
		linestop_list linestops;
	};
}

