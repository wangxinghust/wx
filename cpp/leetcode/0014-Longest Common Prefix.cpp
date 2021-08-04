#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//垂直扫描解法 同LeetCode Approach 2
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) {
			return "";
		}
		if (strs.size() == 1) {
			return strs[0];
		}
		int minLen = strs[0].length();
		for (int i = 0; i + 1 < strs.size(); ++i) {
			minLen = min(strs[i].length(), strs[i + 1].length());
		}
		for (int i = 0; i < minLen; ++i) {
			for (int j = 0; j + 1 < strs.size(); ++j) {
				if (strs[j][i] != strs[j + 1][i])
				{
					return strs[0].substr(0, i);
				}
			}
		}
		return strs[0].substr(0, minLen);
	}

	//Approach 1：Horizontal scanning
};

//int main(int argc, char* argv[]) {
//	vector<string> strs = { "dog","racecar","car" };
//	Solution s;
//	string longest = s.longestCommonPrefix(strs);
//	return 0;
//}