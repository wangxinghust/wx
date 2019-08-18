#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray1(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		//暴力解
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
	// 基于dp，以右边界为准，得到其和最大的子数组，在计算dp过程中找到maxSum
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

// 2019年8月18日19:37:22 头条二面
// 最后的思路是滑动窗口来解，未能成功解出
// leetcode by ajavadia
// i and j always move forward, so they only make one pass over the array: O(n) time, constant space.

// Runtime: 4 ms, faster than 98.65% of C++ online submissions for Maximum Subarray.
// Memory Usage : 9.1 MB, less than 100.00 % of C++ online submissions for Maximum Subarray.
class Solution2{
public:
	int maxSubArray(vector<int>& nums) {
		int max = INT_MIN;
		int N = nums.size();
		// [i,j] sliding window
		int i = 0, j = 0;
		while (i < N) {
			int sum = 0;
			while (j < N) {
				sum += nums[j];
				if (sum > max) max = sum;
				// 加上nums[j]后，反而nums[j]>sum，表明前一刻的sum小于0，直接改成sum<0?
				//if (nums[j] > sum) break;
				if (sum < 0) { j++; break; } // 改为当前sum<0后，需要j++，跳到下一个数去，否则陷入死循环
				else j++;
			}
			i = j;			
		}
		return max;
	}
};
// 滑动窗口，两重循环，外层循环left，内层循环right，而不是在同一层循环，即便是left递增，而非left=right的赋值
// 需要牢记滑动窗口的解法

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 0,-3,1,1 };
//	Solution2 s;
//	int ans = s.maxSubArray(nums);
//	return 0;
//}