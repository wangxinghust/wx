#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// 单调栈
// Runtime: 188 ms, faster than 90.70% of C++ online submissions for Daily Temperatures.
// Memory Usage : 14.8 MB, less than 100.00 % of C++ online submissions for Daily Temperatures.
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int> st;
		vector<int> day(T.size());
		for (int i = T.size() - 1; i >= 0; i--) {

			while (!st.empty() && T[st.top()] <= T[i]) {
				st.pop();
			}
			if (st.empty()) {
				day[i] = 0;
				st.push(i);
			}
			else {
				day[i] = st.top() - i;
				st.push(i);
			}

		}
		return day;
	}
};

int main() {
	vector<int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };
	auto res = Solution().dailyTemperatures(T);
	for (int i : res) {
		cout << i << " ";
	}
	return 0;
}