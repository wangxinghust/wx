#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> > result;
		permuteRecursive(nums, 0, result);
		return result;
	}
	void permuteRecursive(vector<int>& nums, int begin, vector<vector<int> > &result) {
		//先写终止回溯判断条件
		if (begin >= nums.size()) {
			result.push_back(nums);
			return;
		}
		for (int i = begin; i < nums.size(); ++i) {
			swap(nums[begin], nums[i]);
			permuteRecursive(nums, begin + 1, result);
			swap(nums[begin], nums[i]);
		}
	}
};