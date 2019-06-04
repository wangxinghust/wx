#include <vector>
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

//int main()
//{
//	vector<int> nums1 = {  };
//	vector<int> nums2 = { 2,3 };
//	double ret = Solution().findMedianSortedArrays(nums1, nums2);
//	return 0;
//}