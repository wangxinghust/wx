#include <functional>
#include <mutex>
#include <iostream>
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

H2O c;
void HThread() {
	c.hydrogen([] {
		cout << "H";
		});
}
void OThread() {
	c.oxygen([] {
		cout << "O";
		});
}

int main(int argc, char* argv[]) {
	string test = "HOHOHHOOHOHHHHHOHHHOH";

	cout << "input str: " << test << endl;
	for (int i = 0; i < test.size(); ++i) {		
		if (test[i] == 'H') {
			thread* th = new thread(HThread);
		}
		else if (test[i] == 'O') {
			thread* th = new thread(OThread);
		}
	}
	// 主线程睡眠等待所有子线程执行完毕
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}