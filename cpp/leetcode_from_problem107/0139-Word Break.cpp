#include <vector>
#include <string>
#include <iostream>
using namespace std;


// dfs Time Limit Exceeded
class Solution {
	bool isEqual(string s, int i, string word) {
		if (word.length() > s.length() - i) return false;
		if (s.substr(i, word.length()) != word) return false;
		return true;
	}
	bool dfs(string s, int i, vector<string>& wordDict) {
		if (i == s.length()) return true;
		for (auto word : wordDict) {
			if (isEqual(s, i, word))
				if (dfs(s, i + word.length(), wordDict))
					return true;
		}
		return false;
	}
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		return dfs(s, 0, wordDict);
	}
};

// leetcode by paul7: dp
// Runtime: 8 ms, faster than 83.23% of C++ online submissions for Word Break.
// Memory Usage : 10.6 MB, less than 73.60 % of C++ online submissions for Word Break.
class Solution2 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty()) return false;
		vector<bool> dp(s.size() + 1, false);
		// 表示""能被匹配
		dp[0] = true;

		// 往后遍历
		for (int i = 1; i <= s.size(); i++) {
			// 对每个i往前遍历，找dp[i]
			for (int j = i - 1; j >= 0; j--) {
				// dp[i]==true，说明往前的字符串是可以匹配出来的，判断i-j的字符能不能被匹配，能则dp[i]为true
				if (dp[j]) {
					string word = s.substr(j, i - j);
					if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
						dp[i] = true;
						break;
					}
				}
			}
		}

		return dp[s.size()];
	}
};



//int main(int argc, char* argv[]) {
//	vector<vector<string>> wordDicts = { { "cats","dog","sand","and","cat" },{ "leet","code" } , { "car","ca","rs" } };
//	vector<string> ss = { "catsandog" ,"leetcode" ,"cars" };
//
//	for (int i = 0; i < ss.size(); i++) {
//		cout << Solution2().wordBreak(ss[i], wordDicts[i]) << endl;
//	}
//	return 0;
//}