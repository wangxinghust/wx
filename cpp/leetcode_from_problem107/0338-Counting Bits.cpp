#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// 就像vector开辟空间一样，以2的指数的形式向上增加，每次复制前面的数，+1即可
//   0
//   1
//  10
//  11
// 100
// 101
// 110
// 111
//1000
//1001
//1010
//1011
//1100
//1101
//1110
//1111
// Runtime: 56 ms, faster than 48.03% of C++ online submissions for Counting Bits.
// Memory Usage : 9.6 MB, less than 75.61 % of C++ online submissions for Counting Bits.
class Solution {
public:
	vector<int> countBits(int num) {
		if (num == 0) return vector<int>{0};
		if (num == 1) return vector<int>{0, 1};
		vector<int> ans(num + 1, 0);
		ans[1] = 1;
		for (int i = 2; i <= num; i *= 2) {
			for (int j = i; j < 2 * i && j <= num; j++) {
				ans[j] = ans[j - i] + 1;
				//cout << "ans[j]:" << ans[j] << " ans[j-i]:" << ans[j - i] << " j:" << j << " i:" << i << endl;
			}
		}
		return ans;
	}
};

//int main() {
//	vector<int> ans = Solution().countBits(5);
//	for (int n : ans) {
//		cout << n << " ";
//	}
//	cout << endl;
//	return 0;
//}