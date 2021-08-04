#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;
		//从末尾倒数第二个开始循环
		for (int i = nums.size() - 2; i >= 0; --i) {
			//相邻比较，直到找到第一个比其后小的
			if (nums[i] < nums[i + 1]) {
				//从这个数以后找出比这个数大且在序列里最小的，与该数交换
				swap(nums[i], nums[minIndex(nums, i + 1, nums[i])]);
				//后面的数排序，升序得到最小的数
				sort(nums.begin() + i + 1, nums.end());
				return;
			}
		}
		//如果一个数也找不到，则排列为降序，按题目要求反转即可，或sort一遍也行
		reverse(nums.begin(), nums.end());
	}
	int minIndex(vector<int>& nums, int i, int numBase) {
		int minIndex = i;
		++i;
		for (; i < nums.size(); ++i) {
			if (nums[i] > numBase && nums[i] < nums[minIndex]) minIndex = i;
		}
		return minIndex;
	}
};


//int main(int argc, char* argv[]) {
//	vector<int> nums = { 2,3,1 };
//	Solution s;
//	s.nextPermutation(nums);
//	for (int i : nums) {
//		cout << i << endl;
//	}
//	return 0;
//}