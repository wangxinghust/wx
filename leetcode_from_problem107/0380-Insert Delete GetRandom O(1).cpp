#include <unordered_map>
using namespace std;

// leetcode by r_w
// Runtime: 52 ms, faster than 88.99% of C++ online submissions for Insert Delete GetRandom O(1).
// Memory Usage : 22 MB, less than 83.02 % of C++ online submissions for Insert Delete GetRandom O(1).
class RandomizedSet {
	vector<int> nums;
	// ������ֵ�������������е��±�
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
		// ����val�Ͷ�Ӧ���±�
		m[val] = nums.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (m.find(val) == m.end()) return false;
		// ȡ����ĩβ����ֵ
		int last = nums.back();
		// ����map�д��nums����ĩβֵ���±�Ϊvalֵ���±�
		m[last] = m[val];
		// ��lastֵ�滻��val���ڵ�λ��
		nums[m[val]] = last;
		// ����nums��������һ��Ԫ�أ��൱�ڽ�val���ڵ�Ԫ�ص�����
		nums.pop_back();
		// ͬʱ���map�й���val����Ϣ
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