#include <vector>
#include <algorithm>
#include <iostream>
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
	//maxSubArray(nums, i) = (maxSubArray(nums, i - 1) > 0 ? maxSubArray(nums, i - 1) : 0) + nums[i]; 
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
class Solution2 {
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

// ����һ�µ�ʱ�Ľ���˼·���鿴���⣬���������ǵ�ʱ++ûд���������Ĵ�����
// Runtime: 8 ms, faster than 71.69% of C++ online submissions for Maximum Subarray.
// Memory Usage : 9.2 MB, less than 91.18 % of C++ online submissions for Maximum Subarray.
class Solution3 {
public:
	int maxSubArray(vector<int>& nums) {
		int max = INT_MIN;
		int N = nums.size();
		int left = 0, right = 0, sum = 0;
		while (left < N && right < N) {
			while (right < N) {
				sum += nums[right++];
				if (sum > max) max = sum;
				if (sum < 0) break;
			}
			while (left < right) {
				sum -= nums[left++];
				// if (sum > max) max = sum;// ò����һ����û�б�Ҫ�� ������һ�䣬����ȫ�Ǹ�����ʱ����sum����0ʱ����max��Ϊ0��
				if (sum > 0) break;
			}
		}
		return max;
	}
};

//int main(int argc, char* argv[]) {
//	//vector<int> nums = { 0,-3,1,1 };
//	vector<int> nums = { -1 };
//	Solution3 s;
//	int ans = s.maxSubArray(nums);
//	cout << ans << endl;
//	char c = getchar();
//	return 0;
//}