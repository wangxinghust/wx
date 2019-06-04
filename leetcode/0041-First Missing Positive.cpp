#include <vector>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
			//循环交换，使nums[i]-1位置处的值与当前位置的值不相等
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);

		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 2,2,4,1,3 };
//	Solution s;
//	int i = s.firstMissingPositive(nums);
//	return 0;
//}