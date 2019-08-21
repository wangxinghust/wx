#include <functional>
#include <mutex>
using namespace std;

class Foo {
	int count = 0;
	mutex mtx;
	condition_variable cv;
public:
	Foo() {
		count = 1;
	}

	void first(function<void()> printFirst) {
		unique_lock<mutex> lck(mtx);
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		count = 2;
		lck.unlock();
		cv.notify_all();
	}

	void second(function<void()> printSecond) {
		unique_lock<mutex> lck(mtx);
		while (count != 2) {
			cv.wait(lck);
		}
		//cv.wait(lck, [this] {return count == 2; });
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		count = 3;
		lck.unlock();
		cv.notify_all();
	}

	void third(function<void()> printThird) {
		unique_lock<mutex> lck(mtx);
		while (count != 3) {
			cv.wait(lck);
		}
		//cv.wait(lck, [this] {return count == 3; });
		// printThird() outputs "third". Do not change or remove this line.
		printThird();

		lck.unlock();
	}
};