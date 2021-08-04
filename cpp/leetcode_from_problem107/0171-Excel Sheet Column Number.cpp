#include <string>
using namespace std;

// Runtime: 8 ms, faster than 18.92% of C++ online submissions for Excel Sheet Column Number.
// Memory Usage : 8.2 MB, less than 34.99 % of C++ online submissions for Excel Sheet Column Number.
class Solution {
public:
	int titleToNumber(string s) {
		if(s.empty()) return 0;
		int res = 0;
		for (auto ch : s) {
			res *= 26;
			res += ch - '@';
		}
		return res;
	}
};