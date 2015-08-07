#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct bus_key
{
	enum class direction : int { cycle, forward, backward };
	int id;
	direction dir;

	bool operator < (bus_key const& k) const
	{
		if (id < k.id) return true;
		if (id > k.id) return false;
		return (int(dir) < int(k.dir));
	}

	bool operator == (bus_key const& k) const
	{
		return (id == k.id && dir == k.dir);
	}
};
istream& operator >> (istream & is, bus_key::direction & dir)
{
	int i;
	is >> i;
	dir = bus_key::direction(i);
	return is;
}

struct bus
{
	string name;
	map<int, int> route; // <idx, id>
};

struct entry
{
	struct { bus_key key; string name; } line;
	struct { int id; int idx; string name; } stop;
};

using entry_table = vector<entry>;
using station_table = map<int, string>; // <id, name>
using bus_table = map<bus_key, bus>;

int main()
{
	// read entrys
	entry_table et;
	entry e;
	while (cin >> e.line.key.id >> e.line.name
			>> e.stop.id >> e.stop.name >> e.stop.idx
			>> e.line.key.dir)
		et.push_back(e);

	station_table stations;
	bus_table buss;

	// populate station table and bus table
	for (auto& e: et) {
		stations[e.stop.id] = std::move(e.stop.name);
		auto& bus = buss[e.line.key];
		bus.name = std::move(e.line.name);
		bus.route[e.stop.idx] = e.stop.id;
	}

	// generate dot graph
	cout << "digraph G {" << endl;
	for (auto be: buss) {
		auto& k = be.first;
		auto& b = be.second;
		auto last = b.name;
		using bd = bus_key::direction;
		switch (k.dir) {
			case bd::forward: last += "上"; break;
			case bd::backward: last += "下"; break;
			case bd::cycle: last += "环"; break;
		}
		for (auto& re: b.route) {
			auto& sname = stations[re.second];
			cout << "\"" << last << "\" -> \"" << sname << "\"" << endl;
			last = sname;
		}
	}
	cout << "}" << endl;

	// debug
	for (auto be: buss) {
		auto& k = be.first;
		auto& b = be.second;
		cerr << "[" << k.id << "-" << int(k.dir) << "]" << b.name << ": ";
		for (auto& re: b.route)
			cerr << " -> " << stations[re.second];
		cerr << endl;
	}
}

