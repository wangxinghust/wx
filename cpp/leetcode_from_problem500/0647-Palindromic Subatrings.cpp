#include <string>
#include <iostream>
using namespace std;


// Runtime: 4 ms, faster than 90.64% of C++ online submissions for Palindromic Substrings.
// Memory Usage : 8.6 MB, less than 72.00 % of C++ online submissions for Palindromic Substrings.
class Solution {
public:
	int countSubstrings(string s) {
		// 先算奇数的
		int result = s.length();
		for (int i = 0; i < s.length(); i++) {
			int j = 1;
			while (i - j >= 0 && i + j < s.length()) {
				if (s[i - j] == s[i + j]) ++result;
				else break;
				++j;
			}			
		}
		// 再累加偶数的
		for (int i = 0; i < s.length() - 1; i++) {			
			if (s[i] == s[i + 1]) {
				++result;
				int j = 1;
				while (i - j >= 0 && i + 1 + j < s.length()) {
					if (s[i - j] == s[i + 1 + j]) ++result;
					else break;
					++j;
				}
			}
		}

		return result;
	}
};

//int main() {
//	cout << Solution().countSubstrings("aaa");
//	cout << Solution().countSubstrings("aaaaa");
//	return 0;
//}