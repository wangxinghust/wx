#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Approach #1 (Naive Linear Search) [Time Limit Exceeded]

// Approach #2 (Sorting)
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() < 2) return false;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (nums[i] == nums[i + 1]) return true;
		}
		return false;
	}
};

// Approach #3 (Hash Table)
// Runtime: 56 ms, faster than 22.47% of C++ online submissions for Contains Duplicate.
// Memory Usage : 16.3 MB, less than 68.74 % of C++ online submissions for Contains Duplicate.
class Solution2 {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() < 2) return false;
		set<int> newNums;
		for (int x : nums) {
			if (newNums.find(x) != newNums.end()) return true;
			newNums.insert(x);
		}
		return false;
	}
};