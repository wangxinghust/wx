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


	//leetcode Approach 1: Two Pointers �ⷨ��ͬ
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int i = 0;
		for (int j = 1; j < nums.size(); ++j) {
			if (nums[j]!=nums[i]) {
				++i;
				nums[j] = nums[i];
			}
		}
		return i + 1;
	}
};