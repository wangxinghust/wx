#include <math.h>
class Solution {
public:

	//二分查找 找最后一个小于等于所需查找的对象
	//Runtime: 4 ms, faster than 93.46% of C++ online submissions for Sqrt(x).
	//Memory Usage : 8.4 MB, less than 49.49 % of C++ online submissions for Sqrt(x).
	int mySqrt(int x) {
		//假设x是非负的，也可以手动加入x非负的判断，这里用于处理0,1的情况，避免除0出错
		if (x <= 1) return x;

		int left = 0;
		int right = x;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			//由mid*mid<=x改为mid<=x/mid，避免溢出
			if (mid <= x / mid) {
				left = mid + 1;
			}
			else if (mid > x / mid) {
				right = mid - 1;
			}
		}
		return left - 1;
	}
};

int main(int argc, char* argv[]) {
	Solution s;
	int ans = s.mySqrt(0);
	return 0;
}