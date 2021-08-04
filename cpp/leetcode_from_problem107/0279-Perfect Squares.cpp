#include <vector>
#include <algorithm>
using namespace std;

// dp
// Runtime: 72 ms, faster than 73.78% of C++ online submissions for Perfect Squares.
// Memory Usage : 11.2 MB, less than 62.89 % of C++ online submissions for Perfect Squares.
class Solution {
public:
	int numSquares(int n) {
		vector<int> step(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			int minStep = INT_MAX;
			for (int j = 1; j * j <= i; j++) {
				minStep = min(minStep, step[i - j * j]);
			}
			step[i] = minStep + 1;
		}
		return step[n];
	}
};

// leetcode by goelrishabh5: Static Dynamic Programming
// 利用静态变量，求好的值均已存储，需要预先知道所求n的最大值
class Solution2 {
public:
	int numSquares(int n) {
		static vector<int> dp(490001, 490001);
		static int max_n_so_far = 1;
		if (n < max_n_so_far)
			return dp[n];

		dp[0] = 0;
		for (int i = max_n_so_far; i <= n; i++)
			for (int j = 1; j * j <= i; j++)
				dp[i] = min(dp[i], 1 + dp[i - j * j]);

		max_n_so_far = max(n, max_n_so_far);
		return dp[n];
	}
};