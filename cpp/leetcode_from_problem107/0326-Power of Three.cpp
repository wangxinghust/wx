#include <string>
#include <stdlib.h>
#include <regex>
using namespace std;

// Runtime: 24 ms, faster than 45.99% of C++ online submissions for Power of Three.
// Memory Usage : 7.9 MB, less than 87.27 % of C++ online submissions for Power of Three.
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n == 1) return true;
		while (n > 3 && n % 3 == 0)
			n /= 3;
		return n == 3;
	}
};

// Approach 2: Base Conversion
//class Solution2 {
//public:
//	bool isPowerOfThree(int n) {
//		char baseChange[20];
//		// itoa: Convert integer to string (non-standard function)
//		itoa(n, baseChange, 3);
//		return regex_match(baseChange, regex("^10*$"));
//	}
//};

// Approach 3: Mathematics
class Solution3 {
	bool isInt(double x) {
		int y = (int)x;
		double z = y;
		if (z == x)	return true;
		else return false;
	}
public:
	bool isPowerOfThree(int n) {
		return isInt((log10(n) / log10(3)));
	}
};

// Approach 4: Integer Limitations
// 3是素数，找到3的幂次的最大数，则它只能被3^0,3^1,3^2...整除
constexpr int MaxPowerOfThree() {
	int n = 3;
	while (n < std::numeric_limits<int>::max() / 3) {
		n = n * 3;
	}
	return n;
}
class Solution4 {
public:
	bool isPowerOfThree(int n) {
		constexpr int maxPowerOfThree = MaxPowerOfThree();
		return n > 0 && maxPowerOfThree % n == 0;
	}
};