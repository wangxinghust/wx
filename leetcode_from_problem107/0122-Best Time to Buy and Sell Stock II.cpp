#include <vector>
using namespace std;
class Solution {
public:
	// =�ı߽�һ��Ҫ�ӣ�˼·Ϊÿһ������͹ȵ���һ�����
	// Runtime: 12 ms, faster than 17.98% of C++ online submissions for Best Time to Buy and Sell Stock II.
	// Memory Usage : 9.6 MB, less than 24.13 % of C++ online submissions for Best Time to Buy and Sell Stock II.
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		int profit = 0;
		for (int i = 0; i < prices.size() - 1;) {
			if ((i == 0 && prices[i] < prices[i + 1]) || (i > 0 && prices[i] < prices[i + 1] && prices[i] <= prices[i - 1])) {
				for (int j = i + 1; j < prices.size(); j++) {
					if ((j == prices.size() - 1 && prices[j] > prices[j - 1]) || (j<prices.size() - 1 && prices[j]>prices[j - 1] && prices[j] >= prices[j + 1])) {
						profit += prices[j] - prices[i];
						i = j + 1;
						break;
					}
				}
			}
			else
				i++;
		}
		return profit;
	}
};

int main(int argc, char* argv[]) {
	vector<int> prices = { 7,1,5,3,6,4 };
	int ans = Solution().maxProfit(prices);
	return 0;
}