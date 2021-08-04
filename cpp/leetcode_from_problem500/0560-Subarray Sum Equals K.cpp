#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// 依旧用滑动窗口来解 滑动窗口不太好解，数有正有负，关键在窗口扩大和收缩的条件
// 换成hash的解法，先给出用元素作右边界，计算之前的元素和，再从左到右遍历，找左边界，使之刚好
// Runtime: 40 ms, faster than 62.42% of C++ online submissions for Subarray Sum Equals K.
// Memory Usage : 18 MB, less than 26.67 % of C++ online submissions for Subarray Sum Equals K.
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		if (nums.empty()) return 0;

		int result = 0;

		unordered_map<int, int> right_sum;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			++right_sum[sum];
		}

		sum = 0;

		for (int i = 0; i < nums.size(); i++) {
			result += right_sum[sum + k];
			sum += nums[i];
			--right_sum[sum];
		}
		return result;
	}
};

// Approach #2 Using Cumulative sum [Accepted]
// 大概意思是存储子数组和，根据下标i，j可以直接计算i到j的子数组和 时间复杂度O(n^2) 空间复杂度O(n)

// Approach #3 Without space [Accepted]
class Solution2 {
public:
	int subarraySum(vector<int>& nums, int k) {
		int count = 0;
		for (int start = 0; start < nums.size(); start++) {
			int sum = 0;
			for (int end = start; end < nums.size(); end++) {
				sum += nums[end];
				if (sum == k)
					count++;
			}
		}
		return count;
	}
};

// 或者将上述的hash改一改，遍历，存入hash，找hash里是否有sum-k
// 运行时间和空间占用个上述hash一致
// Runtime: 40 ms, faster than 62.42% of C++ online submissions for Subarray Sum Equals K.
// Memory Usage : 18.1 MB, less than 20.00 % of C++ online submissions for Subarray Sum Equals K.
class Solution3 {
public:
	int subarraySum(vector<int>& nums, int k) {
		if (nums.empty()) return 0;
		int result = 0;

		unordered_map<int, int> right_sum;
		// 无元素时，和为0
		right_sum[0] = 1;

		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];

			result += right_sum[sum - k];

			++right_sum[sum]; // 先加再存，避免将刚存的计入到结果里了
		}

		return result;
	}
};

//int main() {
//	vector<int> nums = { 1 };
//	cout << Solution().subarraySum(nums, 0) << endl;
//
//	vector<int> nums2 = { -174, 703, 438, 871, -241, 781, 429, -215, 177, 273, -628, 106, 235, -410, 145, -793, -451, 913, 807, 596, -982, 709, 585, -629, 966, 623, 947, -467, -405, 552, -858, 8, -252, -128, -659, -233, -836, 588, 324, -817, 175, -329, 510, -388, 878, 398, 231, 730, 66, -528, 857, 383, 928, -924, 199, -750, -868, -652, -133, 408, 391, 685, 483, -31, -986, 945, 271, 778, -96, 677, -961, -130, 990, -891, -431, -317, -676, 479, -919, -20, -814, 3, -89, 34, -292, 548, 201, -119, -94, -442, -934, -491, 208, -722, 115, 527, 73, 636, -681, 857 };
//	cout << Solution().subarraySum(nums2, -469) << endl;
//
//	vector<int> nums3 = { -1,-1,1 };
//	cout << Solution().subarraySum(nums3, 0);
//
//	vector<int> nums4 = { 1,1,1 };
//	cout << Solution().subarraySum(nums4, 2);
//	return 0;
//}