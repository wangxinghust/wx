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
		// ԭ�����wordDict�����õ�unordered_set
		// hash����ʱ�临�Ӷ�ΪO(1)
		for (auto item : wordDict)
		{
			dicts.insert(item);
			// ����wordDict��string����̳��Ⱥ�����ȣ�����̳��ȿ�ʼ�������ɣ��������maxLength����
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



// ʹ��map���ݴ�������м��� Memory Limit Exceeded
class SolutionWrong {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty()) return vector<string>();
		map<int, vector<string>> res;
		res[0].push_back("");
		vector<bool> dp(s.size() + 1, false);
		// ��ʾ""�ܱ�ƥ��
		dp[0] = true;

		// �������
		for (int i = 1; i <= s.size(); i++) {
			// ��ÿ��i��ǰ��������dp[i]
			for (int j = i - 1; j >= 0; j--) {
				// dp[i]==true��˵����ǰ���ַ����ǿ���ƥ������ģ��ж�i-j���ַ��ܲ��ܱ�ƥ�䣬����dp[i]Ϊtrue
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