#include <vector>
using namespace std;
class Solution {
public:
	//Runtime: 104 ms, faster than 30.09% of C++ online submissions for Combinations.
	//Memory Usage : 31.6 MB, less than 21.39 % of C++ online submissions for Combinations.
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		if (n <= 0) return ans;
		vector<int> nums(n);
		for (int i = 0; i < n; i++) {
			nums[i] = i + 1;
		}
		ans = combineNum(nums, n, k);
		return ans;
	}

	vector<vector<int>> combineNum(vector<int>& nums, int n, int k) {
		vector<vector<int>> ans;
		if (k <= 0 || n < k) {
			return ans;
		}
		if (n == k) {
			ans.push_back(nums);
			return ans;
		}
		if (k == 1) {
			for (int i : nums) {
				ans.push_back({ i });
			}
		}
		else {
			for (int i = 0; i <= n - k; i++) {
				vector<vector<int>> add;

				vector<int> tmp(nums.begin() + i + 1, nums.end());
				add = combineNum(tmp, tmp.size(), k - 1);

				for (int j = 0; j < add.size(); j++) {
					add[j].insert(add[j].begin(), nums[i]);
				}
				//基于范围的for循环是只读的遍历，除非将变量的类型声明为引用类型 比如 auto &j : add
				/*for (auto j : add) {
					j.insert(j.begin(), nums[i]);
				}*/

				ans.insert(ans.end(), add.begin(), add.end());
			}
		}
		return ans;
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	vector<vector<int>> ans = s.combine(5, 3);
//	return 0;
//}