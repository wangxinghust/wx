#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	//Brute Force: Memory Limit Exceeded
	string longestPalindrome(string s) {
		int length = 1;
		int ahead = 0, rear = 0;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < s.size(); ++j) {
				if (isPalindrome(s, i, j)) {
					if (j - i + 1 > length) {
						length = j - i + 1;
						ahead = i;
						rear = j;
					}
				}
			}
		}
		return s.substr(ahead, length);
	}
	bool isPalindrome(string s, int ahead, int rear) {
		int length = s.size();
		while (ahead >= 0 && rear < length && ahead <= rear) {
			if (s[ahead++] != s[rear--]) {
				return false;
			}
		}
		return true;
	}


	//Expand Around Center
	string longestPalindrome2(string s) {
		if (s.length() < 1) {
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); ++i) {
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = max(len1, len2);
			if (len > end - start) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}
private:
	int expandAroundCenter(string s, int left, int right) {
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R]) {
			--L;
			++R;
		}
		return R - L - 1;//not +1
	}
};

//int main(int argc, char** argv) {
//	Solution s;
//	string str = s.longestPalindrome2("cbbd");
//	return 0;
//}