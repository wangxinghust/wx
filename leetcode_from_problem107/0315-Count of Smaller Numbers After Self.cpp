#include <vector>
#include <algorithm>
using namespace std;

// brute force: Time Limit Exceeded
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> ans(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] < nums[i]) ++ans[i];
			}
		}
		return ans;
	}
};

// leetcode by ywangbc
// Runtime: 160 ms, faster than 17.57% of C++ online submissions for Count of Smaller Numbers After Self.
// Memory Usage : 10.1 MB, less than 90.10 % of C++ online submissions for Count of Smaller Numbers After Self.
class Solution2 {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> db;
		vector<int> result(nums.size());
		// 利用插入排序，一边从后向前遍历，一边往db数组里插入遍历后的数
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			// lower_bound: Returns an iterator pointing to the first element in the range [first, last) that is not less than (i.e. greater or equal to) value, or last if no such element is found.
			auto it = lower_bound(db.begin(), db.end(), nums[i]);
			result[i] = it - db.begin();
			db.insert(it, nums[i]);
		}
		return result;
	}
};

// TODO: learn higher order solutions
// merge sort, binary indexed tree, segment tree

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 5,2,6,1 };
//	vector<int> ret = Solution2().countSmaller(nums);
//	return 0;
//}