#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

// leetcode by pan-yang: dfs+dp
// Runtime: 4 ms, faster than 99.86% of C++ online submissions for Word Break II.
// Memory Usage : 10 MB, less than 95.32 % of C++ online submissions for Word Break II.
class Solution {
	void getPath(const vector<bool>& dp, vector<string>& res, const unordered_set<string>& dicts, string& s, string cur, int start, int minLength, int maxLength)
	{
		int length = s.size();
		for (int pos = start + minLength; pos <= min(start + maxLength, length); ++pos)
		{
			if (dp[pos] && dicts.count(s.substr(start, pos - start)))
			{
				if (pos == length)
					// avoids the extra copy or move operation required when using push_back.
					res.emplace_back(cur + s.substr(start, pos - start));
				else
					getPath(dp, res, dicts, s, cur + s.substr(start, pos - start) + " ", pos, minLength, maxLength);
			}
		}
	}

public:
	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		unordered_set<string> dicts;
		vector<string> res;
		int minLength = INT_MAX, maxLength = 0;
		// 原题给的wordDict即是用的unordered_set
		// hash查找时间复杂度为O(1)
		for (auto item : wordDict)
		{
			dicts.insert(item);
			// 计算wordDict中string的最短长度和最长长度，从最短长度开始遍历即可，回退最多maxLength即可
			minLength = min(minLength, (int)item.length());
			maxLength = max(maxLength, (int)item.length());
		}
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = minLength; i <= s.size(); ++i)
		{
			for (int len = minLength; len <= min(maxLength, i); ++len)
			{
				if (dp[i - len] && dicts.count(s.substr(i - len, len)))
					dp[i] = true;
			}
		}
		if (dp[s.size()])
		{
			getPath(dp, res, dicts, s, "", 0, minLength, maxLength);
		}
		return res;
	}
};



// 使用map来暂存产生的中间结果 Memory Limit Exceeded
class SolutionWrong {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty()) return vector<string>();
		map<int, vector<string>> res;
		res[0].push_back("");
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
						for (auto str : res[j]) {
							res[i].push_back((str == "" ? "" : str + " ") + word);
						}
					}
				}
			}
		}

		return res[s.size()];
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<string>> wordDicts = { { "cats","dog","sand","and","cat" },{ "leet","code" } , { "car","ca","rs" },{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"} };
//	vector<string> ss = { "catsandog" ,"leetcode" ,"cars","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" };
//
//	for (int i = 0; i < ss.size(); i++) {
//		vector<string> res = Solution().wordBreak(ss[i], wordDicts[i]);
//		for (string str : res) {
//			cout << str << "####";
//		}
//		cout << endl;
//	}
//	return 0;
//}