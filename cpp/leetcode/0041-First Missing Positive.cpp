#include <vector>
using namespace std;

// 排序的话，时间复杂度不满足要求
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		// 基于hash数组的想法，将对应的值存储到相应的区域
		for (int i = 0; i < nums.size(); ++i)
			//循环交换，使nums[i]-1位置处的值与当前位置的值不相等
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);

		// 遍历查值
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};

// 2019年8月18日19:26:32 头条一面遇到
// 面试时最后的思路是用vector<bool>来存，开辟同样大小的数组，同时声明一个flag标记，初始值定为1
// 一边遍历给的数组，一边修改vector<bool>数组相应位置的值，同时flag变量根据bool数组递增（和最后遍历没有区别）

//int main(int argc, char* argv[]) {
//	// vector<int> nums = { 2,2,4,1,3 };
//	vector<int> nums = { 3,4,-1,1 };
//	Solution s;
//	int i = s.firstMissingPositive(nums);
//	return 0;
//}