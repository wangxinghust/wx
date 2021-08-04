#include <vector>
#include <set>
#include <list>
#include <unordered_set>
using namespace std;

// 按题目要求只能用位运算来解

// leetcode Approach 1: List operation
// Runtime: 380 ms, faster than 5.15% of C++ online submissions for Single Number.
// Memory Usage : 11.2 MB, less than 21.78 % of C++ online submissions for Single Number.
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		list<int> no_duplicate_list;
		for (int i : nums) {
			auto pos = find(no_duplicate_list.begin(), no_duplicate_list.end(), i);
			if (pos != no_duplicate_list.end()) no_duplicate_list.erase(pos);
			else no_duplicate_list.insert(pos, i);
		}
		return *(no_duplicate_list.begin());
	}
};

// leetcode Approach 2: Hash Table
// hash_set 非标准 换unordered_set
// Runtime: 20 ms, faster than 41.10% of C++ online submissions for Single Number.
// Memory Usage : 11.4 MB, less than 15.99 % of C++ online submissions for Single Number.
class Solution2 {
	int singleNumber(vector<int>& nums) {
		unordered_set<int> hash_table;
		for (int i : nums) {
			if (hash_table.find(i) != hash_table.end()) hash_table.erase(i);
			else hash_table.insert(i);
		}
		return *(hash_table.begin());
	}
};

// leetcode Approach 3: Math
// 2*(a+b+c)-(a+a+b+b+c)=c
// Runtime: 12 ms, faster than 96.86 % of C++ online submissions for Single Number.
// Memory Usage : 11.7 MB, less than 5.68 % of C++ online submissions for Single Number.
class Solution3 {
	int singleNumber(vector<int>& nums) {
		unordered_set<int> set;
		int sum = 0;
		for (int i : nums) {
			sum += i;
			set.insert(i);
		}
		int set_sum = 0;
		for (int i : set) {
			set_sum += 2 * i;
		}
		return set_sum - sum;
	}
};

// leetcode Approach 4: Bit Manipulation
// Runtime: 16 ms, faster than 82.19% of C++ online submissions for Single Number.
// Memory Usage : 9.8 MB, less than 30.12 % of C++ online submissions for Single Number.
class Solution4 {
	int singleNumber(vector<int>& nums) {
		int a = 0;
		for (int i : nums) {
			a ^= i;
		}
		return a;
	}

	// Runtime: 12 ms, faster than 96.86% of C++ online submissions for Single Number.
	// Memory Usage : 9.6 MB, less than 87.92 % of C++ online submissions for Single Number.
	int singleNumber2(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			nums[0] ^= nums[i];
		}
		return nums[0];
	}
};