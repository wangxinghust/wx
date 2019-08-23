#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// leetcode by dietpepsi
// https://leetcode.com/problems/burst-nums/discuss/76228/Share-some-analysis-and-explanations
// https://leetcode.com/problems/burst-balloons/discuss/76229/For-anyone-that-is-still-confused-after-reading-all-kinds-of-explanations...
// 可以视作滑动窗口，先计算只有一格的窗口，也就是k=2，然后逐步往上推导，最后返回dp[0][n-1]
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		vector<int> balloons(nums.size() + 2);
		int n = 1;
		// 去掉为0的balloon, 对结果无影响
		for (int x : nums) if (x > 0) balloons[n++] = x;
		balloons[0] = balloons[n++] = 1;

		vector<vector<int>> dp(n, vector<int>(n));
		for (int k = 2; k < n; ++k) {
			for (int left = 0; left < n - k; ++left) {
				int right = left + k;
				for (int i = left + 1; i < right; ++i) {
					dp[left][right] = max(dp[left][right], balloons[left] * balloons[i] * balloons[right] + dp[left][i] + dp[i][right]);
					//cout << "计算出来的 dp[" << left << "][" << right << "]= " << dp[left][right] << endl;
				}
				//cout << "完成一个内循环" << endl;
			}
			//cout << "-----分隔符" << endl;
		}

		return dp[0][n - 1];
	}
};

//int main() {
//	vector<int> nums = { 3,1,5,8 };
//	cout << "最终结果是: " << Solution().maxCoins(nums) << endl;
//	return 0;
//}