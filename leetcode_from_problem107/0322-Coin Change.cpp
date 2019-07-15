#include <vector>
#include <algorithm>
using namespace std;

// dp
// Runtime: 48 ms, faster than 68.65% of C++ online submissions for Coin Change.
// Memory Usage : 12.4 MB, less than 78.39 % of C++ online submissions for Coin Change.
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());
		// 不用INT_MAX 避免溢出
		vector<int> combination(amount + 1, amount + 1);
		// 组成0元需要0个硬币
		combination[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (coins[j] > i) {
					break;
				}
				else {
					combination[i] = min(combination[i], combination[i - coins[j]] + 1);
				}
			}
		}
		return combination[amount] == amount + 1 ? -1 : combination[amount];
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> coins = { 1,2,5 };
//	int ret = Solution().coinChange(coins, 11);
//	return 0;
//}