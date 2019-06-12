#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	//fill the longer array from the end instead of start
	//Runtime: 4 ms, faster than 95.43% of C++ online submissions for Merge Sorted Array.
	//Memory Usage : 8.6 MB, less than 74.44 % of C++ online submissions for Merge Sorted Array.
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] <= nums2[j]) {
				nums1[k] = nums2[j];
				j--;
			}
			else {
				nums1[k] = nums1[i];
				i--;
			}
			k--;
		}
		for (; j >= 0; j--) {
			nums1[j] = nums2[j];
		}
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//
//	vector<int> nums1 = { 1,2,3,0,0,0 }, nums2 = { 2,5,6 };
//	s.merge(nums1, 3, nums2, 3);
//	for (int i : nums1) {
//		cout << i << endl;
//	}
//	return 0;
//}