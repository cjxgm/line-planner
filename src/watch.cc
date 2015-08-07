#include <thread>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <climits>
#include <sys/inotify.h>
#include <unistd.h>
#include "watch.hh"
using namespace app;

static std::atomic_bool changed;
static std::condition_variable changed_cv;
static std::mutex changed_m;

bool watch::file_changed()
{
	bool result = changed;
	changed = false;
	return result;
}

void watch::wait_change()
{
	std::unique_lock<std::mutex> lock(changed_m);
	changed_cv.wait(lock, []{ return changed.load(); });
	changed = false;
}

void watch::install_watchman(std::string const& dir,
		std::string const& filename)
{
	int id = inotify_init();
	inotify_add_watch(id, dir.c_str(), IN_CREATE|IN_DELETE|IN_MODIFY|IN_MOVE);
	std::thread([id, filename]() {
		constexpr auto buflen = sizeof(inotify_event) + NAME_MAX + 1;
		auto ev = static_cast<inotify_event*>(malloc(buflen));
		while (true) {
			read(id, ev, buflen);
			if (filename == ev->name) {
				{
					std::lock_guard<std::mutex> lock(changed_m);
					changed = true;
				}
				changed_cv.notify_all();
			}
		}
	}).detach();
}

