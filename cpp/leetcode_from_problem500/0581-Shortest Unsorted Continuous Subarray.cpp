#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


// Approach 1: Brute Force
// 对所有的i，j判断这个子序列能否让其满足
// Approach 2: Better Brute Force
// 在法1基础上，基于插入排序的思路，标记出现在错误地方的i，j，对每个i都遍历

// Approach 3: Using Sorting
// 排序后，与排序后的数组对比，找出现在错误位置的元素
// Time complexity : O(nlogn). Sorting takes nlogn time.
// Space complexity : O(n).We are making copy of original array.
// Runtime: 44 ms, faster than 48.61% of C++ online submissions for Shortest Unsorted Continuous Subarray.
// Memory Usage : 11.3 MB, less than 42.86 % of C++ online submissions for Shortest Unsorted Continuous Subarray.
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> snums = nums;
		sort(snums.begin(), snums.end());
		int start = snums.size(), end = 0;
		for (int i = 0; i < snums.size(); i++) {
			if (snums[i] != nums[i]) {
				start = min(start, i);
				end = max(end, i);
			}
		}
		return (end - start >= 0) ? end - start + 1 : 0;
	}
};

// Approach 4: Using Stack
class Solution2 {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		stack<int> st;
		int l = nums.size(), r = 0;
		for (int i = 0; i < nums.size(); i++) {
			while (!st.empty() && nums[st.top()] > nums[i]) {
				l = min(l, st.top());
				st.pop();
			}
			st.push(i);			
		}
		stack<int> st2;
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!st2.empty() && nums[st2.top()] < nums[i]) {
				r = max(r, st2.top());
				st2.pop();
			}
			st2.push(i);
		}
		return r - l > 0 ? r - l + 1 : 0;
	}
};

// Approach 5: Without Using Extra Space
// Runtime: 36 ms, faster than 74.54% of C++ online submissions for Shortest Unsorted Continuous Subarray.
// Memory Usage : 10.4 MB, less than 100.00 % of C++ online submissions for Shortest Unsorted Continuous Subarray.
class Solution3 {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int minV = INT_MAX, maxV = INT_MIN;
		bool flag = false;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1]) {
				flag = true;
			}
			if (flag) {
				minV = min(minV, nums[i]);
			}
		}
		flag = false;
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] > nums[i + 1]) {
				flag = true;
			}
			if (flag) {
				maxV = max(maxV, nums[i]);
			}
		}
		int l, r;
		for (l = 0; l < nums.size(); l++) {
			if (minV < nums[l])
				break;
		}
		for (r = nums.size() - 1; r >= 0; r--) {
			if (maxV > nums[r])
				break;
		}
		return r - l < 0 ? 0 : r - l + 1;
	}
};

// 简单改进，反而空间占用增加，运行时间未减少
// Runtime: 36 ms, faster than 74.54 % of C++ online submissions for Shortest Unsorted Continuous Subarray.
// Memory Usage : 10.5 MB, less than 71.43 % of C++ online submissions for Shortest Unsorted Continuous Subarray.
class Solution4 {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int minV = INT_MAX, maxV = INT_MIN;
		bool flag = false;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1]) {
				flag = true;
				minV = min(minV, nums[i]);
			}
		}
		flag = false;
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] > nums[i + 1]) {
				flag = true;
				maxV = max(maxV, nums[i]);
			}
		}
		int l, r;
		for (l = 0; l < nums.size(); l++) {
			if (minV < nums[l])
				break;
		}
		for (r = nums.size() - 1; r >= 0; r--) {
			if (maxV > nums[r])
				break;
		}
		return r - l < 0 ? 0 : r - l + 1;
	}
};