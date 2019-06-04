#include <string>
#include <vector>
using namespace std;


enum Result {
	FALSE,
	TRUE,
	NO_ACCESS
};
class Solution {
public:
	//Wrong Answer
	bool isMatch(string s, string p) {
		if (s.empty() && p.empty()) {
			return true;
		}
		int indexS = 0, indexP = 0;
		if (s.empty()) {
			while (indexP < p.length()) {
				if (p[indexP] != '*') {
					return false;
				}
				++indexP;
			}
			return true;
		}
		if (p.empty()) {
			return false;
		}
		while (indexS < s.length() && indexP < p.length()) {
			if (p[indexP] == '.') {
				++indexS;
				++indexP;
			}
			else if (p[indexP] == '*') {
				if (indexP < 1) {
					return false;
				}
				while (indexS < s.length() && (s[indexS] == p[indexP - 1] || p[indexP - 1] == '.')) {
					++indexS;
				}
				++indexP;
			}
			else {
				if (s[indexS] == p[indexP]) {
					++indexS;
					++indexP;
				}
				else {
					return false;
				}
			}
		}
		if (indexS == s.length() && indexP == p.length()) {
			return true;
		}
		else {
			return false;
		}
	}


	//Recursion
	bool isMatch1(string s, string p) {
		if (p.empty()) {
			return s.empty();
		}
		//第一个字符的比较
		bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
		if (p.length() >= 2 && p[1] == '*') {
			//出现0次||比对一个则s去掉一个递归
			return isMatch1(s, p.substr(2)) || (first_match && isMatch1(s.substr(1), p));
		}
		//这里是保证了s、p非空的，如果p为空，已经return了，如果s为空，则first_match为false，不会继续计算关系表达式
		else {
			return first_match && isMatch1(s.substr(1), p.substr(1));
		}
	}

	//Dynamic Programming Top-Down Variation java改C++
	vector<vector<Result> > memo;
	bool isMatch2(string s, string p) {
		vector<Result> tmp;
		for (int i = 0; i < p.length() + 1; ++i) {
			tmp.push_back(NO_ACCESS);
		}
		for (int i = 0; i < s.length() + 1; ++i) {
			memo.push_back(tmp);
		}
		return dp(0, 0, s, p);
	}
	bool dp(int i, int j, string s, string p) {
		if (memo[i][j] != NO_ACCESS) {
			return memo[i][j] = TRUE;
		}
		bool ans;
		if (j == p.length()) {
			ans = i == s.length();
		}
		else {
			bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));
			if (j + 1 < p.length() && p[j + 1] == '*') {
				ans = (dp(i, j + 2, s, p) || first_match && dp(i + 1, j, s, p));
			}
			else {
				ans = first_match && dp(i + 1, j + 1, s, p);
			}
		}
		memo[i][j] = ans ? TRUE : FALSE;
		return ans;
	}

	//Bottom-Up Variation 动态规划看等式 此题dp[i][j]=dp[i][j+2]可知适合反向遍历（动态规划有正向和反向的）
	bool isMatch3(string s, string p) {
		//+1用来存""的匹配
		vector<vector<bool> > dp(s.length()+1, vector<bool>(p.length()+1));
		//表示""与""匹配
		dp[s.length()][p.length()] = true;

		for (int i = s.length(); i >= 0; --i) {
			for (int j = p.length() - 1; j >= 0; --j) {
				bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));
				if (j + 1 < p.length() && p[j + 1] == '*') {
					dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
				}
				else {
					dp[i][j] = first_match && dp[i + 1][j + 1];
				}
			}
		}
		return dp[0][0];
	}


	//by 剑指offer 不够严谨，采用的是递归的想法
	bool match(string s, string p)
	{
		if (s.empty()&&p.empty())
		{
			return true;
		}
		if (!s.empty() && p.empty())
		{
			return false;
		}
		if (p[1]!= '*')
		{
			if (s[0] == p[0] || (!s.empty() && p[0] == '.'))
			{
				return match(s.substr(1),p.substr(1));
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (s[0] == p[0] || (!s.empty() && p[0] == '.'))
			{
				return match(s, p.substr(2)) || match(s.substr(1), p);
			}
			else
			{
				return match(s, p.substr(2));
			}

		}
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	bool a = s.isMatch3("aab", "c*a*b*");
//	return 0;
//}