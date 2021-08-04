#include <climits>
class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;
		while (n >= 5) {
			n /= 5;
			res += n;
		}
		return res;
	}
};

//int main(int argc, char* argv[]) {
//	int res = Solution().trailingZeroes(INT_MAX);
//	return 0;
//}