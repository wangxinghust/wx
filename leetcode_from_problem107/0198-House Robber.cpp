#include <vector>
#include <algorithm>
using namespace std;

// recursion Time Limit Exceeded
class Solution {
public:
	int rob(vector<int>& nums) {
		return recursion(nums, 0);
	}
	int recursion(vector<int>& nums, int i) {
		if (i > (int)nums.size() - 1) return 0;
		if (i == nums.size() - 1) return nums[i];
		if (i == nums.size() - 2) return max(nums[i], nums[i + 1]);
		return max(nums[i] + recursion(nums, i + 2), recursion(nums, i + 1));
	}
};

// dp
// Runtime: 4 ms, faster than 72.68% of C++ online submissions for House Robber.
// Memory Usage : 8.5 MB, less than 76.99 % of C++ online submissions for House Robber.
class Solution2 {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return 0;
		int rear = nums[n - 1];
		if (n == 1) return rear;
		int ahead = max(nums[n - 2], nums[n - 1]);
		if (n == 2) return ahead;
		for (int i = n - 3; i >= 0; i--) {
			int tmp = ahead;
			ahead = max(nums[i] + rear, ahead);
			rear = tmp;
		}
		return ahead;
	}
};