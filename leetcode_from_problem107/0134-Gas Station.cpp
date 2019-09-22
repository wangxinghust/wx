#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		for (int i = 0; i < n; i++) {
			int tank = gas[i];
			int step = 0;
			int j = i;
			while (step < n && tank - cost[j] >= 0) {
				tank -= cost[j];
				j = j + 1 < n ? j + 1 : 0;
				tank += gas[j];
				step++;
			}
			if (step == n) return i;
		}
		return -1;
	}
};

class Solution2 {
public:
	int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		for (int i = 0; i < n; i++) {
			gas[i] -= cost[i];
		}
		for (int i = 0; i < n; i++) {
			if (gas[i] >= 0) {
				int residue = gas[i];
				int j = 0;
				for (; j < n; j++) {
					residue += gas[(i + j + 1) % n];
					if (residue < 0) break;
				}
				if (j == n) return i;
			}
		}
		return -1;
	}
};

// leetcode by XBIX360555
// https://leetcode.com/problems/gas-station/discuss/42572/Proof-of-%22if-total-gas-is-greater-than-total-cost-there-is-a-solution%22.-C%2B%2B
// 找最小total
// 假设i点是出发点，那么i往后的各种和都是大于0的，也就是i之后的total只会比total[i]大，因此找最小total即可
class Solution3 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int total(0), subsum(INT_MAX), start(0);
		for (int i = 0; i < n; ++i) {
			total += gas[i] - cost[i];
			if (total < subsum) {
				subsum = total;
				start = i + 1;
			}

			//cout << "total=" << total << "|subsum=" << subsum << "|start=" << start << endl;
		}
		return (total < 0) ? -1 : (start % n);
	}
};

// 利用stl降低代码量
class Solution4 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		for (int i = 0; i < gas.size(); i++)
			gas[i] -= cost[i];
		partial_sum(gas.begin(), gas.end(),gas.begin());
		auto p = min_element(gas.begin(), gas.end());
		return gas[gas.size() - 1] < 0 ? -1 : (p - gas.begin() + 1) % gas.size();
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> gas = { 1,2,3,4,5 };
//	vector<int> cost = { 3,4,5,1,2 };
//	int ans = Solution3().canCompleteCircuit(gas, cost);
//	return 0;
//}