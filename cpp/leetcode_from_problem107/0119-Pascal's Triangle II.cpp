#include <vector>
using namespace std;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> dp(rowIndex + 1);
		dp[0] = 1;
		for (int i = 0; i < rowIndex; i++) {
			dp[i + 1] = dp[i];
			for (int j = i; j > 0; --j) {
				dp[j] = dp[j] + dp[j - 1];
			}
			dp[0] = dp[0];
		}
		return dp;
	}
};