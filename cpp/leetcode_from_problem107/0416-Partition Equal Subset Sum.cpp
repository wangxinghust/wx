#include <iostream>
#include <vector>
using namespace std;

// 依旧是背包问题，且是基础的0-1背包问题，选或者不选
// Runtime: 368 ms, faster than 6.87% of C++ online submissions for Partition Equal Subset Sum.
// Memory Usage : 10.6 MB, less than 52.94 % of C++ online submissions for Partition Equal Subset Sum.
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto& n : nums) {
			sum += n;
		}
		if (sum % 2 == 1) return false;

		sum /= 2;
		vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));

		for (int i = 0; i < nums.size() + 1; i++) {
			dp[i][0] = true;
		}

		/*for (int j = 1; j < sum + 1; j++) {
			dp[0][j] = false;
		}*/

		for (int i = 1; i < nums.size() + 1; i++) {
			for (int j = 1; j < sum + 1; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j >= nums[i - 1]) {
					dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
				}
			}
		}

		return dp[nums.size()][sum];
	}
};

// dp待优化，可转为一维的