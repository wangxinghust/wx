#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4) {
			return res;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			vector<int> numsCut(nums.begin() + i + 1, nums.end());
			threeSum(numsCut, target - nums[i], nums[i]);
		}
		return res;
	}
	void threeSum(vector<int>& nums, int target, int firstNum) {
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue; //avoid repeat
			int j = i + 1, k = nums.size() - 1;
			while (j < k)
			{
				int tmp = nums[i] + nums[j] + nums[k] - target;
				if (tmp > 0)
					k--;
				else if (tmp < 0)
					j++;
				else
				{
					if (k == nums.size() - 1 || (nums[j] != nums[j - 1] || nums[k] != nums[k + 1]))//avoid like[-4,-2,0,0,2,2]
					{
						res.push_back(vector<int>{firstNum, nums[i], nums[j], nums[k]});
					}
					j++;
					k--;
				}
			}
		}
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
//	int target = 0;
//	vector<vector<int> > res;
//	res = s.fourSum(nums, target);
//	return 0;
//}