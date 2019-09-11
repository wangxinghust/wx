#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int len = triangle[triangle.size() - 1].size();
		vector<int> dp(len);
		dp[0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); i++) {
			dp[triangle[i].size() - 1] = dp[triangle[i].size() - 2] + triangle[i][triangle[i].size() - 1];

			for (int j = triangle[i].size() - 2; j >= 1; j--) {
				dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
			}

			dp[0] += triangle[i][0];
		}
		int minPath = INT_MAX;
		for (int n : dp) {
			minPath = min(minPath, n);
		}
		return minPath;
	}
};

//int main() {
//	vector<int> v1 = { 2 };
//	vector<int> v2 = { 3,4 };
//	vector<int> v3 = { 6,5,7 };
//	vector<int> v4 = { 4,1,8,3 };
//	vector<vector<int>> v = { v1,v2,v3,v4 };
//	int ret = Solution().minimumTotal(v);
//	return 0;
//}