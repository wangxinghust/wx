#include <vector>
using namespace std;
class Solution {
public:
	//by wx
	int removeDuplicates1(vector<int>& nums) {
		int len = nums.size();
		if (len < 1) return 0;
		if (len == 1) return 1;
		int firstIndex = 1, secondIndex = 0;
		while (firstIndex < len) {
			if (nums[firstIndex] != nums[secondIndex]) {
				++secondIndex;
				nums[secondIndex] = nums[firstIndex];
				++firstIndex;
			}
			else {
				++firstIndex;
			}
		}
		return secondIndex + 1;
	}


	//leetcode Approach 1: Two Pointers 解法相同
	//Runtime: 20 ms, faster than 96.92% of C++ online submissions for Remove Duplicates from Sorted Array.
	//Memory Usage : 10.1 MB, less than 45.18 % of C++ online submissions for Remove Duplicates from Sorted Array.
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int i = 0;
		for (int j = 1; j < nums.size(); ++j) {
			if (nums[j]!=nums[i]) {
				++i;
				nums[i] = nums[j];
			}
		}
		return i + 1;
	}
};