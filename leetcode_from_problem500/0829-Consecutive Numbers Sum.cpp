class Solution {
public:
	int consecutiveNumbersSum(int N) {
		int count = 0;
		for (int i = 1; i <= N; i++) {
			int up = 2 * N + i - i * i;
			if (up <= 0) break;
			int down = 2 * i;
			if (up % down == 0) {
				++count;
			}
		}
		return count;
	}
};