         #include <vector>
using namespace std;
class Solution {
public:
	//dp but complicated
	int uniquePaths(int m, int n) {
		vector<vector<int> > dp(n, vector<int>(m));
		dp[0] = vector<int>(m, 1);
		for (int i = 1; i < n - 1; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k <= j; ++k) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
		//if排除n==1的情况，防止n-2溢出
		if (n > 1) {
			for (int k = 0; k < m; k++) {
				dp[n - 1][m - 1] += dp[n - 2][k];
			}
		}		
		return dp[n - 1][m - 1];
	}

	//leetcode by jianchao-li,  from the elementary to the profound,
	int uniquePaths1(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}

	int uniquePaths2(int m, int n) {
		vector<int> pre(n, 1), cur(n, 1);
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				cur[j] = pre[j] + cur[j - 1];
			}
			swap(pre, cur);
		}
		return pre[n - 1];
	}
	int uniquePaths3(int m, int n) {
		vector<int> cur(n, 1);
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				cur[j] += cur[j - 1];
			}
		}
		return cur[n - 1];
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	int ans = s.uniquePaths(2, 1);
//	return 0;
//}