#include <stack>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool isMinus = false;
		if (x == INT_MIN) {
			return 0;
		}
		if (x < 0) {
			isMinus = true;
			x = -x;
		}
		int remainder = 0;
		long ans = 0;
		while (x) {
			remainder = x % 10;
			x = x / 10;
			ans = ans * 10 + remainder;
		}
		if (ans > 2147483647 || ans < -2147483647) {
			return 0;
		}
		return !isMinus ? (int)ans : (int)(-ans);
	}


	//leetcode solution
	int reverse2(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < (-8))) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	s.reverse(123);
//	return 0;
//}