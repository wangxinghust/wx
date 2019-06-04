#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray1(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		//±©Á¦½â
		int sum, maxSum = INT_MIN;
		for (int i = 0; i < nums.size(); ++i) {
			sum = nums[i];
			maxSum = max(maxSum, sum);
			for (int j = i + 1; j < nums.size(); ++j) {
				sum += nums[j];
				maxSum = max(maxSum, sum);
			}
		}
		return maxSum;
	}


	//leetcode dp by FujiwaranoSai
	//maxSubArray(nums, i) = maxSubArray(nums, i - 1) > 0 ? maxSubArray(nums, i - 1) : 0 + nums[i]; 
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n);
		dp[0] = nums[0];
		int maxSum = dp[0];
		for (int i = 1; i < n; ++i) {
			dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
			maxSum = max(maxSum, dp[i]);
		}
		return maxSum;
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 0,-3,1,1 };
//	Solution s;
//	int ans = s.maxSubArray(nums);
//	return 0;
//}