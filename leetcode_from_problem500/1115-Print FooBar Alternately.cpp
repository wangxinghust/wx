#include <functional>
#include <mutex>
#include <condition_variable>
#include <iostream>
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

//int main(int argc, char* argv[]) {
//	FooBar fb(3);
//	thread t1(&FooBar::foo, &fb, [] {cout << "foo"; });
//	thread t2(&FooBar::bar, &fb, [] {cout << "bar"; });
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}