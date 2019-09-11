#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Time Limit Exceeded
class Solution {
	bool isPalindrome(string& s, int start, int end) {
		while (start <= end) {
			if (s[start] != s[end])
				return false;
			++start;
			--end;
		}
		return true;
	}
public:
	int minCut(string s) {
		if (s.empty()) return 0;
		// 从j位置开始，i+1长度的字符串需要切几次
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), s.size() - 1));
		for (int j = 0; j < dp.size(); j++) {
			dp[0][j] = 0;
		}
		for (int i = 1; i < dp.size(); i++) {
			for (int j = 0; j <= s.size() - i - 1; j++) {
				if (isPalindrome(s, j, j + i)) {
					dp[i][j] = 0;
				}
				else {
					for (int k = 0; k < i; k++) {
						dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k - 1][j + k + 1] + 1);
					}
				}
			}
			/*cout << "i= " << i << " ";
			for (int j = 0; j < dp.size(); j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;*/
		}
		return dp[s.size() - 1][0];
	}
};

// leetcode by tqlong
class Solution2 {
public:
	int minCut(string s) {
		int n = s.size();
		vector<int> cut(n + 1, 0); // number of cuts for the first k characters
		for (int i = 0; i <= n; i++)
			cut[i] = i - 1;
		for (int i = 0; i < n; i++) {
			// 依据回文的特点，从中心开始展开往后求，特别的cut[0]=-1
			for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) { // odd length palindrome
				cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);
			}
			for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++) { // even length palindrome
				cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
			}
		}
		return cut[n];
	}
};

//int main() {
//	string s = "aab";
//	string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//	int ret = Solution().minCut(s2);
//	return 0;
//}