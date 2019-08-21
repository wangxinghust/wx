#include <functional>
#include <mutex>
using namespace std;

// leetcode by gs_panwar
// Runtime: 508 ms, faster than 15.38% of C++ online submissions for Building H2O.
// Memory Usage : 12.7 MB, less than 100.00 % of C++ online submissions for Building H2O.
class H2O {
	// The mutex class is a synchronization primitive that can be used to protect shared
	// data from being simultaneously accessed by multiple threads.
	mutex m;
	// The condition_variable class is a synchronization primitive
	// that can be used to block a thread, or multiple threads at 
	// the same time, until another thread both modifies a shared
	// variable (the condition), and notifies the condition_variable.
	condition_variable cv;
	int c = 1;
public:
	H2O() {

	}

	void hydrogen(function<void()> releaseHydrogen) {
		unique_lock<mutex> lk(m);
		// wait causes the current thread to block until the condition
		// variable is notified or a spurious wakeup occurs, optionally
		// looping until some predicate is satisfied.
		cv.wait(lk, [this] {return (c % 3 != 0); });
		// releaseHydrogen() outputs "H". Do not change or remove this line.
		releaseHydrogen();
		++c;
		if (!(c % 3)) {
			lk.unlock();
			// notifies all waiting threads 
			cv.notify_all();
		}
	}

	void oxygen(function<void()> releaseOxygen) {
		unique_lock<mutex> lk(m);
		cv.wait(lk, [this] {return (c % 3 == 0); });
		// releaseOxygen() outputs "O". Do not change or remove this line.
		releaseOxygen();
		++c;
		lk.unlock();
		// notifies one waiting thread 
		cv.notify_one();
	}
};