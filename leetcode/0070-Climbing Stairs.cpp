class Solution {
public:

	//斐波那契数列 递归或者dp
	//Runtime: 4 ms, faster than 85.73% of C++ online submissions for Climbing Stairs.
	//Memory Usage : 8.3 MB, less than 65.82 % of C++ online submissions for Climbing Stairs.
	int climbStairs(int n) {
		if (n < 3) {
			return n;
		}
		int first = 1;
		int second = 2;
		for (int i = 3; i <= n; i++) {
			int tmp = second;
			second = first + second;
			first = tmp;
		}
		return second;
	}
};