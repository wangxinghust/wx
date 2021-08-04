#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	// Time Limit Exceeded
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length()) return false;
		int i = 0, j = 0, k = 0;
		if (k == s3.length()) return true;
		while (k < s3.length()) {
			bool b1 = i < s1.length() && s1[i] == s3[k];
			bool b2 = j < s2.length() && s2[j] == s3[k];
			if (b1 || b2) {
				if (b1 && b2) {
					cout << "test" << endl;
					return isInterleave(s1.substr(i + 1), s2.substr(j), s3.substr(k + 1)) || isInterleave(s1.substr(i), s2.substr(j + 1), s3.substr(k + 1));
				}
				if (b1) {
					i++; k++;
				}
				else {
					j++; k++;
				}
			}
			else {
				return false;
			}
		}
		return true;
	}

	//leetcode Approach 3: Using 2D Dynamic Programming
	int isInterleave3(string s1, string s2, string s3) {
		if (s3.length() != s1.length() + s2.length()) return false;
		vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1));
		for (int i = 0; i <= s1.length(); i++) {
			for (int j = 0; j <= s2.length(); j++) {
				if (i == 0 && j == 0) {
					dp[i][j] = true;
				}
				else if (i == 0) {
					dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
				}
				else if (j == 0) {
					dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
				}
				else {
					dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
				}
			}
		}
		return dp[s1.length()][s2.length()];
	}

	//leetcode Approach 4: Using 1D Dynamic Programming
	//Runtime: 4 ms, faster than 93.46% of C++ online submissions for Interleaving String.
	//Memory Usage : 8.5 MB, less than 63.32 % of C++ online submissions for Interleaving String.
	int isInterleave4(string s1, string s2, string s3) {
		if (s3.length() != s1.length() + s2.length()) return false;
		vector<bool> dp(s2.length() + 1);
		for (int i = 0; i <= s1.length(); i++) {
			for (int j = 0; j <= s2.length(); j++) {
				if (i == 0 && j == 0) {
					dp[j] = true;
				}
				else if (i == 0) {
					dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
				}
				else if (j == 0) {
					dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
				}
				else {
					dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
				}
			}
		}
		return dp[s2.length()];
	}
};
//int main(int argc, char* argv[]) {
//	bool b = Solution().isInterleave4("aabcc", "dbbca", "aadbbcbcac");
//	bool b2 = Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc");
//	bool b3 = Solution().isInterleave("a", "b", "a");
//	/*bool b4 = Solution().isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
//		"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
//		"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");*/
//	return 0;
//}