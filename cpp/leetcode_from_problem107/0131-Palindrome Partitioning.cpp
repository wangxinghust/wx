#include <string>
#include <vector>
#include <queue>
using namespace std;

// leetcode by zhangyu917
class Solution {
	bool isPalindrome(const string& s, int start, int end) {
		while (start <= end) {
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
	void dfs(int index, string& s, vector<string>& path, vector<vector<string>>& ret) {
		if (index == s.size()) {
			ret.push_back(path);
			return;
		}
		for (int i = index; i < s.size(); ++i) {
			if (isPalindrome(s, index, i)) {
				path.push_back(s.substr(index, i - index + 1));
				dfs(i + 1, s, path, ret);
				path.pop_back();
			}
		}
	}
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string> > ret;
		if (s.empty()) return ret;

		vector<string> path;
		dfs(0, s, path, ret);
		
		return ret;
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<string>> ret = Solution().partition("aaab");
//	return 0;
//}