#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	//Recursion but Time Limit Exceeded
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '?' || p[0] == '*'));
		if (p[0] == '*') {
			return (first_match && isMatch(s.substr(1), p)) || isMatch(s, p.substr(1));
		}
		else return first_match && (isMatch(s.substr(1), p.substr(1)));
	}

	//leetcode dp
	bool isMatch1(string s, string p) {
		//+1������""��ƥ��
		vector<vector<bool> > dp(s.length() + 1, vector<bool>(p.length() + 1));//Ĭ��ֵΪfalse����������ģ�Ҳ����vector<bool>(p.length()+1,false);
		//��ʾ""��""ƥ��
		dp[s.length()][p.length()] = true;
		//""��"*"ƥ�䣬�����������* ������Խ�磬ֱ���ȶԱ߽紦��һ��Ҳͦ�õ�
		for (int i = p.length() - 1; i >= 0; --i) {
			if (p[i] != '*') break;
			else dp[s.length()][i] = true;
		}
		for (int i = s.length() - 1; i >= 0; --i) {
			for (int j = p.length() - 1; j >= 0; --j) {
				if (s[i] == p[j] || p[j] == '?') {
					dp[i][j] = dp[i + 1][j + 1];
				}
				else if (p[j] == '*') {
					dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
				}
				else {
					dp[i][j] = false;
				}
			}
		}
		return dp[0][0];
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	bool b = s.isMatch("adceb", "*a*b");
//	return 0;
//}