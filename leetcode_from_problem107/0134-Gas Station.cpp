#include <vector>
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
// ÕÒ×îÐ¡total
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
		}
		return (total < 0) ? -1 : (start % n);
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> gas = { 1,2,3,4,5 };
//	vector<int> cost = { 3,4,5,1,2 };
//	int ans = Solution().canCompleteCircuit(gas, cost);
//	return 0;
//}