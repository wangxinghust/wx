#include <unordered_map>
using namespace std;

// leetcode by r_w
// Runtime: 52 ms, faster than 88.99% of C++ online submissions for Insert Delete GetRandom O(1).
// Memory Usage : 22 MB, less than 83.02 % of C++ online submissions for Insert Delete GetRandom O(1).
class RandomizedSet {
	vector<int> nums;
	// 存插入的值，和其在数组中的下标
	unordered_map<int, int> m;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (m.find(val) != m.end()) return false;
		// using emplace_back avoids the extra copy or move operation required when using push_back.
		nums.emplace_back(val);
		// 存入val和对应的下标
		m[val] = nums.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (m.find(val) == m.end()) return false;
		// 取数组末尾处的值
		int last = nums.back();
		// 更改map中存的nums数组末尾值的下标为val值的下标
		m[last] = m[val];
		// 将last值替换到val所在的位置
		nums[m[val]] = last;
		// 弹出nums数组的最后一个元素，相当于将val所在的元素弹出了
		nums.pop_back();
		// 同时清除map中关于val的信息
		m.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */