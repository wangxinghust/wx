#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;
class FooBar {
private:
	int n;
	mutex mtx;
	condition_variable cv;
	bool fooTime;
public:
	FooBar(int n) {
		this->n = n;
		this->fooTime = true;
	}

	void foo(function<void()> printFoo) {
		unique_lock<mutex> lck(mtx);
		for (int i = 0; i < n; i++) {

			cv.wait(lck, [this] {return fooTime; });
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			fooTime = false;
			lck.unlock();
			cv.notify_one();
			lck.lock();
		}
	}

	void bar(function<void()> printBar) {
		unique_lock<mutex> lck(mtx);
		for (int i = 0; i < n; i++) {			
			cv.wait(lck, [this] {return !fooTime; });
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			fooTime = true;
			lck.unlock();
			cv.notify_one();
			lck.lock();
		}
	}
};