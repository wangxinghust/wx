#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

// ˼·������һ�εģ��ڶ��α�����ʱ��ȥ�ӵ�һ�εļ���
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		// �߽��޶�
		if (size < 2) return 0;

		// ��ʾi��֮��һ�β�����׬�������ֵ
		vector<int> oneTransaction(size, 0);
		// �ݴ��һ�ν��׵����ֵ
		int maxPrice = prices[size - 1];
		int maxOneTransaction = 0;
		for (int i = size - 2; i >= 0; i--) {
			if (maxPrice > prices[i]) {
				// ����oneTransactionֵ��Ĭ��Ϊ0
				oneTransaction[i] = max(oneTransaction[i+1], maxPrice - prices[i]);
			}
			else {
				oneTransaction[i] = oneTransaction[i + 1];
				// ����maxPriceֵ
				maxPrice = prices[i];
			}
			// ����maxOneTransactionֵ
			maxOneTransaction = max(maxOneTransaction, oneTransaction[i]);
		}
		int left = 0;
		int maxTwoTransaction = 0;
		// �໬������
		while (left <= size - 4) {
			int right = left + 1;
			while (right <= size - 3) {
				if (prices[right] > prices[left]) {
					maxTwoTransaction = max(maxTwoTransaction, prices[right] - prices[left] + oneTransaction[right + 1]);
				}
				++right;
			}
			++left;
		}
		return max(maxOneTransaction, maxTwoTransaction);
	}
};

// LeetCode by weijiac
// ˼·��ά��4������������ LeetCode 137 Single Number II
class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		int hold1 = INT_MIN, hold2 = INT_MIN;
		int release1 = 0, release2 = 0;
		for (int i : prices) {
			release2 = max(release2, hold2 + i);	// The maximum if we've just sold 2nd stock so far.
			hold2 = max(hold2, release1 - i);		// The maximum if we've just buy  2nd stock so far.
			release1 = max(release1, hold1 + i);	// The maximum if we've just sold 1nd stock so far.
			hold1 = max(hold1, -i);					// The maximum if we've just buy  1st stock so far. release2 = max(release2, hold2 + i);
			//cout <<setw(5)<< hold1 << setw(5) << release1 << setw(5) << hold2 << setw(5) << release2 << endl;
		}
		return release2;
	}
};

//int main() {
//	vector<int> prices = { 3,2,6,5,0,3 };
//	vector<int> prices2 = { 2,1,2,1,0,1,2 };
//	int ret = Solution2().maxProfit(prices2);
//	return 0;
//}