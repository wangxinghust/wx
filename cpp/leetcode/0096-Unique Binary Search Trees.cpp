#include <vector>
using namespace std;
class Solution {
public:
	// catalan numbers
	// but signed integer overflow
	int numTrees(int n) {
		if (n == 0) return 0;
		long long denominator = 1;
		for (int i = 2; i <= n; i++) {
			denominator *= i;
		}
		long long numerator = 1;
		for (int i = n + 2; i <= 2 * n; i++) {
			numerator *= i;
		}
		return numerator / denominator;
	}

	//leetcode by liaison
	int numTrees2(int n) {
		vector<int> G(n + 1);
		G[0] = G[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; ++j) {
				G[i] += G[j - 1] * G[i - j];
			}
		}
		return G[n];
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> test = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
//	vector<int> ans;
//	for (auto i : test) {
//		ans.push_back(Solution().numTrees2(i));
//	}
//	return 0;
//}