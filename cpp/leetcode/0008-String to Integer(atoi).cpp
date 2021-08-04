#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int len = str.length();
		if (len < 1) {
			return 0;
		}
		int index = 0;
		while (index < len && str[index] == ' ') {
			++index;
		}
		bool isMinus = false;
		if (index < len && (str[index] == '+' || str[index] == '-')) {
			if (str[index] == '-') {
				isMinus = true;
			}
			++index;
		}
		int rev = 0;
		while (index < len) {
			int pop = str[index] - '0';
			if (pop < 0 || pop>9) {
				return rev;
			}
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return INT_MAX;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && -pop < (-8))) return INT_MIN;
			if (isMinus) {
				rev = rev * 10 - pop;
			}
			else {
				rev = rev * 10 + pop;
			}
			++index;
		}
		return rev;
	}
};


//int main(int argc, char* argv[]) {
//	Solution s;
//	int x=s.myAtoi("42");
//	return 0;
//}