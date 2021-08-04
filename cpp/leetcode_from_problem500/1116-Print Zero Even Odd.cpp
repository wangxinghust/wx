#include <functional>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>
#include <iostream>
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

void printNumber(int x) {
	std::this_thread::sleep_for(std::chrono::seconds(1));//延缓字符输出时间
	cout << x;
}

//int main() {
//	ZeroEvenOdd zeo(5);
//	vector<thread> threads;
//	threads.push_back(thread(&ZeroEvenOdd::zero, &zeo, printNumber));
//	threads.push_back(thread(&ZeroEvenOdd::even, &zeo, printNumber));
//	threads.push_back(thread(&ZeroEvenOdd::odd, &zeo, printNumber));
//	for (int i = 0; i < 3; i++) {
//		threads[i].join();
//	}
//	cout << endl;
//	return 0;
//}