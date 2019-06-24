#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	// Runtime: 8 ms, faster than 85.00% of C++ online submissions for Best Time to Buy and Sell Stock.
	// Memory Usage : 9.6 MB, less than 13.20 % of C++ online submissions for Best Time to Buy and Sell Stock.
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1) return 0;
		vector<int> left(n);
		left[0] = prices[0];
		for (int i = 1; i < n; i++) {
			left[i] = min(left[i - 1], prices[i]);
		}
		left[n - 1] = prices[n - 1] - left[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			left[i] = max(left[i + 1], prices[i] - left[i]);
		}
		return left[0];
	}

	// leetcode Approach 1: Brute Force

	// leetcode Approach 2: One Pass
	// minPrice 在遍历中变化，同时不断求maxProfit
	// Runtime: 8 ms, faster than 85.00% of C++ online submissions for Best Time to Buy and Sell Stock.
	// Memory Usage : 9.4 MB, less than 75.00 % of C++ online submissions for Best Time to Buy and Sell Stock.
	int maxProfit2(vector<int>& prices) {
		int minPrice = INT_MAX;
		int maxProfit = 0;
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < minPrice) {
				minPrice = prices[i];
			}
			else if (prices[i] - minPrice > maxProfit) {
				maxProfit = prices[i] - minPrice;
			}
		}
		return maxProfit;
	}
};

//int main(int argc, char* argv[]) {
//	//vector<int> prices = { 7,6,4,3,1 };
//	//vector<int> prices = { 7,1,5,3,6,4 };
//	vector<int> prices = { 1,2 };
//	int ans = Solution().maxProfit(prices);
//	return 0;
//}