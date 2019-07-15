#include <vector>
using namespace std;

// 0300-Longest Increasing Subsequence的简化版
// 3个数的sub数组，遍历nums数组，遇到大的，追加，遇到小的，更新合适位置的值
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() < 3) return false;
		int len = 0;
		int sub[3];
		sub[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			// 如果大于末尾值，则追加
			if (nums[i] > sub[len]) {
				sub[++len] = nums[i];
			}
			else {
				// len为0或1
				if (len) { // len为1
					// 小于等于第一个数
					if (nums[i] <= sub[len - 1])
						sub[len - 1] = nums[i];
					// 大于第一个数，又不大于第二个数，插入到第二个数的位置
					else
						sub[len] = nums[i];
				}
				else // len为0
					// 显然小于等于sub[0]，更新sub[len]也就是sub[0]即可
					sub[len] = nums[i];
			}
			if (len == 2) 
				return true;
		}
		return false;
	}
};