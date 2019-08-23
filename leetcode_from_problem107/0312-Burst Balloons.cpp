#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// leetcode by dietpepsi
// https://leetcode.com/problems/burst-nums/discuss/76228/Share-some-analysis-and-explanations
// https://leetcode.com/problems/burst-balloons/discuss/76229/For-anyone-that-is-still-confused-after-reading-all-kinds-of-explanations...
// ���������������ڣ��ȼ���ֻ��һ��Ĵ��ڣ�Ҳ����k=2��Ȼ���������Ƶ�����󷵻�dp[0][n-1]
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		vector<int> balloons(nums.size() + 2);
		int n = 1;
		// ȥ��Ϊ0��balloon, �Խ����Ӱ��
		for (int x : nums) if (x > 0) balloons[n++] = x;
		balloons[0] = balloons[n++] = 1;

		vector<vector<int>> dp(n, vector<int>(n));
		for (int k = 2; k < n; ++k) {
			for (int left = 0; left < n - k; ++left) {
				int right = left + k;
				for (int i = left + 1; i < right; ++i) {
					dp[left][right] = max(dp[left][right], balloons[left] * balloons[i] * balloons[right] + dp[left][i] + dp[i][right]);
					//cout << "��������� dp[" << left << "][" << right << "]= " << dp[left][right] << endl;
				}
				//cout << "���һ����ѭ��" << endl;
			}
			//cout << "-----�ָ���" << endl;
		}

		return dp[0][n - 1];
	}
};

//int main() {
//	vector<int> nums = { 3,1,5,8 };
//	cout << "���ս����: " << Solution().maxCoins(nums) << endl;
//	return 0;
//}