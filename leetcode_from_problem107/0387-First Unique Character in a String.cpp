#include <string>
#include <algorithm>
using namespace std;

// Runtime: 36 ms, faster than 93.58% of C++ online submissions for First Unique Character in a String.
// Memory Usage : 12.8 MB, less than 66.54 % of C++ online submissions for First Unique Character in a String.
class Solution {
public:
	int firstUniqChar(string s) {
		int letters[26];
		for (int i = 0; i < 26; i++) {
			letters[i] = -1;
		}
		for (int i = 0; i < s.length(); i++) {
			if (letters[s[i] - 'a'] == -1)
				letters[s[i] - 'a'] = i;
			else if (letters[s[i] - 'a'] >= 0)
				letters[s[i] - 'a'] = -2;
		}
		int minIndex = INT_MAX;
		for (int i = 0; i < 26; i++) {
			if (letters[i] >= 0)
				minIndex = min(minIndex, letters[i]);
		}
		return minIndex == INT_MAX ? -1 : minIndex;
	}
};

// Approach 1: Linear time solution
// Runtime: 40 ms, faster than 81.31% of C++ online submissions for First Unique Character in a String.
// Memory Usage : 12.7 MB, less than 82.94 % of C++ online submissions for First Unique Character in a String.
// 还是自己的方法稍好，避免了i出现在很长的s串的末尾处，保证第三次遍历最多26次
class Solution2 {
public:
	int firstUniqChar(string s) {
		int letters[26] = { 0 };
		for (int i = 0; i < s.length(); i++) {
			++letters[s[i] - 'a'];
		}
		for (int i = 0; i < s.length(); i++) {
			if (letters[s[i] - 'a'] == 1)
				return i;
		}
		return -1;
	}
};

//int main(int argc,char* argv[]){
//	int index = Solution().firstUniqChar("loveleetcode");
//	return 0;
//}