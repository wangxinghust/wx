#include <vector>
using namespace std;

// LeetCode by fun4LeetCode: Detailed explanation and generalization of the bitwise operation method for single numbers
// https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int x1 = 0, x2 = 0, mask = 0;

		for (int i : nums) {
			x2 ^= x1 & i;
			x1 ^= i;
			mask = ~(x1 & x2);
			x2 &= mask;
			x1 &= mask;
		}

		return x1;  // Since p = 1, in binary form p = '01', then p1 = 1, so we should return x1. 
					// If p = 2, in binary form p = '10', then p2 = 1, and we should return x2.
					// Or alternatively we can simply return (x1 | x2).
	}
};

// 求和的方法比较容易理解: d(非重复元素乘上倍数-原数组和)/(倍数-1)