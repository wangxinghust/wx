#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//如果为奇数
		if ((nums1.size() + nums2.size()) % 2 == 1)
		{
			int medianIndex = (nums1.size() + nums2.size()) / 2 + 1;
			unsigned int i = 0, j = 0;
			int num = 0;
			int ans = 0;
			while (num < medianIndex)
			{
				if (i >= nums1.size())
				{
					return nums2[medianIndex - nums1.size() - 1];
				}
				if (j >= nums2.size())
				{
					return nums1[medianIndex - nums2.size() - 1];
				}
				if (nums1[i] < nums2[j])
				{
					ans = nums1[i];
					i++;
					num++;
				}
				else
				{
					ans = nums2[j];
					j++;
					num++;
				}
			}
			return ans;
		}
		//如果为偶数
		else
		{
			int medianIndex = (nums1.size() + nums2.size()) / 2;
			unsigned int i = 0, j = 0;
			int num = 0;
			int tmp1 = 0, tmp2 = 0;
			while (num < medianIndex)
			{
				if (i >= nums1.size())
				{
					return (nums2[medianIndex - nums1.size() - 1] + nums2[medianIndex - nums1.size()]) / 2.0;
				}
				if (j >= nums2.size())
				{
					return (nums1[medianIndex - nums2.size() - 1] + nums1[medianIndex - nums2.size()]) / 2.0;
				}
				if (nums1[i] < nums2[j])
				{
					tmp1 = nums1[i];
					i++;
					num++;
				}
				else
				{
					tmp1 = nums2[j];
					j++;
					num++;
				}
			}
			if (i >= nums1.size())
			{
				tmp2 = nums2[j];
			}
			if (j >= nums2.size())
			{
				tmp2 = nums1[i];
			}
			if (i < nums1.size() && j < nums2.size())
			{
				tmp2 = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
			}
			return (tmp1 + tmp2) / 2.0;
		}
	}
};

// Approach 1: Recursive Approach
// Runtime: 20 ms, faster than 74.85% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage : 9.8 MB, less than 50.16 % of C++ online submissions for Median of Two Sorted Arrays.
// 对短的数组进行二分查找，确定短的数组的下标i，即可由中点的定义得知在另一半数组里j取多少，判断i值是否满足要求即可
class Solution2 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		// to ensure m<=n
		if (m > n) {
			vector<int> temp = nums1; nums1 = nums2; nums2 = temp;
			int tmp = m; m = n; n = tmp;
		}
		int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
		while (iMin <= iMax) {
			int i = (iMin + iMax) / 2;
			int j = halfLen - i;
			if (i<iMax && nums2[j - 1]>nums1[i]) {
				// i is too small
				iMin = i + 1;
			}
			else if (i > iMin && nums1[i - 1] > nums2[j]) {
				// i is too big
				iMax = i - 1;
			}
			else {
				// i is perfect
				int maxLeft = 0;
				if (i == 0) { maxLeft = nums2[j - 1]; }
				else if (j == 0) { maxLeft = nums1[i - 1]; }
				else { maxLeft = max(nums1[i - 1], nums2[j - 1]); }

				// odd
				if ((m + n) % 2 == 1) { return maxLeft; }

				int minRight = 0;
				if (i == m) { minRight = nums2[j]; }
				else if (j == n) { minRight = nums1[i]; }
				else { minRight = min(nums1[i], nums2[j]); }

				// even
				return (maxLeft + minRight) / 2.0;
			}
		}
		return 0.0;
	}
};

//int main()
//{
//	vector<int> nums1 = { 1,3 };
//	vector<int> nums2 = { 2 };
//	double ret = Solution2().findMedianSortedArrays(nums1, nums2);
//	return 0;
//}