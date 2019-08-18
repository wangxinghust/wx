#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray1(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		//������
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
	// ����dp�����ұ߽�Ϊ׼���õ�������������飬�ڼ���dp�������ҵ�maxSum
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

// 2019��8��18��19:37:22 ͷ������
// ����˼·�ǻ����������⣬δ�ܳɹ����
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
				// ����nums[j]�󣬷���nums[j]>sum������ǰһ�̵�sumС��0��ֱ�Ӹĳ�sum<0?
				//if (nums[j] > sum) break;
				if (sum < 0) { j++; break; } // ��Ϊ��ǰsum<0����Ҫj++��������һ����ȥ������������ѭ��
				else j++;
			}
			i = j;			
		}
		return max;
	}
};
// �������ڣ�����ѭ�������ѭ��left���ڲ�ѭ��right����������ͬһ��ѭ����������left����������left=right�ĸ�ֵ
// ��Ҫ�μǻ������ڵĽⷨ

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 0,-3,1,1 };
//	Solution2 s;
//	int ans = s.maxSubArray(nums);
//	return 0;
//}