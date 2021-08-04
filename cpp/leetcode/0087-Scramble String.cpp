#include <string>
using namespace std;
class Solution {
public:
	//leetcode by raychan
	//Runtime : 4 ms, faster than 97.71 % of C++ online submissions for Scramble String.
	//Memory Usage : 9.6 MB, less than 76.57 % of C++ online submissions for Scramble String.
	bool isScramble(string s1, string s2) {
		if (s1 == s2) return true;
		int len = s1.length();
		int count[26] = { 0 };
		for (int i = 0; i < len; i++) {
			count[s1[i] - 'a']++;
			count[s2[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (count[i] != 0) return false;
		}

		for (int i = 1; i <= len - 1; i++) {
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
			if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))) return true;
		}
		return false;
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	string s1 = "great", s2 = "rgeat";
//	bool b = s.isScramble(s1, s2);
//	return 0;
//}