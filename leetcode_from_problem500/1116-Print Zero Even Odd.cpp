#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

class ZeroEvenOdd {
private:
	int n;
	mutex mtx;
	condition_variable cv;
	bool flag = true;
	int count = 1;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		while (count <= n) {
			unique_lock<mutex> lck(mtx);
			cv.wait(lck, [this] {return flag; });
			if (count <= n)
				printNumber(0);
			flag = false;
			lck.unlock();
			cv.notify_all();
		}
		return;
	}

	void even(function<void(int)> printNumber) {
		while (count <= n) {
			unique_lock<mutex> lck(mtx);
			cv.wait(lck, [this] {return !flag && count % 2 == 0; });
			if (count <= n) {
				printNumber(count);
			}
			flag = true;
			++count;
			lck.unlock();
			cv.notify_all();
		}
		return;
	}

	void odd(function<void(int)> printNumber) {
		while (count <= n) {
			unique_lock<mutex> lck(mtx);
			cv.wait(lck, [this] {return !flag && count % 2 == 1; });
			if (count <= n) {
				printNumber(count);
			}
			flag = true;
			++count;
			lck.unlock();
			cv.notify_all();
		}
		return;
	}
};

int main() {
	return 0;
}