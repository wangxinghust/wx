#include <climits>
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		int rev = 0;
		int tmp = x;
		while (tmp) {
			int pop = tmp % 10;
			tmp /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return false;
			rev = rev * 10 + pop;
		}
		return rev == x;
	}
};

//int main(int argc, int* arcv[]) {
//	Solution s;
//	bool isPalindromeNum = s.isPalindrome(121);
//	return 0;
//}