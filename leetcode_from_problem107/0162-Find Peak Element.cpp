#include <vector>
using namespace std;

// 题目要求: logarithmic complexity

// Approach 1: Linear Scan

// Approach 2: Recursive Binary Search
// mid，斜率为正，说明在右半部分有peak，斜率为负，说明在左半部分有peak
// Runtime: 8 ms, faster than 74.09% of C++ online submissions for Find Peak Element.
// Memory Usage : 8.7 MB, less than 26.26 % of C++ online submissions for Find Peak Element.
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		return search(nums, 0, nums.size() - 1);
	}
private:
	int search(vector<int>& nums, int l, int r) {
		if (l == r) return l;
		int mid = (l + r) / 2;
		// l!=r,在计算mid中，mid+1是一定存在的
		if (nums[mid] > nums[mid + 1]) return search(nums, l, mid);
		return search(nums, mid + 1, r);
	}
};

// Approach 3: Iterative Binary Search
// Runtime: 8 ms, faster than 74.09% of C++ online submissions for Find Peak Element.
// Memory Usage : 8.7 MB, less than 22.91 % of C++ online submissions for Find Peak Element.
class Solution2 {
public:
	int findPeakElement(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] > nums[mid + 1]) r = mid;
			else l = mid + 1; // 注意一个+1，一个不+1
		}
		return l;
	}
};