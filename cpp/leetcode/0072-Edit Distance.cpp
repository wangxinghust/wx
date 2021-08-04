#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//难点在于抽象出dp
	
	//dp[i - 1][j - 1]	dp[i - 1][j]
	//dp[i][j - 1]		dp[i][j]

	//leetcode by jianchao-li dp
	int minDistance(string word1, std::string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++) {
			dp[i][0] = i;
		}
		for (int j = 1; j <= n; j++) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				}
			}
		}
		return dp[m][n];
	}

	//optimize use only two vectors.
	int minDistance2(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<int> pre(n + 1, 0), cur(n + 1, 0);
		for (int j = 1; j <= n; j++) {
			pre[j] = j;
		}
		for (int i = 1; i <= m; i++) {
			cur[0] = i;
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					cur[j] = pre[j - 1];
				}
				else {
					cur[j] = min(pre[j - 1], min(pre[j], cur[j - 1])) + 1;
				}
			}
			//重新覆盖pre
			pre.assign(cur.begin(), cur.end());
		}
		//这儿只能返回pre[n]，而不是cur[n],当m=0的时候，并不进入循环，意味着cur没有初始化
		return pre[n];
	}

	//optimize  just one vector. 1个vector加一个临时变量
	int minDistance3(string word1, string word2) {
		int m = word1.size(), n = word2.size(), pre;
		vector<int> cur(n + 1, 0);
		for (int j = 1; j <= n; j++) {
			cur[j] = j;
		}
		for (int i = 1; i <= m; i++) {
			pre = cur[0];
			//纵向的cur需要赋值为i
			cur[0] = i;
			for (int j = 1; j <= n; j++) {
				int temp = cur[j];
				if (word1[i - 1] == word2[j - 1]) {
					cur[j] = pre;
				}
				else {
					cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
				}
				pre = temp;				
			}
		}
		return cur[n];
	}

	//类似dp优化标准思路：由二维数组变两数组，再优化为1数组，1临时变量
};

//int main(int argc, char* argv[]) {
//	string word1 = "", word2 = "a";
//	Solution s;
//	s.minDistance2(word1, word2);
//	return 0;
//}