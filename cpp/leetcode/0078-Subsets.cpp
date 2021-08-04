#include <vector>
using namespace std;
class Solution {
public:
	//Runtime: 8 ms, faster than 86.36% of C++ online submissions for Subsets.
	//Memory Usage : 10.6 MB, less than 20.40 % of C++ online submissions for Subsets.
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		for (int i = 0; i <= nums.size(); i++) {
			vector<vector<int>> add = combineNum(nums, nums.size(), i);
			ans.insert(ans.end(), add.begin(), add.end());
		}
		ans.push_back({});
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
//	vector<int> nums = { 1,2,3 };
//	vector<vector<int>> ans = s.subsets(nums);
//	return 0;
//}