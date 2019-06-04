#include <math.h>
#include <climits>
class Solution {
public:
	double myPow(double x, int n) {
		if (n >= 0) {
			return pow(x, n);
		}
		else {
			if (n == INT_MIN) {
				double tmp = pow(1.0 / x, INT_MAX);
				return tmp / x;
			}
			else {
				return pow(1.0 / x, -n);
			}
		}
	}
};

//int main(int argc, char* argv[]) {
//	double x = 0;
//	int n = 0;
//	Solution s;
//	double ans = s.myPow(x, n);
//	return 0;
//}