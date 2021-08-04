#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Approach 1: Simple Sorting [Time Limit Exceeded]
class MedianFinder {
	vector<double> store;
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		store.push_back(num);
	}

	double findMedian() {
		sort(store.begin(), store.end());
		int n = store.size();
		return (n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5);
	}
};

// Approach 2: Insertion Sort
// Runtime: 424 ms, faster than 5.33% of C++ online submissions for Find Median from Data Stream.
// Memory Usage : 42.9 MB, less than 24.39 % of C++ online submissions for Find Median from Data Stream.
class MedianFinder2 {
	vector<int> store;
public:
	/** initialize your data structure here. */
	MedianFinder2() {

	}

	void addNum(int num) {
		if (store.empty()) store.push_back(num);
		// lower_bound: returns an iterator pointing to the first element in the range [first,last) that is not less than (i.e. greater or equal to) value, or last if no such element is found.
		else store.insert(lower_bound(store.begin(), store.end(), num), num); // binary search and insertion combined
	}

	double findMedian() {
		int n = store.size();
		return n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5;
	}
};

// Approach 3: Two Heaps
// Runtime: 160 ms, faster than 77.01% of C++ online submissions for Find Median from Data Stream.
// Memory Usage : 42.6 MB, less than 43.42 % of C++ online submissions for Find Median from Data Stream.
class MedianFinder3 {
	priority_queue<int> lo; // max heap
	priority_queue<int,vector<int>,greater<int>> hi; // min heap
public:
	/** initialize your data structure here. */
	MedianFinder3() {

	}

	void addNum(int num) {
		lo.push(num); // add to max heap
		hi.push(lo.top()); // balancing step
		lo.pop();

		// maintain size property
		if (lo.size() < hi.size()) {
			lo.push(hi.top());
			hi.pop();
		}
	}

	double findMedian() {
		return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
	}
};

// Approach 4: Multiset and Two Pointers
// TODO(wangxinghust@hust.edu.cn):

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */