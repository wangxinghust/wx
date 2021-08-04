#include <string>
using namespace std;
class Solution {
public:
	// Runtime: 8 ms, faster than 92.23% of C++ online submissions for Valid Palindrome.
	// Memory Usage : 9.4 MB, less than 43.45 % of C++ online submissions for Valid Palindrome.
	bool isPalindrome(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			while (i < j && !isdigit(s[i]) && !isalpha(s[i])) ++i;
			while (i < j && !isdigit(s[j]) && !isalpha(s[j])) --j;
			if (isdigit(s[i])) {
				if (s[i] != s[j]) {
					return false;
				}
				else {
					++i;
					--j;
				}
			}
			else if (isalpha(s[i])) {
				if (toupper(s[i]) != toupper(s[j])) {
					return false;
				}
				else {
					++i;
					--j;
				}
			}			
		}
		return true;
	}

	// leetcode by satyakam
	// Runtime: 4 ms, faster than 99.73% of C++ online submissions for Valid Palindrome.
	// Memory Usage : 9.5 MB, less than 26.12 % of C++ online submissions for Valid Palindrome.

	// isalnum: Checks if the given character is an alphanumeric character as classified by the current C locale
	bool isPalindrome2(string s) {
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
			while (!isalnum(s[i]) && i < j) i++;
			while (!isalnum(s[j]) && i < j) j--;
			if (toupper(s[i]) != toupper(s[j])) return false;
		}
		return true;
	}
};

//int main(int argc, char* argv[]) {
//	string str = "A man, a plan, a canal: Panama";
//	bool b = Solution().isPalindrome(str);
//	return 0;
//}