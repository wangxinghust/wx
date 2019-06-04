#include <vector>
using namespace std;

class Solution {
public:
	//Runtime: 0 ms
	//Memory Usage: 8.7 MB
	vector<int> plusOne(vector<int>& digits) {
		int i = digits.size() - 1;
		bool carry = true;
		while (carry && i >= 0) {
			if (digits[i] == 9) {
				digits[i] = 0;
				i--;
			}
			else {
				digits[i]++;
				carry = false;
			}
		}
		if (carry) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}


	//leetcode by zezedi 并没有优化，反而时间增长了，之所以空间占用高，是因为题目返回值类型改变了
	//Runtime: 4 ms, faster than 90.98% of C++ online submissions for Plus One.
	//Memory Usage : 8.7 MB, less than 17.95 % of C++ online submissions for Plus One.
	vector<int> plusOne1(vector<int>& digits)
	{
		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				//可以直接跳出返回了
				return digits;
			}
		}
		//循环结束，表示最高位也是9，在末尾加个0，最高位置1即可
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
};