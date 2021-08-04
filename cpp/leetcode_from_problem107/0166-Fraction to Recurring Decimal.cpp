#include <string>
#include <unordered_map>
using namespace std;

// leetcode by mzchen
// 通过unorder_map来记录循环过程里重复出现的数字
// Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Fraction to Recurring Decimal.
// Memory Usage : 8.8 MB, less than 69.21 % of C++ online submissions for Fraction to Recurring Decimal.
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";

		long long n = numerator;
		long long d = denominator;
		string res = "";

		// determine the sign
		if ((n < 0) ^ (d < 0)) res += '-';
		n = abs(n);
		d = abs(d);

		// 计算整数部分
		res += to_string(n / d);
		n %= d;
		if (n == 0) return res;

		res += '.';

		unordered_map<int, int> map;

		// simulate the division process
		for (long long r = n % d; r; r = r % d) {
			// meet a known remainder
			// so we reach the end of the repeating part
			if (map.count(r) > 0) {
				res.insert(map[r], 1, '(');
				res += ')';
				break;
			}

			// the remainder is first seen
			// remember the current position for it
			map[r] = res.size();
			r *= 10;

			// append the quotion digit
			res += to_string(r / d);
		}

		return res;
	}
};

//int main(int argc, char* argv[]) {
//	string res = Solution().fractionToDecimal(131, 999);
//	return 0;
//}