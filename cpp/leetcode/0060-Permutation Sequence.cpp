#include <string>
#include <vector>
using namespace std;

class Solution {
public:

	//通过找规律直接求解
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutation Sequence.
	//Memory Usage : 8.3 MB, less than 65.47 % of C++ online submissions for Permutation Sequence.

	//存1-9的阶乘数值
	int factorial[9] = { 1,2,6,24,120,720,5040,40320,362880 };

	string getPermutation(int n, int k) {
		vector<char> num(n);
		for (int i = 0; i < n; i++) {
			num[i] = '0' + i + 1;
		}
		string ans;
		int j = n - 2;
		k--;//数据里从0开始，而题目里从1开始，大概是这个造成了多算了一步的缘故，自减1即可
		while (k >= 0 && j >= 0) {
			int m = k / factorial[j];
			ans += num[m];
			num.erase(num.begin() + m);

			k %= factorial[j];
			j--;
		}
		ans += num[0];
		return ans;
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	string ans = s.getPermutation(4, 9);
//	return 0;
//}